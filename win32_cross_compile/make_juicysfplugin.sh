#!/usr/bin/env bash

if test -n "$1"; then
  declare -a ARCHS=("$1")
else
  # declare -a ARCHS=("x64" "x86" "arm64")
  declare -a ARCHS=("x64" "x86")
fi
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  BUILD="build_$ARCH"
  # cmake --build "$BUILD" --target JuicySFPlugin_Standalone
  # cmake --build "$BUILD" --target JuicySFPlugin_VST3
  cmake --build "$BUILD"
done