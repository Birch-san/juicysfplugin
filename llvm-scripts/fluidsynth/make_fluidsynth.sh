#!/usr/bin/env bash
set -eo pipefail
cd fluidsynth

BUILD="build_${TARGET_OS}_${ARCH}"
cmake --build "$BUILD" --target libfluidsynth -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
cmake --install "$BUILD" --prefix 'prefix'