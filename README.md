# Making portable releases

Assuming your `juicysfplugin` repository lives in `~/git/juicysfplugin`, then by default it will be compiled will a dynamic link to the fluidsynth which brew installed into `/usr/local/opt`:

```bash
otool -L /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin 
/Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin:
	/usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib (compatibility version 1.0.0, current version 1.7.1)
```

We can rewrite this dynamic link like so:

```bash
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib @executable_path/../Frameworks/libfluidsynth.1.7.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin
chmod +w /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/*
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib @loader_path/../Frameworks/libfluidsynth.1.7.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
install_name_tool -change /usr/local/opt/glib/lib/libglib-2.0.0.dylib @loader_path/../Frameworks/libglib-2.0.0.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/Frameworks/libfluidsynth.1.7.1.dylib
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

## `libintl` LGPL

https://www.gnu.org/software/gettext/manual/html_node/Licenses.html

> either version 2.1 of the License, or (at your option) any later version.

## `libglib` LGPL

> either version 2.1 of the License, or (at your option) any later version.

## `libgthread` LGPL

> either version 2.1 of the License, or (at your option) any later version.

## `libpcre` BSD

> Release 8 of PCRE is distributed under the terms of the "BSD" licence.

## `libfluidsynth` LGPL

https://github.com/FluidSynth/fluidsynth/blob/master/LICENSE

> (This is the first released version of the Lesser GPL.  It also counts as the successor of the GNU Library Public License, version 2, hence the version number 2.1.)

