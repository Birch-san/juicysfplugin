#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
TARGET_TRIPLE="$ARCH-linux-gnu"
cd alsa-lib
libtoolize --force --copy --automake
aclocal
autoheader
automake --foreign --copy --add-missing
autoconf
# --prefix doesn't understand multi-arch very well, so this will require some postprocessing
./configure --enable-static=yes --enable-shared=no --host="$TARGET_TRIPLE" --prefix=/alsa-install