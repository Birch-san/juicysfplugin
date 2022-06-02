# docker build . --tag=juicy-llvm
# docker build . --tag=juicy-llvm --target=juicysfplugin_win32_x64
# docker run -it --rm --name juicy-llvm juicy-llvm
ARG UBUNTU_VER=22.10

FROM ubuntu:$UBUNTU_VER AS toolchain-common
# xz-utils - for extracting llvm-mingw releases
# lib* - for compiling JUCE
# zstd - for extracting MSYS2 packages
RUN apt-get update -qq && \
DEBIAN_FRONTEND=noninteractive apt-get install -qqy --no-install-recommends \
wget ca-certificates \
git xz-utils \
cmake build-essential pkg-config \
libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libfreetype6-dev \
zstd \
&& \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM toolchain-common AS llvm_mingw
COPY llvm-scripts/download_llvm_mingw.sh download_llvm_mingw.sh
ARG LLVM_MINGW_VER=20220323
RUN LLVM_MINGW_VER=$LLVM_MINGW_VER ./download_llvm_mingw.sh download_llvm_mingw.sh
# here's how to merge it into existing /bin, but that could have unintended clashes
# RUN tar -xvf llvm-mingw.tar.xz --strip-components=1 -k && rm llvm-mingw.tar.xz
RUN mkdir -p /opt/llvm-mingw && tar -xvf llvm-mingw.tar.xz --strip-components=1 -C /opt/llvm-mingw && rm llvm-mingw.tar.xz
ENV PATH="/opt/llvm-mingw/bin:$PATH"

FROM llvm_mingw AS linux_xcompile
COPY llvm-scripts/multi-arch-apt.sh multi-arch-apt.sh
RUN ./multi-arch-apt.sh
COPY llvm-scripts/get_fluidsynth_deps_linux.sh get_fluidsynth_deps_linux.sh

FROM linux_xcompile AS linux_deps_aarch64
RUN ./get_fluidsynth_deps_linux.sh arm64
COPY llvm-scripts/linux_arm64_toolchain.cmake /linux_arm64_toolchain.cmake

FROM linux_xcompile AS linux_deps_x86_64
RUN ./get_fluidsynth_deps_linux.sh amd64
COPY llvm-scripts/linux_amd64_toolchain.cmake /linux_amd64_toolchain.cmake

FROM linux_xcompile AS linux_deps_i386
RUN ./get_fluidsynth_deps_linux.sh i386
COPY llvm-scripts/linux_i386_toolchain.cmake /linux_i386_toolchain.cmake

FROM toolchain-common AS get_juce
COPY llvm-scripts/clone_juce.sh clone_juce.sh
RUN ./clone_juce.sh

FROM toolchain-common AS get_fluidsynth
COPY llvm-scripts/clone_fluidsynth.sh clone_fluidsynth.sh
RUN ./clone_fluidsynth.sh

FROM toolchain-common AS make_juce
COPY --from=get_juce JUCE JUCE
COPY llvm-scripts/make_juce.sh make_juce.sh
RUN ./make_juce.sh

FROM toolchain-common AS msys2_deps
COPY llvm-scripts/get_fluidsynth_deps_win32.sh get_fluidsynth_deps_win32.sh

FROM msys2_deps AS msys2_deps_x64
RUN ./get_fluidsynth_deps_win32.sh x64

FROM msys2_deps AS msys2_deps_x86
RUN ./get_fluidsynth_deps_win32.sh x86

FROM msys2_deps AS msys2_deps_aarch64
RUN ./get_fluidsynth_deps_win32.sh arm64

FROM llvm_mingw AS make_fluidsynth_win32_x64
COPY --from=msys2_deps_x64 clang64 clang64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/win32_x86_64_toolchain.cmake /win32_x86_64_toolchain.cmake
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh win32 x64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh win32 x64

FROM llvm_mingw AS make_fluidsynth_win32_x86
COPY --from=msys2_deps_x86 clang32 clang32
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/win32_i686_toolchain.cmake /win32_i686_toolchain.cmake
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh win32 x86
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh win32 x86

