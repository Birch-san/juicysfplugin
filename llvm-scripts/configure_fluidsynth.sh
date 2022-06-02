#!/usr/bin/env bash
set -eo pipefail
shopt -s nullglob

cd fluidsynth

if test -n "$1"; then
  declare -a ARCHS=("$1")
else
  declare -a ARCHS=("x64" "x86" "arm64")
fi

declare -A TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  TOOLCHAIN="${TOOLCHAINS[$ARCH]}"
  echo "toolchain: $TOOLCHAIN"
  TOOLCHAIN_FILE="/${TOOLCHAIN}_toolchain.cmake"
  echo "toolchain file: $TOOLCHAIN_FILE"

  BUILD="build_$ARCH"

  # OpenMP doesn't support static libraries on Windows:
  # https://github.com/llvm/llvm-project/blob/main/openmp/README.rst#options-for-libomp
  # Yet, our priority is "statically-link everything" (in order to build a single-file binary,
  # which can be installed by drag-and-drop).
  PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" -DCMAKE_INSTALL_PREFIX="/$REPO" \
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
-Denable-coreaudio=off \
-Denable-coremidi=off \
-Denable-framework=off \
-Denable-lash=off \
-Denable-alsa=off \
-Denable-systemd=off \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_BUILD_TYPE=Release
done