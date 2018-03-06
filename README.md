<img src="https://github.com/Birch-san/juicysfplugin/raw/master/Juicy.png" width="128px">

<img width="634" alt="image" src="https://user-images.githubusercontent.com/6141784/37062123-745e79f2-218d-11e8-8e30-30b3effeca70.png">

# What

juicysfplugin is an Audio Plugin for playing MIDI music through a soundfont synthesizer.

[JUCE](https://github.com/WeAreROLI/JUCE) is the framework for making audio plugins.  
[fluidsynth](http://www.fluidsynth.org/) is the soundfont synthesizer.

juicysfplugin works as a standalone application (for playing around). You can plugin your hardware MIDI keyboard, or play with the software MIDI keyboard. Or router MIDI messages into it from a virtual MIDI controller (e.g. the macOS IAC Bus).  

juicysfplugin is also an Audio Plugin. VST, VST3, AU, AUv3.

# Making portable releases

Building is trivial, but bundling to deploy on other people's computers is harder (they don't have fluidsynth, nor its dependencies).

I've not automated this process.  
It relies on the "copy" build steps which ensure our frameworks are bundled into the targets (e.g. libfluidsynth gets copied into the Frameworks folder of the .app target).  
After that, I manually relink the .app to be portable. Here's how...

Assuming your `juicysfplugin` repository lives in `~/git/juicysfplugin`, then by default it will be compiled will a dynamic link to the fluidsynth which brew installed into `/usr/local/opt`:

```bash
otool -L /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin 
/Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin:
	/usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib (compatibility version 1.0.0, current version 1.7.1)
```

We can rewrite this dynamic link like so:

```bash
# the executable depends on fluidsynth 1
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib @executable_path/../Frameworks/libfluidsynth.1.7.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin
# the appex Plugin depends on fluidsynth 1. might have this slightly wrong.
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib @executable_path/../Frameworks/libfluidsynth.1.7.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/PlugIns/juicysfplugin.appex/Contents/MacOS/juicysfplugin
chmod +w /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/*
# fluidsynth depends on glib, gthread, intl
# change its identity from 1.7.1 to just 1
install_name_tool -id @loader_path/../Frameworks/libfluidsynth.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
install_name_tool -change /usr/local/opt/glib/lib/libglib-2.0.0.dylib @loader_path/../Frameworks/libglib-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
install_name_tool -change /usr/local/opt/glib/lib/libgthread-2.0.0.dylib @loader_path/../Frameworks/libgthread-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib @loader_path/../Frameworks/libintl.8.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
# glib depends on pcre, intl
install_name_tool -id @loader_path/../Frameworks/libglib-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libglib-2.0.0.dylib
install_name_tool -change /usr/local/opt/pcre/lib/libpcre.1.dylib @loader_path/../Frameworks/libpcre.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libglib-2.0.0.dylib
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib @loader_path/../Frameworks/libintl.8.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libglib-2.0.0.dylib
# gthread depends on pcre, intl, glib
install_name_tool -id @loader_path/../Frameworks/libgthread-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libgthread-2.0.0.dylib
install_name_tool -change /usr/local/opt/pcre/lib/libpcre.1.dylib @loader_path/../Frameworks/libpcre.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libgthread-2.0.0.dylib
install_name_tool -change /usr/local/opt/gettext/lib/libintl.8.dylib @loader_path/../Frameworks/libintl.8.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libgthread-2.0.0.dylib
install_name_tool -change /usr/local/Cellar/glib/2.54.3/lib/libglib-2.0.0.dylib @loader_path/../Frameworks/libglib-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libgthread-2.0.0.dylib
# intl
install_name_tool -id @loader_path/../Frameworks/libintl.8.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libintl.8.dylib
# pcre
install_name_tool -id @loader_path/../Frameworks/libpcre.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libpcre.1.dylib
```


## dependencies

We'll need:

> glib and gthread, but also iconv and intl

https://lists.nongnu.org/archive/html/fluid-dev/2012-03/msg00032.html  
https://lists.nongnu.org/archive/html/fluid-dev/2012-03/msg00033.html

I already added to XCode target "standalone plugin" a "copy files" build phase, which copies the following into Frameworks:

```
/usr/local/Cellar/glib/2.54.3/lib/libglib-2.0.0.dylib
/usr/local/opt/glib/lib/libgthread-2.0.0.dylib
/usr/local/opt/pcre/lib/libpcre.1.dylib
/usr/local/opt/gettext/lib/libintl.8.dylib
/usr/local/Cellar/fluid-synth/1.1.10/lib/libfluidsynth.1.7.1.dylib
```

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