FROM llvm_mingw AS make_fluidsynth_win32_aarch64
COPY --from=msys2_deps_aarch64 clangarm64 clangarm64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/win32_aarch64_toolchain.cmake /win32_aarch64_toolchain.cmake
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh win32 arm64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh win32 arm64

FROM linux_deps_x86_64 AS make_fluidsynth_linux_x86_64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh linux x64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh linux x64

FROM linux_deps_i386 AS make_fluidsynth_linux_i386
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh linux x86
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh linux x86

FROM linux_deps_aarch64 AS make_fluidsynth_linux_aarch64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh linux arm64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh linux arm64

FROM llvm_mingw AS juicysfplugin_common
COPY --from=make_juce /linux_native/ /linux_native/
WORKDIR juicysfplugin
COPY resources/Logo512.png resources/Logo512.png
COPY VST2_SDK/ /VST2_SDK/
COPY llvm-scripts/configure_juicysfplugin.sh configure_juicysfplugin.sh
COPY cmake/Modules/FindPkgConfig.cmake cmake/Modules/FindPkgConfig.cmake
COPY CMakeLists.txt CMakeLists.txt
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h

FROM juicysfplugin_common AS juicysfplugin_common_win32
COPY llvm-scripts/fix_mingw_headers.sh fix_mingw_headers.sh
RUN ./fix_mingw_headers.sh
COPY llvm-scripts/attrib_noop.sh /usr/local/bin/attrib

FROM juicysfplugin_common_win32 AS juicysfplugin_win32_x64
COPY --from=msys2_deps_x64 /clang64/ /clang64/
COPY --from=make_fluidsynth_win32_x64 /clang64/include/fluidsynth.h /clang64/include/fluidsynth.h
COPY --from=make_fluidsynth_win32_x64 /clang64/include/fluidsynth/ /clang64/include/fluidsynth/
COPY --from=make_fluidsynth_win32_x64 /clang64/lib/pkgconfig/fluidsynth.pc /clang64/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_win32_x64 /clang64/lib/libfluidsynth.a /clang64/lib/libfluidsynth.a
RUN /juicysfplugin/configure_juicysfplugin.sh win32 x64
COPY llvm-scripts/win32_x86_64_toolchain.cmake /win32_x86_64_toolchain.cmake
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh win32 x64

FROM juicysfplugin_common_win32 AS juicysfplugin_win32_x86
COPY --from=msys2_deps_x86 /clang32/ /clang32/
COPY --from=make_fluidsynth_win32_x86 /clang32/include/fluidsynth.h /clang32/include/fluidsynth.h
COPY --from=make_fluidsynth_win32_x86 /clang32/include/fluidsynth/ /clang32/include/fluidsynth/
COPY --from=make_fluidsynth_win32_x86 /clang32/lib/pkgconfig/fluidsynth.pc /clang32/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_win32_x86 /clang32/lib/libfluidsynth.a /clang32/lib/libfluidsynth.a
COPY llvm-scripts/win32_i686_toolchain.cmake /win32_i686_toolchain.cmake
RUN /juicysfplugin/configure_juicysfplugin.sh win32 x86
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh win32 x86

FROM juicysfplugin_common_win32 AS juicysfplugin_win32_aarch64
COPY --from=msys2_deps_aarch64 /clangarm64/ /clangarm64/
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/include/fluidsynth.h /clangarm64/include/fluidsynth.h
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/include/fluidsynth/ /clangarm64/include/fluidsynth/
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/lib/pkgconfig/fluidsynth.pc /clangarm64/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/lib/libfluidsynth.a /clangarm64/lib/libfluidsynth.a
COPY llvm-scripts/win32_aarch64_toolchain.cmake /win32_aarch64_toolchain.cmake
RUN /juicysfplugin/configure_juicysfplugin.sh win32 arm64
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh win32 arm64

