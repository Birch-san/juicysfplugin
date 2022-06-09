#!/usr/bin/env bash
set -eo pipefail

if test -n "$1"; then
  ARCH="$1"
else
  >&2 echo "specify an architecture via arg0"
  exit 1
fi

# "libasound2-dev:$ARCH" was no use (no static distribution included)
# not sure why it was necessary (for cross-arch only) to specify 
# libselinux (a transitive dependency of libglib).
# this suggests that I missed something when setting up the cross-arch
# apt repositories.
# musl for anything we compile ourselves, to reduce exposure to super-new glibc
apt-get update -qq && \
DEBIAN_FRONTEND=noninteractive apt-get install -qqy --no-install-recommends \
"libsndfile1-dev:$ARCH" "libglib2.0-dev:$ARCH" "libselinux1:$ARCH" \
"musl-dev:$ARCH" \
&& \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*