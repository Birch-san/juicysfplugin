#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

TARGET_OS="$1"
ARCH="$2"

declare -A win32_REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A linux_REPOS=( [x64]=x86_64 [x86]=i386 [arm64]=aarch64 )

# builds include paths such as the following:
# /clang64/include
# /usr/include
resolve_include_install_path () {
  local TARGET_OS="$1"
  local ARCH="$2"
  local REPO_ARCH="${TARGET_OS}_REPOS[$ARCH]"
  local REPO="${!REPO_ARCH}"
  case $TARGET_OS in
    win32)
      echo "/$REPO/include"
      ;;

    linux)
      echo "/usr/include"
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
  local TARGET_OS="$1"
  local ARCH="$2"
  local REPO_ARCH="${TARGET_OS}_REPOS[$ARCH]"
  local REPO="${!REPO_ARCH}"
  case $TARGET_OS in
    win32)
      echo "/$REPO/lib"
      ;;

    linux)
      echo "/usr/lib/$REPO-linux-gnu"
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}


# builds PKG_CONFIG_PATHs such as the following:
# /clang64/lib/pkgconfig
# /usr/lib/x86_64-linux-gnu/pkgconfig
resolve_pkg_config_path () {
  local LIB_INSTALL_PATH="$1"
  echo "$LIB_INSTALL_PATH/pkgconfig"
}
 
echo "arch: $ARCH"

REPO="${REPOS[$ARCH]}"
echo "repo: $REPO"

BUILD="build_${TARGET_OS}_${ARCH}"

INCLUDE_INSTALL_PATH="$(resolve_include_install_path "$TARGET_OS" "$ARCH")"
LIB_INSTALL_PATH="$(resolve_lib_install_path "$TARGET_OS" "$ARCH")"
echo "LIB_INSTALL_PATH: $LIB_INSTALL_PATH"

PKG_CONFIG_PATH="$(resolve_pkg_config_path "$LIB_INSTALL_PATH")"
echo "PKG_CONFIG_PATH: $PKG_CONFIG_PATH"

cmake --build "$BUILD" --target libfluidsynth
# manual installation; not sure how to ask it to "only install libfluidsynth".
cp "$BUILD"/fluidsynth.pc "/$PKG_CONFIG_PATH/"
cp "$BUILD"/src/libfluidsynth*.a "/$LIB_INSTALL_PATH/libfluidsynth.a"
mkdir -p "/$INCLUDE_INSTALL_PATH/fluidsynth"
cp include/fluidsynth/*.h "/$INCLUDE_INSTALL_PATH/fluidsynth/"
cp "$BUILD"/include/fluidsynth.h "/$INCLUDE_INSTALL_PATH/fluidsynth.h"
cp "$BUILD"/include/fluidsynth/*.h "/$INCLUDE_INSTALL_PATH/fluidsynth/"