FROM juicysfplugin_common AS juicysfplugin_linux_x86_64
COPY --from=linux_deps_x86_64 /usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu
COPY --from=make_fluidsynth_linux_x86_64 /usr/include/fluidsynth.h /usr/include/fluidsynth.h
COPY --from=make_fluidsynth_linux_x86_64 /usr/include/fluidsynth/ /usr/include/fluidsynth/
COPY --from=make_fluidsynth_linux_x86_64 /usr/lib/x86_64-linux-gnu/pkgconfig/fluidsynth.pc /usr/lib/x86_64-linux-gnu/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_linux_x86_64 /usr/lib/x86_64-linux-gnu/libfluidsynth.a /usr/lib/x86_64-linux-gnu/libfluidsynth.a
COPY llvm-scripts/linux_amd64_toolchain.cmake /linux_amd64_toolchain.cmake
RUN /juicysfplugin/configure_juicysfplugin.sh linux x64
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh linux x64

FROM juicysfplugin_common AS juicysfplugin_linux_i386
COPY --from=linux_deps_i386 /usr/lib/i386-linux-gnu /usr/lib/i386-linux-gnu
COPY --from=make_fluidsynth_linux_i386 /usr/include/fluidsynth.h /usr/include/fluidsynth.h
COPY --from=make_fluidsynth_linux_i386 /usr/include/fluidsynth/ /usr/include/fluidsynth/
COPY --from=make_fluidsynth_linux_i386 /usr/lib/i386-linux-gnu/pkgconfig/fluidsynth.pc /usr/lib/i386-linux-gnu/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_linux_i386 /usr/lib/i386-linux-gnu/libfluidsynth.a /usr/lib/i386-linux-gnu/libfluidsynth.a
COPY llvm-scripts/linux_i386_toolchain.cmake /linux_i386_toolchain.cmake
RUN /juicysfplugin/configure_juicysfplugin.sh linux x86
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh linux x86

FROM juicysfplugin_common AS juicysfplugin_linux_aarch64
COPY --from=linux_deps_aarch64 /usr/lib/aarch64-linux-gnu /usr/lib/aarch64-linux-gnu
COPY --from=make_fluidsynth_linux_aarch64 /usr/include/fluidsynth.h /usr/include/fluidsynth.h
COPY --from=make_fluidsynth_linux_aarch64 /usr/include/fluidsynth/ /usr/include/fluidsynth/
COPY --from=make_fluidsynth_linux_aarch64 /usr/lib/aarch64-linux-gnu/pkgconfig/fluidsynth.pc /usr/lib/aarch64-linux-gnu/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_linux_aarch64 /usr/lib/aarch64-linux-gnu/libfluidsynth.a /usr/lib/aarch64-linux-gnu/libfluidsynth.a
COPY llvm-scripts/linux_arm64_toolchain.cmake /linux_arm64_toolchain.cmake
RUN /juicysfplugin/configure_juicysfplugin.sh linux arm64
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh linux arm64

FROM ubuntu:$UBUNTU_VER AS distribute
COPY --from=juicysfplugin_linux_x86_64 /juicysfplugin/build_linux_x64/JuicySFPlugin_artefacts/ /linux_x64/
COPY --from=juicysfplugin_linux_i386 /juicysfplugin/build_linux_x86/JuicySFPlugin_artefacts/ /linux_x86/
COPY --from=juicysfplugin_linux_aarch64 /juicysfplugin/build_linux_arm64/JuicySFPlugin_artefacts/ /linux_arm64/
COPY --from=juicysfplugin_win32_x64 /juicysfplugin/build_win32_x64/JuicySFPlugin_artefacts/ /win32_x64/
COPY --from=juicysfplugin_win32_x86 /juicysfplugin/build_win32_x86/JuicySFPlugin_artefacts/ /win32_x86/
COPY --from=juicysfplugin_win32_aarch64 /juicysfplugin/build_win32_arm64/JuicySFPlugin_artefacts/ /win32_arm64/