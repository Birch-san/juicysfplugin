#!/usr/bin/env bash
set -eo pipefail
cd libsndfile

BUILD="build_$TARGET_TRIPLE"
cmake --build "$BUILD" -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
cmake --install "$BUILD" --prefix 'prefix'