Here was the crazy idea to install libraries via x86_64 and arm64e brew, then merge them into universal binaries with lipo, then link against those libs.

```bash
# https://stackoverflow.com/a/65424574/5257399
# install brew for arm64e, x86_64. on this M1 Mac, arm64e is the native distribution.
# install native brew (arm64e):
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
# install foreign brew (x86_64):
arch -x86_64 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
alias ibrew='arch -x86_64 /usr/local/bin/brew'
alias mbrew='arch -arm64e /opt/homebrew/bin/brew'

# install fluidsynth via brew.
# we are **only** doing this to get a hold of its libraries.
# in fact, by default it's built with *more* libraries than we need (for example it has readline, for interactivity).
# get the x86_64 libraries:
ibrew install fluidsynth
# and the arm64e libraries:
mbrew install fluidsynth
# whichever architecture is native to you: use that to install pkg-config
brew install pkg-config

git clone git@github.com:FluidSynth/fluidsynth.git
cd fluidsynth
git checkout v2.2.4
# https://github.com/FluidSynth/fluidsynth/blob/master/README.cmake.md

# do a one-off single-architecture build just to generate the pkg-config
# or skip this and refer to my results below
cmake -Bbuild -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps" \
-DBUILD_SHARED_LIBS=off \
-Denable-portaudio=off \
-Denable-dbus=off \
-Denable-aufile=off \
-Denable-ipv6=off \
-Denable-jack=off \
-Denable-ladspa=off \
-Denable-libinstpatch=on \
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
-Denable-openmp=on \
-Denable-coreaudio=off \
-Denable-coremidi=off \
-Denable-framework=off \
-Denable-lash=off \
-Denable-alsa=off \
-Denable-systemd=off \
-DCMAKE_BUILD_TYPE=Debug
cmake --build build --target install
# now we know what dependencies we'll need
PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig" pkg-config --libs-only-l --static fluidsynth | tr ' ' '\n' | sort -u | grep -vEe '-l(fluidsynth|m)' | sed 's/^-l//'
# the dependencies are:
FLAC
glib-2.0
gthread-2.0
iconv
intl
ogg
opus
pcre
sndfile
vorbis
vorbisenc
# clean the build folder, so we're ready for our multi-arch build
rm -rf build

PKG_CONFIG_PATH="$(ibrew --prefix)/lib/pkgconfig" pkg-config --libs-only-l --static fluidsynth | tr ' ' '\n' | sort -u | grep -vEe '-l(fluidsynth|m)' | sed 's/^-l//'

mkdir -p "$HOME/juicyuniversals/lib" "$HOME/juicyuniversals/include"
LIBS="$(PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig" pkg-config --libs-only-l --static fluidsynth | tr ' ' '\n' | sort -u | grep -vEe '-l(fluidsynth|m)' | sed 's/^-l//')"
while read -r lib; do
  echo "Creating fat library of $lib."
  IN_x86_64="$(ibrew --prefix)/lib/lib${lib}.a"
  if [ ! -f "$IN_x86_64" ]; then
    echo "No x86_64 library at: $IN_x86_64"
    echo "Trying keg-only fallback..."
    IN_x86_64="$(ibrew --prefix)/opt/lib${lib}/lib/lib${lib}.a"
  fi
  if [ ! -f "$IN_x86_64" ]; then
    echo "Failed to find x86_64 library at: $IN_x86_64"
    continue
  fi
  IN_arm64e="$(mbrew --prefix)/lib/lib${lib}.a"
  if [ ! -f "$IN_arm64e" ]; then
    echo "No arm64e library at: $IN_arm64e"
    echo "Trying keg-only fallback..."
    IN_arm64e="$(mbrew --prefix)/opt/lib${lib}/lib/lib${lib}.a"
  fi
  if [ ! -f "$IN_arm64e" ]; then
    echo "Failed to find arm64e library at: $IN_arm64e"
    continue
  fi
  echo "x86_64 from: $IN_x86_64"
  echo "arm64e from: $IN_arm64e"
  OUT="$HOME/juicyuniversals/lib/lib${lib}.a"
  echo "Outputting to: $OUT"
  lipo -create "$IN_arm64e" "$IN_x86_64" -output "$OUT"
done <<< "$LIBS"


cmake -Bbuild -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps" \
-DBUILD_SHARED_LIBS=off \
-Denable-portaudio=off \
-Denable-dbus=off \
-Denable-aufile=off \
-Denable-ipv6=off \
-Denable-jack=off \
-Denable-ladspa=off \
-Denable-libinstpatch=on \
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
-Denable-openmp=on \
-Denable-coreaudio=off \
-Denable-coremidi=off \
-Denable-framework=off \
-Denable-lash=off \
-Denable-alsa=off \
-Denable-systemd=off \
'-DCMAKE_OSX_ARCHITECTURES=x86_64;arm64' \
-DCMAKE_PREFIX_PATH="$HOME/juicyuniversals" \
-DCMAKE_BUILD_TYPE=Debug
cmake --build build --target install
```