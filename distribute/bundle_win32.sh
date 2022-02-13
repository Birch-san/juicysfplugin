#!/usr/bin/env bash
# ./bundle_win32.sh 3.1.0

set -eo pipefail
DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

OUT="$DIR/out"
mkdir -p "$OUT"

VERSION="$1"

# x86 build fails in JUCE 6.1.5; problem compiling UUIDGetter
# https://gist.github.com/Birch-san/a36b10155e51bd814ecc7109501e1e64
# declare -a ARCHS=("x64" "x86")
declare -a ARCHS=("x64")

# macOS bundled GNU bash doesn't support associative arrays
arch_long_ix() {
    case $1 in
        'x64') return 0;;
        'x86') return 1;;
    esac
}
arch_longs=("x86_64-win"
           "x86-win");
# declare -A ARCH_LONGS=( [x64]=x86_64-win [x86]=x86-win )

FLAVOUR=Release
CONTAINER_NAME=win32_mount
docker create --name "$CONTAINER_NAME" llvm-mingw
trap "docker rm \"$CONTAINER_NAME\" > /dev/null" EXIT

for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  set +e
  arch_long_ix "$ARCH"
  ARCH_LONG="${arch_longs[$?]}"
  set -e
  # ARCH_LONG="${ARCH_LONGS[$ARCH]}"
  echo "arch_long: $ARCH_LONG"

  FLAVOUR_DIRNAME="win_$ARCH"
  ARCH_OUT="$OUT/$FLAVOUR_DIRNAME"
  echo "arch_out: $ARCH_OUT"

  STANDALONE="$ARCH_OUT/Standalone"
  mkdir -p "$STANDALONE"

  VST2="$ARCH_OUT/VST2"
  mkdir -p "$VST2"

  VST3="$ARCH_OUT/VST3"
  mkdir -p "$VST3"

  docker cp "$CONTAINER_NAME":"$ARCH/$FLAVOUR/Standalone/juicysfplugin.exe" "$STANDALONE/juicysfplugin.exe"
  docker cp "$CONTAINER_NAME":"$ARCH/$FLAVOUR/VST/libjuicysfplugin.dll" "$VST2/libjuicysfplugin.dll"
  docker cp "$CONTAINER_NAME":"$ARCH/$FLAVOUR/VST3/juicysfplugin.vst3/Contents/$ARCH_LONG/juicysfplugin.vst3" "$VST3/juicysfplugin.vst3"

  cp -r "$DIR/../licenses_of_dependencies" "$ARCH_OUT"
  cp "$DIR/../LICENSE.txt" "$ARCH_OUT"

  cp "$DIR/README.$ARCH.txt" "$ARCH_OUT/README.txt"

  pushd "$OUT" > /dev/null
  zip -9 -r "juicysfplugin-$VERSION-$ARCH.zip" "$FLAVOUR_DIRNAME"
  popd > /dev/null
done