#!/usr/bin/env bash
set -eo pipefail
cd libsndfile

INSTALL_PREFIX="prefix"

SRC_INCLUDE_DIR="$INSTALL_PREFIX/include"
SRC_LIB_DIR="$INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"

cp -R "$SRC_INCLUDE_DIR"/* "$DEST_INCLUDE_DIR/"
cp -R "$SRC_LIB_DIR"/* "$DEST_LIB_DIR/"
PC_NAME=sndfile
PC_FILE=$PC_NAME.pc
cp "$SRC_PKG_CONFIG_DIR/$PC_FILE" "$DEST_PKG_CONFIG_DIR/"
PC_ABS="$DEST_PKG_CONFIG_DIR/$PC_FILE"
gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$PC_ABS"