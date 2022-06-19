#!/usr/bin/env bash
set -eo pipefail
cd alsa-lib

SRC_INSTALL_PREFIX="prefix"
SRC_INCLUDE_DIR="$SRC_INSTALL_PREFIX/include"
SRC_LIB_DIR="$SRC_INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"

make install
mv "$SRC_INCLUDE_DIR"/* "$DEST_INCLUDE_DIR/"
mv "$SRC_LIB_DIR"/liba{sound,topology}.a "$DEST_LIB_DIR/"
mv "$SRC_PKG_CONFIG_DIR"/alsa{,-topology}.pc "$DEST_PKG_CONFIG_DIR/"
ALSA_PC="$DEST_PKG_CONFIG_DIR/alsa.pc"
gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^exec_prefix$/ {
  $2="${prefix}"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$ALSA_PC"