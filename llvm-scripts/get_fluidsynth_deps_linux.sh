#!/usr/bin/env bash
set -eo pipefail

if test -n "$1"; then
  ARCH="$1"
else
  >&2 echo "specify an architecture via arg0"
  exit 1
fi

CROSS_COMPILE_SYSROOT_DEPS=()
if [ "$(dpkg --print-architecture)" != "$ARCH" ]; then
  CROSS_COMPILE_SYSROOT_DEPS+=(
    "libc6-$ARCH-cross"
    "libgcc-12-dev-$ARCH-cross"
    "libstdc++-12-dev-$ARCH-cross"
  )
fi

echo "CROSS_COMPILE_SYSROOT_DEPS:
${CROSS_COMPILE_SYSROOT_DEPS[*]}"

# "libasound2-dev:$ARCH" was no use (no static distribution included).
# "libjack-jackd2-dev:$ARCH" was no use (no static distribution included).
# libbrotli line is for dependencies of libfreetype (we had to compile our own to get -fPIC)
# "libsndfile1-dev:$ARCH" was not compiled with -fPIC for x86_64 (though it worked fine on aarch64)
# libflac line is for dependencies of sndfile
apt-get update -qq && apt-get upgrade -y && \
DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
"libglib2.0-dev:$ARCH" \
"libx11-dev:$ARCH" "libxrandr-dev:$ARCH" "libxinerama-dev:$ARCH" "libxcursor-dev:$ARCH" \
"libbrotli-dev:$ARCH" "libc6-dev:$ARCH" "libpng-dev:$ARCH" "zlib1g-dev:$ARCH" \
"libflac-dev:$ARCH" "libopus-dev:$ARCH" "libvorbis-dev:$ARCH" python3 \
rename gawk \
"${CROSS_COMPILE_SYSROOT_DEPS[@]}"
apt-get clean -y
rm -rf /var/lib/apt/lists/*
ln -sf /usr/bin/python3 /usr/bin/python