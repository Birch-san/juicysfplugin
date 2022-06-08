#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
cd freetype
TARGET_TRIPLE="$ARCH-linux-gnu"
BUILD="build_$TARGET_TRIPLE"
LINKER_FLAGS="-fuse-ld=lld"

declare -A linux_TOOLCHAINS=( [x86_64]=amd64 [i386]=i386 [aarch64]=arm64 )
TOOLCHAIN_ARCH="${linux_TOOLCHAINS[$ARCH]}"
TOOLCHAIN_FILE="/linux_${TOOLCHAIN_ARCH}_toolchain.cmake"
echo "toolchain file: $TOOLCHAIN_FILE"

# let's disable every codec and see whether it works anyway
cmake -B"$BUILD" \
-DBUILD_SHARED_LIBS=off \
-DFT_DISABLE_PNG=on \
-DFT_DISABLE_ZLIB=on \
-DFT_DISABLE_BZIP2=on \
-DFT_DISABLE_BROTLI=on \
-DCMAKE_C_FLAGS=-fPIC \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_EXE_LINKER_FLAGS="$LINKER_FLAGS" \
-DCMAKE_MODULE_LINKER_FLAGS="$LINKER_FLAGS" \
-DCMAKE_SHARED_LINKER_FLAGS="$LINKER_FLAGS"