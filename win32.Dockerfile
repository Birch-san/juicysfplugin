# docker build . -f win32.Dockerfile --tag=llvm-mingw
# docker run -it --rm --name llvm-mingw llvm-mingw
# docker cp get_fluidsynth_deps.sh llvm-mingw:/build/get_fluidsynth_deps.sh && docker exec llvm-mingw /build/get_fluidsynth_deps.sh

FROM mstorsjo/llvm-mingw
COPY win32_cross_compile/FindPkgConfig.cmake /opt/cmake/share/cmake-3.20/Modules/FindPkgConfig.cmake
RUN apt-get update -qq && \
apt-get install -qqy --no-install-recommends zstd && \
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
# RUN /build/make_juce.sh
# WORKDIR juicysfplugin
# COPY cmake/Modules/FindPkgConfig.cmake cmake/Modules/FindPkgConfig.cmake
# COPY Source/ Source/
# COPY JuceLibraryCode/ JuceLibraryCode/
# COPY CMakeLists.txt CMakeLists.txt
# COPY win32_cross_compile/init.sh init.sh
# RUN /build/init.sh