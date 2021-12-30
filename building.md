```bash
git clone git@github.com:juce-framework/JUCE.git
cd JUCE
git checkout 6.1.4
cmake -B cmake-build-install -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps"
cmake --build cmake-build-install --target install

# the brew distribution of fluidsynth is not suitable for static linking (it lacks a libfluidsynth.a)
# but this is still useful because it will give us all of the dependencies, which will enable us to install our own fuidsynth
brew install fluidsynth pkg-config

git clone git@github.com:FluidSynth/fluidsynth.git
cd fluidsynth
git checkout v2.2.4
# https://github.com/FluidSynth/fluidsynth/blob/master/README.cmake.md
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
-DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build --target install

git clone git@github.com:Birch-san/juicysfplugin.git
cd juicysfplugin
PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig;$(brew --prefix)/lib/pkgconfig" cmake -B build -DCMAKE_PREFIX_PATH="$HOME/juicydeps;$(brew --prefix)" -DCMAKE_BUILD_TYPE=Debug -DVST2_SDK_PATH="$HOME/SDKs/VST_SDK/VST2_SDK" -DVST_COPY_DIR="/Library/Audio/Plug-Ins/VST" -DVST3_COPY_DIR="/Library/Audio/Plug-Ins/VST3" -DAU_COPY_DIR="/Library/Audio/Plug-Ins/Components"

# use VST3 SDK:
PKG_CONFIG_PATH="$HOME/juicydeps/lib64/pkgconfig;$(brew --prefix)/lib/pkgconfig" cmake -B build -DCMAKE_PREFIX_PATH="$HOME/juicydeps;$(brew --prefix)" -DCMAKE_BUILD_TYPE=Debug -DVST2_SDK_PATH="$HOME/SDKs/VST_SDK/vst2sdk" -DVST3_SDK_PATH="$HOME/SDKs/VST_SDK/vst3sdk" -DVST_COPY_DIR="/Library/Audio/Plug-Ins/VST" -DVST3_COPY_DIR="/Library/Audio/Plug-Ins/VST3" -DAU_COPY_DIR="/Library/Audio/Plug-Ins/Components"
cmake --build build
````