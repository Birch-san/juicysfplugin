#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

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

BUILD="build_${TARGET_OS}_${ARCH}"

CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION="$(resolve_try_compile_target_type_option "$TARGET_OS")"
echo "CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION: $CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION"

# OpenMP doesn't support static libraries on Windows:
# https://github.com/llvm/llvm-project/blob/main/openmp/README.rst#options-for-libomp
# Yet, our priority is "statically-link everything" (in order to build a single-file binary,
# which can be installed by drag-and-drop).
# Use position-independent code because we need to be able to link our
# libfluidsynth.a into juicysfplugin.so, which must contain only PIC
PKG_CONFIG_PATH="$DEST_PKG_CONFIG_PATH" cmake -B"$BUILD" \
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