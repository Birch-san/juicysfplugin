A lot of thrashing was involved.

So first I'll list the steps that I _know_ are necessary.  
Then after that I'll list the steps which were probably unnecessary.

# Definitely necessary

## Install Visual Studio Community:

https://www.visualstudio.com/

## Install [VST3 Audio Plug-Ins SDK](https://www.steinberg.net/en/company/developers.html)

Such that this folder exists:

```
C:\SDKs\VST_SDK\VST3_SDK
```

## Install JUCE framework

https://shop.juce.com/get-juce

JUCE should be installed to `C:\Juce`

_Note: the only thing we actually need from here is `C:\Juce\modules`. I've copied that into the repository now, so soon I'll be able to make that step skippable._

## That's all. Probably.

Well, unless you're also interested in the Setup project:

## Configure "Setup" project

This is project constructs a .exe and .msi installer (i.e. for distributing the synth).

### Install support for Visual Studio Setup projects

https://marketplace.visualstudio.com/items?itemName=VisualStudioProductTeam.MicrosoftVisualStudio2017InstallerProjects

### Fix unrecoverable build error

Register MergeMod.dll

https://stackoverflow.com/questions/42624572/unrecoverable-build-error-whilst-trying-to-build-setup-on-vs2015

If you encounter "Unrecoverable build error" when building juicysfplugin's setup.exe installer, you need to open an administrator prompt and register MergeMod.dll:

```bash
regsvr32 "C:\Program Files (x86)\Common Files\Microsoft Shared\MSI Tools\MergeMod.dll"
```

You may also need to run Visual Studio as Adminstrator.

# Necessary for changing the dependencies

If you want to build against a newer version of fluidsynth, you'll need libfluidsynth.dll and friends.

The way I originally got these was from MSYS2's MinGW repository.

## Install msys2 toolchain (x86_64):

http://www.msys2.org/

> MSYS2 is a software distro and building platform for Windows
> an independent rewrite of MSYS, based on modern Cygwin (POSIX compatibility layer) and MinGW-w64
> provides a bash shell, Autotools, revision control systems and the like for building native Windows applications using MinGW-w64 toolchains
> features a package management system to provide easy installation of packages, Pacman

## Grab latest package definitions:

Press the Start key to search for and launch an MSYS2 command prompt. Named `MSYS2 MinGW 64-bit`.

```
pacman -Syu
```

It may ask you to close the terminal and run update one more time:

```
pacman -Su
```

## Install libfluidsynth.dll:

https://github.com/Alexpux/MINGW-packages/blob/master/mingw-w64-fluidsynth/PKGBUILD

```
pacman -S --needed mingw64/mingw-w64-x86_64-fluidsynth
```

## Learn about how to make changes to PKGBUILD

If you want to change compile flags on the [fluidsynth package](https://github.com/Alexpux/MINGW-packages/blob/master/mingw-w64-fluidsynth/PKGBUILD), you'll need to clone the MINGW-packages repository, edit `mingw-w64-fluidsynth/PKGBUILD`, and build with `makepkg-mingw -sCLf`.

https://github.com/msys2/msys2/wiki/Creating-Packages#re-building-a-package

```bash
git clone "https://github.com/Alexpux/MINGW-packages"
cd MINGW-packages/mingw-w64-fluidsynth
makepkg-mingw -sCLf
pacman -U mingw-w64-*-fluidsynth-*-any.pkg.tar.xz
```

## Learn about dynamic linking

You can use `ldd` to check where a dll looks for its dependencies:

```
$ ldd /mingw64/bin/libfluidsynth-1.dll
        libsndfile-1.dll => /mingw64/bin/libsndfile-1.dll (0x70440000)
        …
```

Side-note: [fuslogvw](https://docs.microsoft.com/en-us/dotnet/framework/tools/fuslogvw-exe-assembly-binding-log-viewer) helps you debug .NET's run-time linker. Not relevant to juicysfplugin (because it's not managed code), but it's a useful tool for Windows developers to know about.

# Prefer CLion?

We don't have Windows support in our CMake project (I could add it by using Projucer to generate a CODE::Blocks exporter, but I don't want to maintain that).

Anyway, here's my notes.

## Install CLion

https://www.jetbrains.com/clion/nextversion/

## Install MinGW toolchain

Required for CLion integration.

https://stackoverflow.com/questions/36375081/how-to-run-clion-with-msys2-on-windows

You don't need all the packages here (like Ada, Fortran, Objective-C...), but space is cheap so just install all.

```bash
pacman -S --needed mingw-w64-x86_64-toolchain
```

## Configure CLion

Add MinGW Toolchain:

```
C:\msys64\mingw64
```

# Want to use Visual Studio upon a CMake project?

We don't have Windows support in our CMake project (see "Prefer CLion?" section for brief explanation), but I wrote some notes on this whilst I was thrashing around.

## Configure Visual Studio build environment

https://trac.ffmpeg.org/wiki/CompilationGuide/MSVC#Settingtheenvironment

Sets source and target architecture to x64:

```cmd
"C:\Program Files (x86)\Microsoft Visual Studio\Preview\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
```

## Configure MSYS2 environment

Press the Start key to search for and launch an MSYS2 command prompt. Named `MSYS2 MinGW 64-bit`.

Ensure that on MSYS2's path, Visual Studio's cl and link programs have the highest precedence:

```bash
echo 'export PATH="/c/Program Files (x86)/Microsoft Visual Studio/Preview/Community/VC/Tools/MSVC/14.14.26428/bin/Hostx64/x64/:$PATH"' >> ~/.bashrc
```

Ensure that any libs or headers you wish to include are added to the path:

```bash
echo 'export LIB="EXAMPLE:$LIB"' >> ~/.bashrc
echo 'export INCLUDE="EXAMPLE:$INCLUDE"' >> ~/.bashrc
```

## Install LLVM

I can't remember why, since this seems to be switching to a different toolchain or compiler altogether.  
Maybe it was an alternative approach.

https://releases.llvm.org/download.html

# Glossary

https://github.com/msys2/msys2/wiki/How-does-MSYS2-differ-from-Cygwin

```
Cygwin: Gives you application support for POSIX compatible API, build and run environment. Useful when you have a native POSIX application you want to compile and run on a windows box.

MSYS2: API's and build environment. This is useful when you have something like a library you want to use that requires autotools or has a complicated build system.

MinGW: POSIX API. Useful if you want to compile, or especially cross compile using gcc, use POSIX api's and have access to unix command line tools.
```