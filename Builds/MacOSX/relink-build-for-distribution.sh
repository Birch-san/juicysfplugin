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

LIBDIR="$MYDIR/lib"
BUILDDIR="$MYDIR/build"
PLUGINNAME="juicysfplugin"

declare -a BUILDS=("Debug" "Release")
# .app is a special case which has a Plugins folder inside it, containing a .appex Plugin
declare -a TARGETS=("app" \
"appex" \
"component" \
"vst" \
"vst3" \
"app/Contents/PlugIns/$PLUGINNAME.appex"
)

echo "Known builds: ${BUILDS[*]}"
echo "Known targets: ${TARGETS[*]}"

echo "Build directory: $BUILDDIR"
echo "Lib directory: $LIBDIR"


FLUIDSYNTH="libfluidsynth.1.7.2.dylib"
GLIB="libglib-2.0.0.dylib"
GTHREAD="libgthread-2.0.0.dylib"
INTL="libintl.8.dylib"
PCRE="libpcre.1.dylib"

# all of the following are just for SF3 support...
SNDFILE="libsndfile.1.dylib"
FLAC="libFLAC.8.dylib"
OGG="libogg.0.dylib"
VORBIS="libvorbis.0.dylib"
VORBISENC="libvorbisenc.2.dylib"

FRAMEWORKLOAD="@loader_path/../Frameworks"

for i in "${BUILDS[@]}"
do
	BUILD="$BUILDDIR/$i"
	if [ -d "$BUILD" ]; then
		echo "Found $i build subdirectory. Iterating over targets."
		for j in "${TARGETS[@]}"
		do
			CONTENTS="$BUILD/$PLUGINNAME.$j/Contents"
			BINARY="$CONTENTS/MacOS/$PLUGINNAME"
			if [ -f "$BINARY" ]; then

echo "Found $j"
echo "Copying libraries into target"
FRAMEWORKS="$CONTENTS/Frameworks"
mkdir -p "$FRAMEWORKS"
cp "$LIBDIR/"* "$FRAMEWORKS/"
# we're gonna relink these frameworks also, so make them writeable
chmod +w "$FRAMEWORKS/"*

# our $BINARY (Contents/MacOS/juicysfplugin) begins its life linked to a brew-installed fluidsynth library
# which it expects to find at: /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib
# we want to change this link to point to the fluidsynth library we copied into: Contents/MacOS/Frameworks/libfluidsynth.1.7.2.dylib
# we tell it to look for it with a relative path: @executable_path/../Frameworks/libfluidsynth.1.7.2.dylib
# and yes, it's fine to point it at our 1.7.2.dylib even though it expects 1.dylib. Because 1.dylib was always a symlink to the more specific version (1.7.2) anyway.
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib "$FRAMEWORKLOAD/$FLUIDSYNTH" "$BINARY"

# changes to our libfluidsynth (depends on glib, gthread, intl):
# change our 1.7.2.dylib to identify itself as 1.dylib, to meet our targets' expectations
install_name_tool -id "$FRAMEWORKLOAD/libfluidsynth.1.dylib" "$FRAMEWORKS/$FLUIDSYNTH"
install_name_tool -change /usr/local/opt/libsndfile/lib/libsndfile.1.dylib "$FRAMEWORKLOAD/$SNDFILE" "$FRAMEWORKS/$FLUIDSYNTH"
install_name_tool -change /usr/local/opt/glib/lib/libglib-2.0.0.dylib "$FRAMEWORKLOAD/$GLIB" "$FRAMEWORKS/$FLUIDSYNTH"
install_name_tool -change /usr/local/opt/glib/lib/libgthread-2.0.0.dylib "$FRAMEWORKLOAD/$GTHREAD" "$FRAMEWORKS/$FLUIDSYNTH"
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib "$FRAMEWORKLOAD/$INTL" "$FRAMEWORKS/$FLUIDSYNTH"

