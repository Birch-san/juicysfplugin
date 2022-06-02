#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

if test -n "$1"; then
  declare -a ARCHS=("$1")
else
  declare -a ARCHS=("x64" "x86" "arm64")
fi

declare -A TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  BUILD="build_$ARCH"

  cmake --build "$BUILD" --target libfluidsynth
  # manual installation; not sure how to ask it to "only install libfluidsynth".
  cp "$BUILD"/fluidsynth.pc "/$REPO/lib/pkgconfig/"
  cp "$BUILD"/src/libfluidsynth*.a "/$REPO/lib/libfluidsynth.a"
  mkdir -p /$REPO/include/fluidsynth
  cp include/fluidsynth/*.h "/$REPO/include/fluidsynth/"
  cp "$BUILD"/include/fluidsynth.h "/$REPO/include/fluidsynth.h"
  cp "$BUILD"/include/fluidsynth/*.h "/$REPO/include/fluidsynth/"
done