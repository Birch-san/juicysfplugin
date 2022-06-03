#!/usr/bin/env bash
set -eo pipefail
cd alsa-lib
libtoolize --force --copy --automake
aclocal
autoheader
automake --foreign --copy --add-missing
autoconf
./configure --enable-static=yes --enable-shared=no --host="$1-linux-gnu" --prefix=/usr/lib/