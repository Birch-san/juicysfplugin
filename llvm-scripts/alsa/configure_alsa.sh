#!/usr/bin/env bash
set -eo pipefail
if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

CFLAGS=(-fPIC)
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
CC=/usr/bin/clang CFLAGS="${CFLAGS[*]}" LDFLAGS=-fuse-ld=lld ./configure --enable-static=yes --enable-shared=no --host="$TARGET_TRIPLE" --prefix="$(realpath './prefix')"