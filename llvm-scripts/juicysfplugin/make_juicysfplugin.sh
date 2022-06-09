#!/usr/bin/env bash

TARGET_OS="$1"
ARCH="$2"
 
echo "target OS: $TARGET_OS"
echo "arch: $ARCH"

BUILD="build_${TARGET_OS}_${ARCH}"
# TODO: build all targets
cmake --build "$BUILD" --target JuicySFPlugin_Standalone -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
cmake --build "$BUILD" --target JuicySFPlugin_VST3 -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
cmake --build "$BUILD" --target JuicySFPlugin_VST -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
# cmake --build "$BUILD"