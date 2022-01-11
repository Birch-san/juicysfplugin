# DOCKER_BUILDKIT=0 docker build . -f win32.Dockerfile --tag=llvm-mingw
# docker run -it --rm --name llvm-mingw llvm-mingw
# docker cp get_fluidsynth_deps.sh llvm-mingw:/build/get_fluidsynth_deps.sh && docker exec llvm-mingw /build/get_fluidsynth_deps.sh

FROM mstorsjo/llvm-mingw
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends zstd libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libfreetype6-dev && \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*
COPY win32_cross_compile/clone_fluidsynth.sh clone_fluidsynth.sh
RUN /build/clone_fluidsynth.sh
COPY win32_cross_compile/install.sh install.sh
COPY win32_cross_compile/get_fluidsynth_deps.sh get_fluidsynth_deps.sh
RUN /build/get_fluidsynth_deps.sh
COPY win32_cross_compile/x86_64_toolchain.cmake x86_64_toolchain.cmake
COPY win32_cross_compile/i686_toolchain.cmake i686_toolchain.cmake
COPY win32_cross_compile/aarch64_toolchain.cmake aarch64_toolchain.cmake
COPY win32_cross_compile/make_minimal_fluidsynth.sh make_minimal_fluidsynth.sh
RUN /build/make_minimal_fluidsynth.sh
COPY win32_cross_compile/clone_juce.sh clone_juce.sh
RUN /build/clone_juce.sh
COPY win32_cross_compile/make_juce.sh make_juce.sh
RUN /build/make_juce.sh
WORKDIR juicysfplugin
COPY VST2_SDK/ /VST2_SDK/
COPY resources/Logo512.png resources/Logo512.png
COPY cmake/Modules/FindPkgConfig.cmake cmake/Modules/FindPkgConfig.cmake
COPY Source/ Source/
COPY JuceLibraryCode/JuceHeader.h JuceLibraryCode/JuceHeader.h
COPY CMakeLists.txt CMakeLists.txt
COPY win32_cross_compile/configure_juicysfplugin.sh configure_juicysfplugin.sh
RUN /build/juicysfplugin/configure_juicysfplugin.sh
# TODO: move this up to top layer
RUN dpkg --add-architecture i386 && \
apt-get update -qq && \
apt-get install -qqy --no-install-recommends wine-stable wine32 && \
rm -rf /var/lib/apt/lists/*
COPY win32_cross_compile/attrib.sh /usr/local/bin/attrib
COPY win32_cross_compile/make_juicysfplugin.sh make_juicysfplugin.sh
RUN /build/juicysfplugin/make_juicysfplugin.sh