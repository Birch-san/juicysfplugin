# docker build . --tag=juicy-llvm
# docker run -it --rm --name juicy-llvm juicy-llvm
ARG UBUNTU_VER=22.10

FROM ubuntu:$UBUNTU_VER AS toolchain-common
# xz-utils - for extracting llvm-mingw releases
# lib* - for compiling JUCE
# zstd - for extracting MSYS2 packages
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
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

FROM toolchain-common AS get_juce
COPY llvm-scripts/clone_juce.sh clone_juce.sh
RUN ./clone_juce.sh

FROM toolchain-common AS get_fluidsynth
COPY llvm-scripts/clone_fluidsynth.sh clone_fluidsynth.sh
RUN ./clone_fluidsynth.sh

FROM toolchain-common AS toolchain-win32
COPY --from=llvm_mingw llvm-mingw.tar.xz llvm-mingw.tar.xz
# here's how to merge it into existing /bin, but that could have unintended clashes
# RUN tar -xvf llvm-mingw.tar.xz --strip-components=1 -k && rm llvm-mingw.tar.xz
RUN mkdir -p /opt/llvm-mingw && tar -xvf llvm-mingw.tar.xz --strip-components=1 -C /opt/llvm-mingw && rm llvm-mingw.tar.xz
ENV PATH="/opt/llvm-mingw/bin:$PATH"
COPY llvm-scripts/x86_64_toolchain.cmake /x86_64_toolchain.cmake
COPY llvm-scripts/i686_toolchain.cmake /i686_toolchain.cmake
COPY llvm-scripts/aarch64_toolchain.cmake /aarch64_toolchain.cmake

FROM toolchain-common AS make_juce
COPY --from=get_juce JUCE JUCE
COPY llvm-scripts/make_juce.sh make_juce.sh
RUN ./make_juce.sh

FROM toolchain-common AS msys2_deps
COPY llvm-scripts/get_fluidsynth_deps.sh get_fluidsynth_deps.sh

FROM msys2_deps AS msys2_deps_x64
RUN ./get_fluidsynth_deps.sh x64

FROM msys2_deps AS msys2_deps_x86
RUN ./get_fluidsynth_deps.sh x86

FROM msys2_deps AS msys2_deps_aarch64
RUN ./get_fluidsynth_deps.sh arm64

FROM toolchain-win32 AS make_fluidsynth_win32_x86
COPY --from=msys2_deps_x86 clang32 clang32
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x86
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x86

FROM toolchain-win32 AS make_fluidsynth_win32_x64
COPY --from=msys2_deps_x64 clang64 clang64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x64

FROM toolchain-win32 AS make_fluidsynth_win32_aarch64
COPY --from=msys2_deps_aarch64 clangarm64 clangarm64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY llvm-scripts/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh arm64
COPY llvm-scripts/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh arm64

FROM toolchain-win32 AS juicysfplugin_common
COPY --from=make_juce /linux_native/ /linux_native/
WORKDIR juicysfplugin
COPY resources/Logo512.png resources/Logo512.png
COPY VST2_SDK/ /VST2_SDK/
COPY llvm-scripts/configure_juicysfplugin.sh configure_juicysfplugin.sh
COPY cmake/Modules/FindPkgConfig.cmake cmake/Modules/FindPkgConfig.cmake
# ensure that empty Source directory exists before cmake references it via
# add_subdirectory().
# delay the actual `COPY Source` to the last moment, for fast incremental build
RUN mkdir -p Source/
COPY CMakeLists.txt CMakeLists.txt

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
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h
RUN /juicysfplugin/configure_juicysfplugin.sh x64
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh x64

FROM juicysfplugin_common_win32 AS juicysfplugin_win32_x86
COPY --from=msys2_deps_x86 /clang32/ /clang32/
COPY --from=make_fluidsynth_win32_x86 /clang32/include/fluidsynth.h /clang32/include/fluidsynth.h
COPY --from=make_fluidsynth_win32_x86 /clang32/include/fluidsynth/ /clang32/include/fluidsynth/
COPY --from=make_fluidsynth_win32_x86 /clang32/lib/pkgconfig/fluidsynth.pc /clang32/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_win32_x86 /clang32/lib/libfluidsynth.a /clang32/lib/libfluidsynth.a
RUN /juicysfplugin/configure_juicysfplugin.sh x86
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh x86

FROM juicysfplugin_common_win32 AS juicysfplugin_win32_aarch64
COPY --from=msys2_deps_aarch64 /clangarm64/ /clangarm64/
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/include/fluidsynth.h /clangarm64/include/fluidsynth.h
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/include/fluidsynth/ /clangarm64/include/fluidsynth/
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/lib/pkgconfig/fluidsynth.pc /clangarm64/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_win32_aarch64 /clangarm64/lib/libfluidsynth.a /clangarm64/lib/libfluidsynth.a
RUN /juicysfplugin/configure_juicysfplugin.sh arm64
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h
COPY llvm-scripts/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh arm64

FROM ubuntu:$UBUNTU_VER AS distribute
COPY --from=juicysfplugin_win32_x64 /juicysfplugin/build_x64/JuicySFPlugin_artefacts/ /x64/
COPY --from=juicysfplugin_win32_x86 /juicysfplugin/build_x86/JuicySFPlugin_artefacts/ /x86/
COPY --from=juicysfplugin_win32_aarch64 /juicysfplugin/build_arm64/JuicySFPlugin_artefacts/ /arm64/