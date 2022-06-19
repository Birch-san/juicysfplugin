#!/usr/bin/env bash
cd JUCE

MAKE_CORES="$(($(grep -c ^processor /proc/cpuinfo)+1))"
export CMAKE_BUILD_PARALLEL_LEVEL="$MAKE_CORES"
cmake -B build -DCMAKE_INSTALL_PREFIX="/linux_native"
cmake --build build --target install -- -j"$MAKE_CORES"
# for some reason this file I introduced to my branch of JUCE isn't included
# by JUCE's install. we can move it ourselves.
cp -R /JUCE/extras/Build/CMake/Modules/ /linux_native/lib/cmake/JUCE-*/