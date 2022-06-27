#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

# TODO write installer, making use of our new env vars

# manual installation; not sure how to ask it to "only install libfluidsynth".
# cp "$BUILD"/fluidsynth.pc "$PKG_CONFIG_PATH/"
# cp "$BUILD"/src/libfluidsynth*.a "$LIB_INSTALL_PATH/libfluidsynth.a"
# mkdir -p "$INCLUDE_INSTALL_PATH/fluidsynth"
# cp include/fluidsynth/*.h "$INCLUDE_INSTALL_PATH/fluidsynth/"
# cp "$BUILD"/include/fluidsynth.h "$INCLUDE_INSTALL_PATH/fluidsynth.h"
# cp "$BUILD"/include/fluidsynth/*.h "$INCLUDE_INSTALL_PATH/fluidsynth/"

# FLUIDSYNTH_PC="$PKG_CONFIG_PATH/fluidsynth.pc"
# gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
#   $2="'"$INSTALL_PREFIX"'"
# }
# $1 ~ /^libdir$/ {
#   $2="${pcfiledir}/.."
# }
# { print $0 }' OFS== "$FLUIDSYNTH_PC"