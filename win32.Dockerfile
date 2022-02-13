# docker build . -f win32.Dockerfile --tag=llvm-mingw
# docker run -it --rm --name llvm-mingw llvm-mingw
ARG UBUNTU_VER=22.04

FROM ubuntu:$UBUNTU_VER AS wgetter
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
wget ca-certificates && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM wgetter AS get_llvm_mingw
COPY win32_cross_compile/download_llvm_mingw.sh download_llvm_mingw.sh
ARG LLVM_MINGW_VER=20220209
RUN LLVM_MINGW_VER=$LLVM_MINGW_VER ./download_llvm_mingw.sh download_llvm_mingw.sh

FROM ubuntu:$UBUNTU_VER AS gitter
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
git ca-certificates && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*

FROM gitter AS get_juce
COPY win32_cross_compile/clone_juce.sh clone_juce.sh
RUN ./clone_juce.sh

FROM gitter AS get_fluidsynth
COPY win32_cross_compile/clone_fluidsynth.sh clone_fluidsynth.sh
RUN ./clone_fluidsynth.sh

FROM ubuntu:$UBUNTU_VER AS toolchain
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
xz-utils cmake build-essential pkg-config && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY --from=get_llvm_mingw llvm-mingw.tar.xz llvm-mingw.tar.xz
# here's how to merge it into existing /bin, but that could have unintended clashes
# RUN tar -xvf llvm-mingw.tar.xz --strip-components=1 -k && rm llvm-mingw.tar.xz
RUN mkdir -p /opt/llvm-mingw && tar -xvf llvm-mingw.tar.xz --strip-components=1 -C /opt/llvm-mingw && rm llvm-mingw.tar.xz
ENV PATH="/opt/llvm-mingw/bin:$PATH"
COPY win32_cross_compile/x86_64_toolchain.cmake /x86_64_toolchain.cmake
COPY win32_cross_compile/i686_toolchain.cmake /i686_toolchain.cmake
COPY win32_cross_compile/aarch64_toolchain.cmake /aarch64_toolchain.cmake

FROM ubuntu:$UBUNTU_VER AS make_juce
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
cmake build-essential pkg-config libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libfreetype6-dev && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY --from=get_juce JUCE JUCE
COPY win32_cross_compile/make_juce.sh make_juce.sh
RUN ./make_juce.sh

FROM wgetter AS msys2_deps
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
zstd && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY win32_cross_compile/get_fluidsynth_deps.sh get_fluidsynth_deps.sh
RUN ./get_fluidsynth_deps.sh

FROM toolchain AS make_fluidsynth_x86
COPY --from=msys2_deps clang32 clang32
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY win32_cross_compile/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x86
COPY win32_cross_compile/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x86

FROM toolchain AS make_fluidsynth_x64
COPY --from=msys2_deps clang64 clang64
COPY --from=get_fluidsynth fluidsynth fluidsynth
COPY win32_cross_compile/configure_fluidsynth.sh configure_fluidsynth.sh
RUN ./configure_fluidsynth.sh x64
COPY win32_cross_compile/build_fluidsynth.sh build_fluidsynth.sh
RUN ./build_fluidsynth.sh x64

FROM toolchain AS juicysfplugin_common
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends \
libfreetype6-dev && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY --from=make_juce /linux_native/ /linux_native/
COPY --from=msys2_deps /clang32/ /clang32/
COPY --from=msys2_deps /clang64/ /clang64/
COPY --from=make_fluidsynth_x64 /clang64/include/fluidsynth.h /clang64/include/fluidsynth.h
COPY --from=make_fluidsynth_x64 /clang64/include/fluidsynth/ /clang64/include/fluidsynth/
COPY --from=make_fluidsynth_x64 /clang64/lib/pkgconfig/fluidsynth.pc /clang64/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_x64 /clang64/lib/libfluidsynth.a /clang64/lib/libfluidsynth.a
COPY --from=make_fluidsynth_x86 /clang32/include/fluidsynth.h /clang32/include/fluidsynth.h
COPY --from=make_fluidsynth_x86 /clang32/include/fluidsynth/ /clang32/include/fluidsynth/
COPY --from=make_fluidsynth_x86 /clang32/lib/pkgconfig/fluidsynth.pc /clang32/lib/pkgconfig/fluidsynth.pc
COPY --from=make_fluidsynth_x86 /clang32/lib/libfluidsynth.a /clang32/lib/libfluidsynth.a
COPY win32_cross_compile/fix_mingw_headers.sh fix_mingw_headers.sh
RUN ./fix_mingw_headers.sh
COPY win32_cross_compile/attrib_noop.sh /usr/local/bin/attrib
WORKDIR juicysfplugin
COPY VST2_SDK/ /VST2_SDK/
COPY resources/Logo512.png resources/Logo512.png
COPY cmake/Modules/FindPkgConfig.cmake cmake/Modules/FindPkgConfig.cmake
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h
COPY CMakeLists.txt CMakeLists.txt
COPY win32_cross_compile/configure_juicysfplugin.sh configure_juicysfplugin.sh

FROM juicysfplugin_common AS juicysfplugin_x86
RUN /juicysfplugin/configure_juicysfplugin.sh x86
COPY win32_cross_compile/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh x86

FROM juicysfplugin_common AS juicysfplugin_x64
RUN /juicysfplugin/configure_juicysfplugin.sh x64
COPY win32_cross_compile/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /juicysfplugin/make_juicysfplugin.sh x64

FROM ubuntu:$UBUNTU_VER AS distribute
# x86 build fails in JUCE 6.1.5; problem compiling UUIDGetter
# https://gist.github.com/Birch-san/a36b10155e51bd814ecc7109501e1e64
# COPY --from=juicysfplugin_x86 /juicysfplugin/build_x86/JuicySFPlugin_artefacts/ /x86/
COPY --from=juicysfplugin_x64 /juicysfplugin/build_x64/JuicySFPlugin_artefacts/ /x64/