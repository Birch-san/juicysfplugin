#!/usr/bin/env bash

# declare -a ARCHS=("x64" "x86" "arm64")
declare -a ARCHS=("x64")
declare -A TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  TOOLCHAIN="${TOOLCHAINS[$ARCH]}"
  echo "toolchain: $TOOLCHAIN"
  TOOLCHAIN_FILE="/build/${TOOLCHAIN}_toolchain.cmake"
  echo "toolchain file: $TOOLCHAIN_FILE"

  BUILD="build_$ARCH"

  VERBOSE=1 PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" \
-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
-DCMAKE_PREFIX_PATH="/linux_native" \
-DCMAKE_INSTALL_PREFIX="/$REPO" \
-DVST2_SDK_PATH="/VST2_SDK" \
-DCMAKE_CXX_STANDARD=17 \
-DCMAKE_C_STANDARD=11 \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_BUILD_TYPE=Debug
  cmake --build "$BUILD" --target JuicySFPlugin_Standalone
done