These are instructions for producing a Universal Binary on an M1 Mac.

```bash
git clone git@github.com:juce-framework/JUCE.git
cd JUCE
git checkout 6.1.4
cmake -B cmake-build-install -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps"
cmake --build cmake-build-install --target install

# the brew distribution of fluidsynth is not suitable for static linking (it lacks a libfluidsynth.a)
# but this is still useful because it will give us all of the dependencies, which will enable us to install our own fuidsynth
brew install fluidsynth pkg-config

# install an Intel brew
arch -x86_64 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
alias ibrew="arch -x86_64 /usr/local/bin/brew"
# install Intel fluidsynth dependencies
ibrew install fluidsynth

git clone git@github.com:FluidSynth/fluidsynth.git
cd fluidsynth
git checkout v2.2.4
# https://github.com/FluidSynth/fluidsynth/blob/master/README.cmake.md

# use my forked cmake with fixed support for FindPkgConfig _LINK_LIBRARIES:
# https://gitlab.kitware.com/Birchlabs/cmake/-/merge_requests/1
# ~/git/cmake/cmake-build/bin/cmake
# or use your standard cmake, but grab the patched FindPkgConfig module from juicysfplugin repo:
# -DCMAKE_MODULE_PATH="$HOME/git/juicysfplugin/cmake/Modules/" cmake

# we disable libinstpatch because it's hard to statically-link against it
# - its cmake is not configured to statically-link against its own dependencies, or to produce a static binary
# - it's not published on brew
PKG_CONFIG_PATH="$(brew --prefix)/lib/pkgconfig" ~/git/cmake/cmake-build/bin/cmake -Bbuild -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps" \
-DBUILD_SHARED_LIBS=off \
-Denable-portaudio=off \
-Denable-dbus=off \
-Denable-aufile=off \
-Denable-ipv6=off \
-Denable-jack=off \
-Denable-ladspa=off \
-Denable-libinstpatch=off \
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
-DCMAKE_BUILD_TYPE=Release
cmake --build build --target install

PKG_CONFIG_PATH="$(ibrew --prefix)/lib/pkgconfig" ~/git/cmake/cmake-build/bin/cmake -Bbuild -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps_x86_64" \
-DBUILD_SHARED_LIBS=off \
-Denable-portaudio=off \
-Denable-dbus=off \
-Denable-aufile=off \
-Denable-ipv6=off \
-Denable-jack=off \
-Denable-ladspa=off \
-Denable-libinstpatch=off \
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
-DCMAKE_OSX_ARCHITECTURES=x86_64 \
-DCMAKE_BUILD_TYPE=Release
cmake --build build --target install

git clone git@github.com:Birch-san/juicysfplugin.git
cd juicysfplugin

# Simple version:
PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig;$(brew --prefix)/lib/pkgconfig" cmake -B build -DCMAKE_PREFIX_PATH="$HOME/juicydeps;$(brew --prefix)" -DCMAKE_BUILD_TYPE=Release

# XCode generator + Universal Binary + codesigning + AUv3 + VST2 + auto-install to /Library/Audio/Plug-Ins + target lower OS
PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig;$(brew --prefix)/lib/pkgconfig" cmake -B build -DCMAKE_PREFIX_PATH="$HOME/juicydeps;$(brew --prefix)" -DVST2_SDK_PATH="$HOME/SDKs/VST_SDK/VST2_SDK" -DVST_COPY_DIR="/Library/Audio/Plug-Ins/VST" -DVST3_COPY_DIR="/Library/Audio/Plug-Ins/VST3" -DAU_COPY_DIR="/Library/Audio/Plug-Ins/Components" '-DCMAKE_OSX_ARCHITECTURES=x86_64;arm64' -DEXTRA_ARCH_PKG_CONFIG_PATH="$HOME/juicydeps_x86_64/lib64/pkgconfig;$(ibrew --prefix)/lib/pkgconfig" -GXcode -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="Apple Development" -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM=TVU9P2GAL9 -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0

# use external VST3 SDK:
# -DVST2_SDK_PATH="$HOME/SDKs/VST_SDK/vst2sdk" -DVST3_SDK_PATH="$HOME/SDKs/VST_SDK/vst3sdk"

# build just one target, in Debug mode
cmake --build build --target JuicySFPlugin_Standalone
# build all targets, in Release mode
cmake --build build --config Release -- -allowProvisioningUpdates
````