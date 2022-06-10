#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
cd freetype
TARGET_TRIPLE="$ARCH-linux-gnu"
BUILD="build_$TARGET_TRIPLE"

declare -A linux_TOOLCHAINS=( [x86_64]=amd64 [i386]=i386 [aarch64]=arm64 )
TOOLCHAIN_ARCH="${linux_TOOLCHAINS[$ARCH]}"
TOOLCHAIN_FILE="/linux_${TOOLCHAIN_ARCH}_toolchain.cmake"
echo "toolchain file: $TOOLCHAIN_FILE"

DPKG_ARCH="${linux_TOOLCHAINS[$ARCH]}"
if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

if [ "$CROSS_COMPILING" == '1' ]; then
  CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION='-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY'
else
  CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION=''
fi
CMAKE_C_FLAGS=(-fPIC)
echo "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS[*]}"

# let's disable every codec and see whether it works anyway
cmake -B"$BUILD" \
"$CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION" \
-DBUILD_SHARED_LIBS=off \
-DFT_DISABLE_PNG=on \
-DFT_DISABLE_ZLIB=on \
-DFT_DISABLE_BZIP2=on \
-DFT_DISABLE_BROTLI=on \
-DCMAKE_C_FLAGS="${CMAKE_C_FLAGS[*]}" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE"