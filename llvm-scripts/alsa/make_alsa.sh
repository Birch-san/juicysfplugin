#!/usr/bin/env bash
set -eo pipefail
ARCH="$1"
TARGET_TRIPLE="$ARCH-linux-gnu"
SRC_INSTALL_PREFIX="/alsa-install"
SRC_INCLUDE_DIR="$SRC_INSTALL_PREFIX/include"
SRC_LIB_DIR="$SRC_INSTALL_PREFIX/lib"
SRC_PKG_CONFIG_DIR="$SRC_LIB_DIR/pkgconfig"
DEST_MULTIARCH_PREFIX=/usr
DEST_INCLUDE_DIR="$DEST_MULTIARCH_PREFIX/include"
DEST_LIB_DIR="$DEST_MULTIARCH_PREFIX/lib/$TARGET_TRIPLE"
DEST_PKG_CONFIG_DIR="$DEST_LIB_DIR/pkgconfig"
cd alsa-lib
make -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
make install
# --prefix doesn't understand multi-arch very well, so we move files
# and rewrite pkgconfig to make sense for the new location
mkdir -p "$DEST_PKG_CONFIG_DIR"
mv "$SRC_INCLUDE_DIR"/* "$DEST_INCLUDE_DIR/"
mv "$SRC_LIB_DIR"/liba{sound,topology}.a "$DEST_LIB_DIR/"
mv "$SRC_PKG_CONFIG_DIR"/alsa{,-topology}.pc "$DEST_PKG_CONFIG_DIR/"
TMPFILE="$(mktemp)"
ALSA_PC="$DEST_PKG_CONFIG_DIR/alsa.pc"
awk -F'=' '$1 ~ /^prefix$/ {
  $2="/usr"
}
$1 ~ /^exec_prefix$/ {
  $2="${prefix}"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$ALSA_PC" > "$TMPFILE"
mv "$TMPFILE" "$ALSA_PC"