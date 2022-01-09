#!/usr/bin/env bash

# declare -a ARCHS=("x64" "x86" "arm64")
declare -a ARCHS=("x64" "x86")
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  BUILD="build_$ARCH"
  cmake --build "$BUILD" --target JuicySFPlugin_Standalone
done