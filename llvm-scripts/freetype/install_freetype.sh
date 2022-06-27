#!/usr/bin/env bash
set -eo pipefail
cd freetype

INSTALL_PREFIX="prefix"

SRC_INCLUDE_DIR="$INSTALL_PREFIX/include"
SRC_LIB_DIR="$INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"

set -x
ls -l "$INSTALL_PREFIX"
ls -l "$SRC_INCLUDE_DIR"
ls -l "$SRC_INCLUDE_DIR/freetype2"
# ls -l "$SRC_INCLUDE_DIR/freetype2/config"
ls -l "$SRC_LIB_DIR"
ls -l "$SRC_PKG_CONFIG_DIR"

cp -R "$SRC_INCLUDE_DIR"/* "$DEST_INCLUDE_DIR/"
# mv "$SRC_INCLUDE_DIR"/freetype2/config/* "$DEST_INCLUDE_DIR"/freetype2/config/
mv "$SRC_LIB_DIR"/libfreetype.a "$DEST_LIB_DIR/"
mv "$SRC_PKG_CONFIG_DIR"/freetype2.pc "$DEST_PKG_CONFIG_DIR/"
FREETYPE_PC="$DEST_PKG_CONFIG_DIR/freetype2.pc"
gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$FREETYPE_PC"