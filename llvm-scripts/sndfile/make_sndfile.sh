#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
TARGET_TRIPLE="$ARCH-linux-gnu"
BUILD="build_$TARGET_TRIPLE"

cd libsndfile

INSTALL_PREFIX="prefix"
mkdir -p "$INSTALL_PREFIX"

cmake --build "$BUILD" -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
cmake --install "$BUILD" --prefix "$INSTALL_PREFIX"

# --target install doesn't understand multi-arch very well, so we move files
# and rewrite pkgconfig to make sense for the new location
SRC_INCLUDE_DIR="$INSTALL_PREFIX/include"
SRC_LIB_DIR="$INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"
DEST_MULTIARCH_PREFIX=/usr
DEST_INCLUDE_DIR="$DEST_MULTIARCH_PREFIX/include"
DEST_LIB_DIR="$DEST_MULTIARCH_PREFIX/lib/$TARGET_TRIPLE"
DEST_PKG_CONFIG_DIR="$DEST_LIB_DIR/pkgconfig"

mkdir -p "$DEST_PKG_CONFIG_DIR"
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