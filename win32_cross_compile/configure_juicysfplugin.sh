#!/usr/bin/env bash

# declare -a ARCHS=("x64" "x86" "arm64")
declare -a ARCHS=("x64")
declare -A TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  TOOLCHAIN="${TOOLCHAINS[$ARCH]}"
  echo "toolchain: $TOOLCHAIN"
  TOOLCHAIN_FILE="/build/${TOOLCHAIN}_toolchain.cmake"
  TOOLCHAIN_LIB_DIR="/opt/llvm-mingw/${TOOLCHAIN}-w64-mingw32/lib"
  echo "toolchain file: $TOOLCHAIN_FILE"

  BUILD="build_$ARCH"

  # we don't have pkg-config files for system libraries (e.g. libintl),
  # so pkg-config doesn't know that it depends on libiconv.
  # hence we introduce libiconv via CMAKE_EXE_LINKER_FLAGS.

  # the advice in pkg-config "libs other" (to provide -pthread flag to linker)
  # ends up dynamically linking it, even if we preface with -Wl,Bstatic
  # so I've told CMakeFiles not to use the "libs other" advice.
  # consequentially it's up to us to link in a suitable pthread archive via CMAKE_EXE_LINKER_FLAGS
  VERBOSE=1 PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" \
-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
-DCMAKE_PREFIX_PATH="/linux_native" \
-DCMAKE_EXE_LINKER_FLAGS="/$REPO/lib/libiconv.a $TOOLCHAIN_LIB_DIR/libwinpthread.a" \
-DCMAKE_INSTALL_PREFIX="/$REPO" \
-DVST2_SDK_PATH="/VST2_SDK" \
-DCMAKE_CXX_FLAGS='-DJUCE_DISABLE_ASSERTIONS' \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_BUILD_TYPE=Debug
done