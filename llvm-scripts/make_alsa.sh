#!/usr/bin/env bash
set -eo pipefail
cd alsa-lib
make -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
exec make install