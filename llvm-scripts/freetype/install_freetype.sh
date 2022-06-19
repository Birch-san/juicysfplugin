#!/usr/bin/env bash
set -eo pipefail
cd freetype

BUILD="build_$TARGET_TRIPLE"

INSTALL_PREFIX="prefix"
mkdir -p "$INSTALL_PREFIX"

cmake --install "$BUILD" --prefix "$INSTALL_PREFIX"

SRC_INCLUDE_DIR="$INSTALL_PREFIX/include"
SRC_LIB_DIR="$INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"

cp -R include/* "$DEST_INCLUDE_DIR/"
mv "$SRC_INCLUDE_DIR"/freetype/config/* "$DEST_INCLUDE_DIR"/freetype/config/
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