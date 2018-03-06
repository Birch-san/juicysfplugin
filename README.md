# Making portable releases

Assuming your `juicysfplugin` repository lives in `~/git/juicysfplugin`, then by default it will be compiled will a dynamic link to the fluidsynth which brew installed into `/usr/local/opt`:

```bash
otool -L /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin 
/Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin:
	/usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib (compatibility version 1.0.0, current version 1.7.1)
```

We can rewrite this dynamic link like so:

```bash
install_name_tool -change /usr/local/opt/fluid-synth/lib/libfluidsynth.1.dylib @executable_path/../Frameworks/libfluidsynth.1.dylib /Users/birch/git/juicysfplugin/Builds/MacOSX/build/Release/juicysfplugin.app/Contents/MacOS/juicysfplugin
```