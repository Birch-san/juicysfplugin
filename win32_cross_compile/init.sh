#!/usr/bin/env bash
cd juicysfplugin

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

  # PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" pkg-config flac --static --libs-only-l

  PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" -DCMAKE_INSTALL_PREFIX="/$REPO" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_BUILD_TYPE=Debug
  cmake --build "$BUILD" --target JuicySFPlugin_Standalone

  # cp "$BUILD"/fluidsynth.pc /$REPO/lib/pkgconfig/
  # cp "$BUILD"/src/libfluidsynth*.a /$REPO/lib/libfluidsynth.a
  # mkdir -p /$REPO/include/fluidsynth
  # cp "$BUILD"/include/fluidsynth.h /$REPO/include/fluidsynth.h
  # cp "$BUILD"/include/fluidsynth/*.h /$REPO/include/fluidsynth/
done