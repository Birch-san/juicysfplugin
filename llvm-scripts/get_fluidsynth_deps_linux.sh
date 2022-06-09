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
${CROSS_COMPILE_SYSROOT_DEPS[@]}"

# "libasound2-dev:$ARCH" was no use (no static distribution included).
# "libjack-jackd2-dev:$ARCH" was no use (no static distribution included).
apt-get update -qq && apt-get upgrade -y && \
DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
"libsndfile1-dev:$ARCH" "libglib2.0-dev:$ARCH" \
"libx11-dev:$ARCH" "libxrandr-dev:$ARCH" "libxinerama-dev:$ARCH" "libxcursor-dev:$ARCH" \
"libbrotli-dev:$ARCH" "libc6-dev:$ARCH" "libpng-dev:$ARCH" "zlib1g-dev:$ARCH" \
"${CROSS_COMPILE_SYSROOT_DEPS[@]}" \
&& \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*