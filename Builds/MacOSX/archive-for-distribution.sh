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
  BUILDDIR="$MYDIR/build/$BUILD"
	if [ -d "$BUILDDIR" ]; then
    echo "Found build $BUILD"
    if [[ -d "$BUILDDIR/juicysfplugin.app" \
    && -d "$BUILDDIR/juicysfplugin.component" \
    && -d "$BUILDDIR/juicysfplugin.vst" \
    && -d "$BUILDDIR/juicysfplugin.vst3" ]]; then
      echo "Found in $BUILD all targets: .app, .component, .vst, .vst3"
      echo "Archiving $BUILD targets to build/$BUILD.tar.xz:"
      ls "$BUILDDIR"
      \cp -rf "$MYDIR/how to install.txt" "$BUILDDIR/how to install.txt"
      \cp -rf "$MYDIR/../../LICENSE.txt" "$BUILDDIR/LICENSE.txt"
      \cp -rf "$MYDIR/../../licenses_of_dependencies" "$BUILDDIR/."
      tar -hczf "$BUILDDIR.tar.xz" --exclude="libjuicysfplugin.a" -C "$MYDIR/build/$BUILD" .
    else
      echo "Did not find in $BUILD all targets: .app, .component, .vst, .vst3; skipping."
    fi
	else
		echo "Missing $BUILD; skipping."
	fi
done