# changes to our glib (depends on pcre, intl):
install_name_tool -id "$FRAMEWORKLOAD/$GLIB" "$FRAMEWORKS/$GLIB"
install_name_tool -change /usr/local/opt/pcre/lib/libpcre.1.dylib "$FRAMEWORKLOAD/$PCRE" "$FRAMEWORKS/$GLIB"
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib "$FRAMEWORKLOAD/$INTL" "$FRAMEWORKS/$GLIB"

# changes to our gthread (depends on pcre, intl, glib):
# yes, the brew-installed libgthread links directly to brew-installed libglib (unlike fluidsynth, which points at a _symlink_ to the same)
install_name_tool -id "$FRAMEWORKLOAD/$GTHREAD" "$FRAMEWORKS/$GTHREAD"
install_name_tool -change /usr/local/opt/pcre/lib/libpcre.1.dylib "$FRAMEWORKLOAD/$PCRE" "$FRAMEWORKS/$GTHREAD"
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib "$FRAMEWORKLOAD/$INTL" "$FRAMEWORKS/$GTHREAD"
install_name_tool -change /usr/local/Cellar/glib/2.56.1/lib/libglib-2.0.0.dylib "$FRAMEWORKLOAD/$GLIB" "$FRAMEWORKS/$GTHREAD"

# changes to our intl:
install_name_tool -id "$FRAMEWORKLOAD/$INTL" "$FRAMEWORKS/$INTL"

# changes to our pcre:
install_name_tool -id "$FRAMEWORKLOAD/$PCRE" "$FRAMEWORKS/$PCRE"

# the following are just for SF3 support...
# changes to our libsndfile (depends on FLAC, ogg, vorbis, vorbisenc):
install_name_tool -id "$FRAMEWORKLOAD/$SNDFILE" "$FRAMEWORKS/$SNDFILE"
install_name_tool -change /usr/local/opt/flac/lib/libFLAC.8.dylib "$FRAMEWORKLOAD/$FLAC" "$FRAMEWORKS/$SNDFILE"
install_name_tool -change /usr/local/opt/libogg/lib/libogg.0.dylib "$FRAMEWORKLOAD/$OGG" "$FRAMEWORKS/$SNDFILE"
install_name_tool -change /usr/local/opt/libvorbis/lib/libvorbis.0.dylib "$FRAMEWORKLOAD/$VORBIS" "$FRAMEWORKS/$SNDFILE"
install_name_tool -change /usr/local/opt/libvorbis/lib/libvorbisenc.2.dylib "$FRAMEWORKLOAD/$VORBISENC" "$FRAMEWORKS/$SNDFILE"

# changes to our FLAC:
install_name_tool -id "$FRAMEWORKLOAD/$FLAC" "$FRAMEWORKS/$FLAC"

# changes to our ogg:
install_name_tool -id "$FRAMEWORKLOAD/$OGG" "$FRAMEWORKS/$OGG"

# changes to our vorbis (depends on ogg):
install_name_tool -id "$FRAMEWORKLOAD/$VORBIS" "$FRAMEWORKS/$VORBIS"
install_name_tool -change /usr/local/opt/libogg/lib/libogg.0.dylib "$FRAMEWORKLOAD/$OGG" "$FRAMEWORKS/$VORBIS"

# changes to our vorbisenc (depends on vorbis, ogg):
install_name_tool -id "$FRAMEWORKLOAD/$VORBISENC" "$FRAMEWORKS/$VORBISENC"
install_name_tool -change /usr/local/Cellar/libvorbis/1.3.6/lib/libvorbis.0.dylib "$FRAMEWORKLOAD/$VORBIS" "$FRAMEWORKS/$VORBISENC"
install_name_tool -change /usr/local/opt/libogg/lib/libogg.0.dylib "$FRAMEWORKLOAD/$OGG" "$FRAMEWORKS/$VORBISENC"

			else
				echo "Missing $j; skipping."
			fi
		done
	else
		echo "No build directory '$i'. Skipping."
	fi
done
