#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
TARGET_TRIPLE="$ARCH-linux-gnu"

CFLAGS=(-fPIC)

declare -A DPKG_ARCHS=( [x86_64]=amd64 [i386]=i386 [aarch64]=arm64 )

DPKG_ARCH="${linux_TOOLCHAINS[$ARCH]}"
if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

DPKG_ARCH="${DPKG_ARCHS[$ARCH]}"
if [ "$CROSS_COMPILING" == '1' ]; then
  CFLAGS+=(
    "--target=$TARGET_TRIPLE"
  )
fi
echo "CFLAGS: ${CFLAGS[*]}"

cd alsa-lib
libtoolize --force --copy --automake
aclocal
autoheader
automake --foreign --copy --add-missing
autoconf
# --prefix doesn't understand multi-arch very well, so this will require some postprocessing
CC=/usr/bin/clang CFLAGS="${CFLAGS[*]}" LDFLAGS=-fuse-ld=lld ./configure --enable-static=yes --enable-shared=no --host="$TARGET_TRIPLE" --prefix=/alsa-install