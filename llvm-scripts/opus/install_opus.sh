#!/usr/bin/env bash
set -eo pipefail
cd opus

BUILD="build_$TARGET_TRIPLE"

INSTALL_PREFIX="prefix"
mkdir -p "$INSTALL_PREFIX"

cmake --install "$BUILD" --prefix "$INSTALL_PREFIX"

SRC_INCLUDE_DIR="$INSTALL_PREFIX/include"
SRC_LIB_DIR="$INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"

mv "$SRC_INCLUDE_DIR"/* "$DEST_INCLUDE_DIR/"
mv "$SRC_LIB_DIR"/libopus.a "$DEST_LIB_DIR/"
mv "$SRC_PKG_CONFIG_DIR"/opus.pc "$DEST_PKG_CONFIG_DIR/"
PC_NAME='opus'
PC_FILE="$PC_NAME.pc"
cp "$SRC_PKG_CONFIG_DIR/$PC_FILE" "$DEST_PKG_CONFIG_DIR/"
PC_ABS="$DEST_PKG_CONFIG_DIR/$PC_FILE"
gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^exec_prefix$/ {
  $2="${prefix}"
}
$1 ~ /^includedir$/ {
  $2="${prefix}/include"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$PC_ABS"