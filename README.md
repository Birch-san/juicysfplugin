<img width="634" alt="image" src="https://user-images.githubusercontent.com/6141784/37062123-745e79f2-218d-11e8-8e30-30b3effeca70.png">

Latest release: https://github.com/Birch-san/juicysfplugin/releases

Demo track: [mp3](https://github.com/Birch-san/juicysfplugin/releases/download/1.0.5/Demo_track.mp3), [FLAC](https://github.com/Birch-san/juicysfplugin/releases/download/1.0.5/Demo_track.flac), [FLAC+compressor](https://github.com/Birch-san/juicysfplugin/releases/download/1.0.5/Demo_track_soundgoodizer.flac)

# What

juicysfplugin is a macOS audio plugin for playing MIDI music through a soundfont synthesizer.

It's well-suited for making videogame music. If you have a soundfont of your favourite game, you can write your own melodies with its instruments.

[JUCE](https://github.com/WeAreROLI/JUCE) is the framework for making audio plugins.  
[fluidsynth](http://www.fluidsynth.org/) is the soundfont synthesizer.

**Mode 1: standalone application**

juicysfplugin.app is a standalone application, for playing around.

You can plugin your hardware MIDI keyboard, or play with the software MIDI keyboard. Or route MIDI messages into it from a virtual MIDI controller (e.g. the [macOS IAC Bus](http://re-compose.desk.com/customer/portal/articles/1382244-setting-up-the-iac-bus-on-a-mac)).  

**Mode 2: audio plugin**

juicysfplugin audio plugins are provided: VST, VST3, AU, AUv3.  
This means you can host it inside your DAW (e.g. GarageBand, FL Studio Mac, Sibelius…) to record the sounds you make.

# Why

I couldn't find a _free_, _easy-to-use_ macOS audio plugin for making music with soundfonts.

# Install

Latest release: https://github.com/Birch-san/juicysfplugin/releases

**Download Release.tar.xz, open it to unzip.**

Release contains:

```
juicysfplugin.app  # standalone application, for playing around
juicysfplugin.component  # AU plugin
juicysfplugin.vst  # VST plugin
juicysfplugin.vst3  # VST3 plugin
```

To install plugins, move them to the following folder:

```
juicysfplugin.component -> ~/Library/Audio/Plug-Ins/Components/juicysfplugin.component
juicysfplugin.vst -> ~/Library/Audio/Plug-Ins/VST/juicysfplugin.vst
juicysfplugin.vst3 -> ~/Library/Audio/Plug-Ins/VST3/juicysfplugin.vst3
```

Now, you may do one of the following:

- Open the standalone juicysfplugin.app
- Load the AU/VST/VST3 into your favourite DAW (e.g. GarageBand, FL Studio)

**Load a soundfont**

You can drag-and-drop a soundfont into the file picker.

![image](https://user-images.githubusercontent.com/6141784/37062424-500bc91e-218e-11e8-9916-eae6d82ca566.png)

Here's some soundfonts to get you started:

- FlameStudios' GPL-licensed [guitar soundfonts](http://www.flamestudios.org/free/Soundfonts)

I'll refrain from recommending specific General MIDI or videogame soundfonts, since the licensing and provenance are often unclear.

### How do I setup the standalone .app

**Options > Audio/MIDI settings**

<img width="256px" alt="image" src="https://user-images.githubusercontent.com/6141784/37062230-bdb128b6-218d-11e8-985a-e9b2b5fd0bb2.png">

**Set Output to Built-In Output**

Or any output device that you can hear audio through.

Input audio device doesn't matter. We only use MIDI as input.  
Ignore the warning about feedback. There is no feedback loop (no audio is input).

<img width="515" alt="image" src="https://user-images.githubusercontent.com/6141784/37062266-d723c984-218d-11e8-9ded-9dc5eb701199.png">

# Building from source

Install XCode and XCode command line tools. Accept terms.

Ensure [brew](https://brew.sh/) and `libfluidsynth` are installed:

```bash
brew install fluidsynth
```

Install [JUCE](https://shop.juce.com/get-juce) 5.3 in `/Applications`.  
We expect to find JUCE headers in `/Applications/JUCE/modules`.

(Optional) To target VST3, install Steinberg [VST3 Audio Plug-Ins SDK](https://www.steinberg.net/en/company/developers.html).  
We expect to find a folder `~/SDKs/VST_SDK/VST3_SDK`.

(Optional) Install IntelliJ AppCode if you prefer it to XCode.

Open `juicysfplugin/Builds/MacOSX/juicysfplugin.xcodeproj` in XCode (or IntelliJ AppCode).

Build & run the "juicysfplugin - Standalone Plugin" target.

## Testing VST/AU plugins inside an audio plugin host

You'll notice that the schemes for [VST, VST3, AU, AUv3] targets are configured such that "Run" launches the executable `AudioPluginHost.app`. This lets you run the audio plugin as though it were hosted inside a DAW.

I recommend building (e.g. with XCode) the simple Audio Plugin Host that comes with JUCE Framework:

`/Applications/JUCE/extras/AudioPluginHost/Builds/MacOSX/AudioPluginHost.xcodeproj`

Then symlink `/Applications/JUCE/AudioPluginHost.app` to it (simply because that's where I told the Run configuration to look for it):

```bash
ln -sf /Applications/JUCE/extras/AudioPluginHost/Builds/MacOSX/build/Debug/AudioPluginHost.app /Applications/JUCE/AudioPluginHost.app
```

# Dependency versions

Known working with:

```
macOS High Sierra 10.13
XCode 9.3
JUCE Framework 5.3
VST3 Audio Plug-Ins SDK 3.6.9
# brew:
- fluidsynth --version 1.1.10
- libraries in /usr/local/lib
- headers in /usr/local/include
libfluidsynth.1.7.1.dylib
  ├─libglib-2.0.0.dylib
  │   └─libpcre.1.dylib
  ├─libgthread-2.0.0.dylib
  └─libintl.8.dylib
```

# Making portable releases

Follow the steps in [Building from source](#building-from-source) to output a product to the build folder.

The .app, .vst (and so on) that you build will only work on a computer that has brew fluidsynth installed.

If you want to build a _truly portable release_, you'll need to _bundle libfluidsynth and all its dependencies_ into your product.

```bash
cd juicysfplugin/Builds/MacOSX
# first check that you have a Release or Debug product in the `build` directory

# bundles `juicysfplugin/lib` libs into the products you created,
# relinks your executables to use their bundled libs
./relink-build-for-distribution.sh

# follows symlinks, archives Release and Debug folders as tar.xz
./archive-for-distribution.sh
```

Note: Release **and** Debug flavors _both_ output targets [VST, VST3, AU] to the same location:  `~/Library/Audio/Plug-Ins/$TARGET/juicysfplugin.$EXT`.  
Whichever flavor you built _most recently_, wins.

The way I provide archives of _both_ build flavors is by archiving one, building next flavor, then archiving that (i.e. I build serially, not parallel).  
But probably people only care about the Release flavor anyway.

# Licenses

Tell me if I've missed anything.

Overall, juicysfplugin is GPLv3.

## Framework

Built upon JUCE framework under the GPL-v3 license:

https://www.gnu.org/licenses/gpl-3.0.en.html

## Libraries

The following external libraries are bundled into this audio plugin and dynamically linked:

### `libintl` LGPL

https://www.gnu.org/software/gettext/manual/html_node/Licenses.html

> either version 2.1 of the License, or (at your option) any later version.

### `libglib` LGPL

> either version 2.1 of the License, or (at your option) any later version.

### `libgthread` LGPL

> either version 2.1 of the License, or (at your option) any later version.

## `libpcre` BSD

> Release 8 of PCRE is distributed under the terms of the "BSD" licence.

### `libfluidsynth` LGPL

https://github.com/FluidSynth/fluidsynth/blob/master/LICENSE

> (This is the first released version of the Lesser GPL.  It also counts as the successor of the GNU Library Public License, version 2, hence the version number 2.1.)

## SDKs

### Steinberg VST3

The VST3 release is built against the Steinberg VST3 SDK.

http://www.steinberg.net/sdklicenses_vst3

> This Software Development Kit is licensed under the terms of the Steinberg VST3 License,
or alternatively under the terms of the General Public License (GPL) Version 3.

# Questions

## Windows/Linux/Android/iOS version?

No _big_ barriers. The source code and all its dependencies are cross-platform. The main friction is setting up a dev environment, and learning how to link dynamic libraries on that OS (i.e. we need to link to libfluidsynth).

Some thoughts that come to mind:

- Bundling libraries portably is far easier on Windows than on macOS
  - Just throw a dll next to the executable
  - .NET assembly binding can be debugged using [fuslogvw](https://docs.microsoft.com/en-us/dotnet/framework/tools/fuslogvw-exe-assembly-binding-log-viewer)
- Windows already has plenty of free, nice soundfont plugins
- It's probably pretty hard to bundle fluidsynth into mobile apps
- Bundling would be easier if I used static linking
- Static linking is hard