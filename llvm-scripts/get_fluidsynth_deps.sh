#!/usr/bin/env bash

set -eo pipefail
shopt -s nullglob

CTRL='\033' # begin escape sequence
BC="${CTRL}[0;" # begin colour modification
Red="${BC}31m"
Purple="${BC}35m"
Cyan="${BC}36m"
NC="${BC}0m" # No Color

if test -n "$1"; then
  declare -a ARCHS=("$1")
else
  declare -a ARCHS=("x64" "x86" "arm64")
fi

declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A PKG_PREFIX_ARCHS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
# https://waterlan.home.xs4all.nl/libintl.html
# apparently libintl is part of gettext
declare -a PKGS=("libiconv" "flac" "glib2" "libogg" "opus-1" "libvorbis" "pcre-" "libsndfile" "gettext")

pids=()

_term() {
  echo "Caught SIGTERM signal!"
  if [ ${#pids} -eq 0 ]
  then
    echo "No child processes; exiting."
    return $?
  fi
  echo "Sending SIGTERM to ${#pids} child processes: ${pids[*]}"
  for pid in ${arr[@]}
  do
    kill -TERM "$pid"
  done
}
_int() {
  echo "Caught fatal signal!"
  if [ ${#pids} -eq 0 ]
  then
    echo "No child processes; exiting."
    return $?
  fi
  echo "Sending SIGINT to ${#pids} child processes: ${pids[*]}"
  for pid in ${arr[@]}
  do
    kill -INT "$pid"
  done
}
trap '_int' SIGINT EXIT
trap '_term' SIGTERM
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  REPO_URL="https://repo.msys2.org/mingw/$REPO"
  echo "repo URL: $REPO_URL"

  REPO_FILE="repo-$ARCH.txt"
  echo "repo file: $REPO_FILE"
  wget -qO "$REPO_FILE" "$REPO_URL"

  INSTALL_ROOT="/deps/$ARCH"

  mkdir -p "$INSTALL_ROOT"
  echo "install root: $INSTALL_ROOT"

  for PKG in ${PKGS[@]}; do
    echo "pkg: $PKG"
    PKG_PREFIX_ARCH="${PKG_PREFIX_ARCHS[$ARCH]}"
    echo "pkg prefix arch: $PKG_PREFIX_ARCH"
    PKG_PREFIX="mingw-w64-clang-$PKG_PREFIX_ARCH-$PKG"
    echo "pkg prefix: $PKG_PREFIX"

    FILE=`cat $REPO_FILE | sed -n 's/.*href="\([^"]*\).*/\1/p' | grep -E "^$PKG_PREFIX" | egrep -v '.sig$' | sort | tail -1f`

    if [[ $FILE == *.zst || $FILE == *.xz ]]
    then
      ASSET="$REPO_URL/$FILE"
      echo -e "${Cyan}Downloading $ASSET...${NC}"
      wget -q "$ASSET" &
      pids+=("$!")
    else
      >&2 echo -e "${Red}$FILE cannot be extracted; unsupported extension${NC}"
      exit 1
    fi
  done
done

echo -e "${Cyan}Waiting for ${#pids[@]} parallel downloads to complete...${NC}"
for pid in "${pids[@]}"; do
  wait "$pid"
done

trap - SIGINT EXIT SIGTERM

for file in *.zst; do
  echo -e "${Cyan}Extracting $file...${NC}"
  tar -I zstd -xvf "$file" -C /
  rm "$file"
done

for file in *.xz; do
  echo -e "${Cyan}Extracting $file...${NC}"
  tar xJvf "$file" -C /
  rm "$file"
done