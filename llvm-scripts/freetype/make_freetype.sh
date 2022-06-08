#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
TARGET_TRIPLE="$ARCH-linux-gnu"
BUILD="build_$TARGET_TRIPLE"

cd freetype

cmake --build "$BUILD" -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"

# --target install doesn't understand multi-arch very well, so we move files
# and rewrite pkgconfig to make sense for the new location
SRC_INCLUDE_DIR="$BUILD/include"
SRC_LIB_DIR="$BUILD"
SRC_PKG_CONFIG_DIR="$BUILD"
DEST_MULTIARCH_PREFIX=/usr
DEST_INCLUDE_DIR="$DEST_MULTIARCH_PREFIX/include"
DEST_LIB_DIR="$DEST_MULTIARCH_PREFIX/lib/$TARGET_TRIPLE"
DEST_PKG_CONFIG_DIR="$DEST_LIB_DIR/pkgconfig"

mkdir -p "$DEST_PKG_CONFIG_DIR"
cp -R include/* "$DEST_INCLUDE_DIR/"
mv "$SRC_INCLUDE_DIR"/freetype/config/* "$DEST_INCLUDE_DIR"/freetype/config/
mv "$SRC_LIB_DIR"/libfreetype.a "$DEST_LIB_DIR/"
mv "$SRC_PKG_CONFIG_DIR"/freetype2.pc "$DEST_PKG_CONFIG_DIR/"
TMPFILE="$(mktemp)"
FREETYPE_PC="$DEST_PKG_CONFIG_DIR/freetype2.pc"
awk -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$FREETYPE_PC" > "$TMPFILE"
mv "$TMPFILE" "$FREETYPE_PC"