#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

TARGET_OS="$1"
ARCH="$2"

declare -A win32_TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A linux_TOOLCHAINS=( [x64]=amd64 [x86]=i386 [arm64]=arm64 )
declare -A win32_REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A linux_REPOS=( [x64]=x86_64 [x86]=i386 [arm64]=aarch64 )

DPKG_ARCH="${linux_TOOLCHAINS[$ARCH]}"
if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

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

resolve_try_compile_target_type_option () {
  local TARGET_OS="$1"
  case $TARGET_OS in
    win32)
      ;;

    linux)
      if [ "$CROSS_COMPILING" == '1' ]; then
        echo '-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY'
      fi
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

echo "target OS: $TARGET_OS"
echo "arch: $ARCH"

TOOLCHAIN_ARCH_VAR="${TARGET_OS}_TOOLCHAINS[$ARCH]"
TOOLCHAIN_ARCH="${!TOOLCHAIN_ARCH_VAR}"
echo "toolchain arch: $TOOLCHAIN_ARCH"
TOOLCHAIN_FILE="/${TARGET_OS}_${TOOLCHAIN_ARCH}_toolchain.cmake"
echo "toolchain file: $TOOLCHAIN_FILE"

BUILD="build_${TARGET_OS}_${ARCH}"

LIB_INSTALL_PATH="$(resolve_lib_install_path "$TARGET_OS" "$ARCH")"
echo "LIB_INSTALL_PATH: $LIB_INSTALL_PATH"

PKG_CONFIG_PATH="$(resolve_pkg_config_path "$LIB_INSTALL_PATH")"
echo "PKG_CONFIG_PATH: $PKG_CONFIG_PATH"

CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION="$(resolve_try_compile_target_type_option "$TARGET_OS")"
echo "CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION: $CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION"

# OpenMP doesn't support static libraries on Windows:
# https://github.com/llvm/llvm-project/blob/main/openmp/README.rst#options-for-libomp
# Yet, our priority is "statically-link everything" (in order to build a single-file binary,
# which can be installed by drag-and-drop).
# Use position-independent code because we need to be able to link our
# libfluidsynth.a into juicysfplugin.so, which must contain only PIC
PKG_CONFIG_PATH="$PKG_CONFIG_PATH" cmake -B"$BUILD" \
-DBUILD_SHARED_LIBS=off \
-Denable-portaudio=off \
-Denable-dbus=off \
-Denable-aufile=off \
-Denable-ipv6=off \
-Denable-jack=off \
-Denable-ladspa=off \
-Denable-libinstpatch=off \
-Denable-libsndfile=on \
-Denable-midishare=off \
-Denable-opensles=off \
-Denable-oboe=off \
-Denable-network=off \
-Denable-oss=off \
-Denable-dsound=off \
-Denable-wasapi=off \
-Denable-waveout=off \
-Denable-winmidi=off \
-Denable-sdl2=off \
-Denable-pkgconfig=on \
-Denable-pulseaudio=off \
-Denable-readline=off \
-Denable-threads=on \
-Denable-openmp=off \
-Denable-lash=off \
-Denable-alsa=off \
-Denable-systemd=off \
-DCMAKE_POSITION_INDEPENDENT_CODE=on \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
"$CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION" \
-DCMAKE_BUILD_TYPE=Release