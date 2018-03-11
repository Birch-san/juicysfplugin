#!/usr/bin/env bash

# Ascertain directory in which script lives; compatible with all UNIX
# Thanks to kenorb
# http://stackoverflow.com/a/17744637/5257399
MYDIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
set -o pipefail

error() {
  local parent_lineno="$1"
  local message="$2"
  local code="${3:-1}"
  if [[ -n "$message" ]] ; then
    echo "Error on or near line ${parent_lineno}: ${message}; exiting with status ${code}"
  else
    echo "Error on or near line ${parent_lineno}; exiting with status ${code}"
  fi
  exit "${code}"
}
trap 'error ${LINENO}' ERR

####

declare -a BUILDS=("Debug" "Release")
for BUILD in "${BUILDS[@]}"
do
	if [ -d "$MYDIR/build/$BUILD" ]; then
		echo "Found $BUILD; archiving targets to build/$BUILD.tar.xz:"
		ls "$MYDIR/build/$BUILD"
		tar -hczf "$MYDIR/build/$BUILD.tar.xz" -C "$MYDIR/build/$BUILD" .
	else
		echo "Missing $BUILD; skipping."
	fi
done
