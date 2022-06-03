#!/usr/bin/env bash
set -eo pipefail

if test -n "$1"; then
  ARCH="$1"
else
  >&2 echo "specify an architecture via arg0"
  exit 1
fi

# libasound2 is actually a JUCE dep, required transitively by juicysfplugin,
# not a fluidsynth dep. but there's no real downside to grabbing it whilst we're in the area;
# the juicysfplugin build stage inherits from us too.
apt-get update -qq && \
DEBIAN_FRONTEND=noninteractive apt-get install -qqy --no-install-recommends \
"libsndfile1-dev:$ARCH" "libglib2.0-dev:$ARCH" \
"libasound2-dev:$ARCH" \
&& \
apt-get clean -y && \
rm -rf /var/lib/apt/lists/*