#!/usr/bin/env bash
cd JUCE

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
  echo "toolchain file: $TOOLCHAIN_FILE"

  BUILD="build_$ARCH"

  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-clang++" /opt/llvm-mingw/bin/c++
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-clang" /opt/llvm-mingw/bin/cc
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-addr2line" /opt/llvm-mingw/bin/addr2line
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-ar" /opt/llvm-mingw/bin/ar
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-ld" /opt/llvm-mingw/bin/ld
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-nm" /opt/llvm-mingw/bin/nm
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-objcopy" /opt/llvm-mingw/bin/objcopy
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-objdump" /opt/llvm-mingw/bin/objdump
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-ranlib" /opt/llvm-mingw/bin/ranlib
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-readelf" /opt/llvm-mingw/bin/readelf
  ln -sf "/opt/llvm-mingw/bin/${TOOLCHAIN}-w64-mingw32-strip" /opt/llvm-mingw/bin/strip

  VERBOSE=1 PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" \
-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
-DCMAKE_INSTALL_PREFIX="/$REPO" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_BUILD_TYPE=Debug
  cmake --build "$BUILD" --target install

  # PKG_CONFIG_PATH="$REPO/lib/pkgconfig" cmake -B build -DCMAKE_PREFIX_PATH="$REPO;/linux_native" -DCMAKE_BUILD_TYPE=Debug
  # cmake --build "$BUILD" --target JuicySFPlugin_Standalone

  # cp "$BUILD"/fluidsynth.pc /$REPO/lib/pkgconfig/
  # cp "$BUILD"/src/libfluidsynth*.a /$REPO/lib/libfluidsynth.a
  # mkdir -p /$REPO/include/fluidsynth
  # cp "$BUILD"/include/fluidsynth.h /$REPO/include/fluidsynth.h
  # cp "$BUILD"/include/fluidsynth/*.h /$REPO/include/fluidsynth/
done