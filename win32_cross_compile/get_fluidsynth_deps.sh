#!/usr/bin/env bash
# declare -a ARCHS=("x64" "x86" "arm64")
declare -a ARCHS=("x64" "x86" "arm64")
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A PKG_PREFIX_ARCHS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -a PKGS=("libiconv" "flac" "glib2" "libogg" "opus-1" "libvorbis" "pcre-" "libsndfile")

# -lFLAC
# -lfluidsynth
# -lglib-2.0
# -lgthread-2.0
# -liconv
# -lintl
# -lm
# -logg
# -lopus
# -lpcre
# -lsndfile
# -lvorbis
# -lvorbisenc
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  REPO_URL="https://repo.msys2.org/mingw/$REPO"
  echo "repo URL: $REPO_URL"

  INSTALL_ROOT="/deps/$ARCH"

  mkdir -p "$INSTALL_ROOT"
  echo "install root: $INSTALL_ROOT"

  for PKG in ${PKGS[@]}; do
    echo "pkg: $PKG"
    PKG_PREFIX_ARCH="${PKG_PREFIX_ARCHS[$ARCH]}"
    echo "pkg prefix arch: $PKG_PREFIX_ARCH"
    PKG_PREFIX="mingw-w64-clang-$PKG_PREFIX_ARCH-$PKG"
    echo "pkg prefix: $PKG_PREFIX"
    URL="$REPO_URL" /build/install.sh "$PKG_PREFIX"
  done
done