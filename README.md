<img width="634" alt="image" src="https://user-images.githubusercontent.com/6141784/37062123-745e79f2-218d-11e8-8e30-30b3effeca70.png">

Latest release: https://github.com/Birch-san/juicysfplugin/releases

# What

juicysfplugin is an Audio Plugin for playing MIDI music through a soundfont synthesizer.

[JUCE](https://github.com/WeAreROLI/JUCE) is the framework for making audio plugins.  
[fluidsynth](http://www.fluidsynth.org/) is the soundfont synthesizer.

juicysfplugin works as a standalone application (for playing around). You can plugin your hardware MIDI keyboard, or play with the software MIDI keyboard. Or router MIDI messages into it from a virtual MIDI controller (e.g. the macOS IAC Bus).  

juicysfplugin is also an Audio Plugin. VST, VST3, AU, AUv3.

# Why

I couldn't find a _free_, _easy-to-use_ macOS audio plugin for making music with soundfonts.

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