#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

TARGET_OS="$1"
ARCH="$2"

declare -A win32_REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A linux_ARCHS=( [x64]=x86_64 [x86]=i386 [arm64]=aarch64 )

# builds prefix paths such as the following:
# /clang64
# /usr
resolve_multiarch_install_prefix () {
  local TARGET_OS="$1"
  local ARCH="$2"
  case $TARGET_OS in
    win32)
      local REPO="${win32_REPOS[$ARCH]}"
      echo "/$REPO"
      ;;

    linux)
      echo "/usr"
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

# builds lib paths such as the following:
# /clang64/lib
# /usr/lib/x86_64-linux-gnu
resolve_lib_install_path () {
  local PREFIX="$1"
  local TARGET_OS="$2"
  local ARCH_NICKNAME="$3"
  local LIB_UNQUALIFIED="$PREFIX/lib"
  case $TARGET_OS in
    win32)
      echo "$LIB_UNQUALIFIED"
      ;;

    linux)
      local ARCH="${linux_ARCHS[$ARCH_NICKNAME]}"
      local TARGET_TRIPLE="$ARCH-linux-gnu"
      echo "$LIB_UNQUALIFIED/$TARGET_TRIPLE"
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}
 
echo "arch: $ARCH"

BUILD="build_${TARGET_OS}_${ARCH}"

INSTALL_PREFIX="$(resolve_multiarch_install_prefix "$TARGET_OS" "$ARCH")"

INCLUDE_INSTALL_PATH="$INSTALL_PREFIX/include"
LIB_INSTALL_PATH="$(resolve_lib_install_path "$INSTALL_PREFIX" "$TARGET_OS" "$ARCH")"
echo "LIB_INSTALL_PATH: $LIB_INSTALL_PATH"

PKG_CONFIG_PATH="$LIB_INSTALL_PATH/pkgconfig"
echo "PKG_CONFIG_PATH: $PKG_CONFIG_PATH"

cmake --build "$BUILD" --target libfluidsynth -- -j"$(($(grep -c ^processor /proc/cpuinfo)+1))"
# manual installation; not sure how to ask it to "only install libfluidsynth".
cp "$BUILD"/fluidsynth.pc "$PKG_CONFIG_PATH/"
cp "$BUILD"/src/libfluidsynth*.a "$LIB_INSTALL_PATH/libfluidsynth.a"
mkdir -p "$INCLUDE_INSTALL_PATH/fluidsynth"
cp include/fluidsynth/*.h "$INCLUDE_INSTALL_PATH/fluidsynth/"
cp "$BUILD"/include/fluidsynth.h "$INCLUDE_INSTALL_PATH/fluidsynth.h"
cp "$BUILD"/include/fluidsynth/*.h "$INCLUDE_INSTALL_PATH/fluidsynth/"

FLUIDSYNTH_PC="$PKG_CONFIG_PATH/fluidsynth.pc"
gawk -i inplace -F'=' '$1 ~ /^prefix$/ {
  $2="'"$INSTALL_PREFIX"'"
}
$1 ~ /^libdir$/ {
  $2="${pcfiledir}/.."
}
{ print $0 }' OFS== "$FLUIDSYNTH_PC"