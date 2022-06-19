#!/usr/bin/env bash
set -eEo pipefail
cd libsndfile

BUILD="build_$TARGET_TRIPLE"

if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
  CROSS_COMPILING='1'
else
  CROSS_COMPILING=''
fi

if [ "$CROSS_COMPILING" == '1' ]; then
  CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION='-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY'
else
  CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION=''
fi
CMAKE_C_FLAGS=(-fPIC)
echo "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS[*]}"

LIB_DIR="/usr/lib/$TARGET_TRIPLE"

# hide shared objects, so find_library locates static libraries instead
# admittedly since pkgconfig is not run in static mode it won't find transitive
# dependencies, but juicysfplugin downstream *will*
LIBS_TO_RENAME="asound|ogg|FLAC|vorbis(enc|file)?|opus"
function __error_handing__(){
  local last_status_code=$1;
  local error_line_number=$2;
  echo 1>&2 "Error - exited with status $last_status_code at line $error_line_number";
  find -L "$LIB_DIR" -type f -regextype posix-extended -regex "$LIB_DIR/lib($LIBS_TO_RENAME)\.so\.bak\$" -exec rename 's/\.bak$//' '{}' \;
}
trap '__error_handing__ $? $LINENO' ERR
find -L "$LIB_DIR" -type f -regextype posix-extended -regex "$LIB_DIR/lib($LIBS_TO_RENAME)\.so\$" -exec rename 's/(.*)/$1.bak/' '{}' \;

# let's disable every codec and see whether it works anyway
cmake -B"$BUILD" \
"$CMAKE_TRY_COMPILE_TARGET_TYPE_OPTION" \
-DBUILD_SHARED_LIBS=off \
-DBUILD_PROGRAMS=off \
-DBUILD_EXAMPLES=off \
-DBUILD_TESTING=off \
-DENABLE_EXTERNAL_LIBS=on \
-DENABLE_MPEG=off \
-DENABLE_PACKAGE_CONFIG=on \
-DCMAKE_FIND_LIBRARY_PREFIXES='lib' \
-DCMAKE_FIND_LIBRARY_SUFFIXES='.a' \
-DCMAKE_C_FLAGS="${CMAKE_C_FLAGS[*]}" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE"