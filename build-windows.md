Glossary:

https://github.com/msys2/msys2/wiki/How-does-MSYS2-differ-from-Cygwin

```
Cygwin: Gives you application support for POSIX compatible API, build and run environment. Useful when you have a native POSIX application you want to compile and run on a windows box.

MSYS2: API's and build environment. This is useful when you have something like a library you want to use that requires autotools or has a complicated build system.

MinGW: POSIX API. Useful if you want to compile, or especially cross compile using gcc, use POSIX api's and have access to unix command line tools.
```


1) Install Visual Studio Community:

https://www.visualstudio.com/

2) Configure Visual Studio build environment

https://trac.ffmpeg.org/wiki/CompilationGuide/MSVC#Settingtheenvironment

Sets source and target architecture to x64:

```cmd
"C:\Program Files (x86)\Microsoft Visual Studio\Preview\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
```

3) Clone [fluidsynth](https://github.com/FluidSynth/fluidsynth) repository:

```bash
git clone git@github.com:FluidSynth/fluidsynth.git
```

4) Install msys2 toolchain:

http://www.msys2.org/

> MSYS2 is a software distro and building platform for Windows
> an independent rewrite of MSYS, based on modern Cygwin (POSIX compatibility layer) and MinGW-w64
> provides a bash shell, Autotools, revision control systems and the like for building native Windows applications using MinGW-w64 toolchains
> features a package management system to provide easy installation of packages, Pacman

5) Grab latest package definitions:

Press the Start key to search for and launch an MSYS2 command prompt. Named `MSYS2 MinGW 64-bit`.

```
pacman -Syu
```

It may ask you to close the terminal and run update one more time:

```
pacman -Su
```

6) install libfluidsynth.dll:

https://github.com/Alexpux/MINGW-packages/blob/master/mingw-w64-fluidsynth/PKGBUILD

```
pacman -S --needed mingw64/mingw-w64-x86_64-fluidsynth
```

```
$ pacman -S --needed mingw64/mingw-w64-x86_64-fluidsynth
resolving dependencies...
looking for conflicting packages...

Packages (36) mingw-w64-x86_64-bzip2-1.0.6-6  mingw-w64-x86_64-ca-certificates-20170211-2
              mingw-w64-x86_64-expat-2.2.5-1  mingw-w64-x86_64-flac-1.3.2-1  mingw-w64-x86_64-gcc-libs-7.3.0-2
              mingw-w64-x86_64-gettext-0.19.8.1-4  mingw-w64-x86_64-glib2-2.56.1-2  mingw-w64-x86_64-gmp-6.1.2-1
              mingw-w64-x86_64-libffi-3.2.1-4  mingw-w64-x86_64-libiconv-1.15-3  mingw-w64-x86_64-libogg-1.3.3-1
              mingw-w64-x86_64-libsndfile-1.0.28-1  mingw-w64-x86_64-libsystre-1.0.1-4  mingw-w64-x86_64-libtasn1-4.13-1
              mingw-w64-x86_64-libtre-git-r128.6fb7206-2  mingw-w64-x86_64-libvorbis-1.3.6-1
              mingw-w64-x86_64-libwinpthread-git-6.0.0.5134.2416de71-1  mingw-w64-x86_64-mpc-1.1.0-1
              mingw-w64-x86_64-mpfr-4.0.1-1  mingw-w64-x86_64-ncurses-6.1.20180526-1  mingw-w64-x86_64-openssl-1.0.2.o-1
              mingw-w64-x86_64-p11-kit-0.23.12-1  mingw-w64-x86_64-pcre-8.42-1
              mingw-w64-x86_64-portaudio-190600_20161030-3  mingw-w64-x86_64-python3-3.6.5-1
              mingw-w64-x86_64-readline-7.0.005-1  mingw-w64-x86_64-speex-1.2.0-1  mingw-w64-x86_64-speexdsp-1.2rc3-3
              mingw-w64-x86_64-sqlite3-3.24.0-1  mingw-w64-x86_64-tcl-8.6.8-1  mingw-w64-x86_64-termcap-1.3.1-3
              mingw-w64-x86_64-tk-8.6.8-1  mingw-w64-x86_64-wineditline-2.205-1  mingw-w64-x86_64-xz-5.2.4-1
              mingw-w64-x86_64-zlib-1.2.11-1  mingw-w64-x86_64-fluidsynth-1.1.11-1

Total Download Size:    40.77 MiB
Total Installed Size:  254.59 MiB
```

```
alexb@DESKTOP-JE77PJ2 MSYS ~
$ ldd /mingw64/bin/libfluidsynth-1.dll
        ntdll.dll => /c/WINDOWS/SYSTEM32/ntdll.dll (0x7ffcc2030000)
        KERNEL32.DLL => /c/WINDOWS/System32/KERNEL32.DLL (0x7ffcc0ca0000)
        KERNELBASE.dll => /c/WINDOWS/System32/KERNELBASE.dll (0x7ffcbe740000)
        apphelp.dll => /c/WINDOWS/SYSTEM32/apphelp.dll (0x7ffcbc400000)
        msvcrt.dll => /c/WINDOWS/System32/msvcrt.dll (0x7ffcc0d60000)
        DSOUND.dll => /c/WINDOWS/SYSTEM32/DSOUND.dll (0x7ffc9ad20000)
        USER32.dll => /c/WINDOWS/System32/USER32.dll (0x7ffcc1590000)
        win32u.dll => /c/WINDOWS/System32/win32u.dll (0x7ffcbe9c0000)
        advapi32.dll => /c/WINDOWS/System32/advapi32.dll (0x7ffcc11e0000)
        GDI32.dll => /c/WINDOWS/System32/GDI32.dll (0x7ffcc1320000)
        sechost.dll => /c/WINDOWS/System32/sechost.dll (0x7ffcc1ea0000)
        RPCRT4.dll => /c/WINDOWS/System32/RPCRT4.dll (0x7ffcc1350000)
        gdi32full.dll => /c/WINDOWS/System32/gdi32full.dll (0x7ffcbf320000)
        msvcp_win.dll => /c/WINDOWS/System32/msvcp_win.dll (0x7ffcbe9e0000)
        ucrtbase.dll => /c/WINDOWS/System32/ucrtbase.dll (0x7ffcbe640000)
        powrprof.dll => /c/WINDOWS/System32/powrprof.dll (0x7ffcbe390000)
        combase.dll => /c/WINDOWS/System32/combase.dll (0x7ffcc1720000)
        WS2_32.dll => /c/WINDOWS/System32/WS2_32.dll (0x7ffcc0c30000)
        WINMM.dll => /c/WINDOWS/SYSTEM32/WINMM.dll (0x7ffcbc1c0000)
        libglib-2.0-0.dll => /mingw64/bin/libglib-2.0-0.dll (0x685c0000)
        libportaudio-2.dll => /mingw64/bin/libportaudio-2.dll (0x632c0000)
        ole32.dll => /c/WINDOWS/System32/ole32.dll (0x7ffcbf690000)
        ??? => ??? (0xdd0000)
        libreadline7.dll => /mingw64/bin/libreadline7.dll (0x6e780000)
        SETUPAPI.dll => /c/WINDOWS/System32/SETUPAPI.dll (0x7ffcc1a50000)
        SHELL32.dll => /c/WINDOWS/System32/SHELL32.dll (0x7ffcbf7f0000)
        cfgmgr32.dll => /c/WINDOWS/System32/cfgmgr32.dll (0x7ffcbe5f0000)
        libsndfile-1.dll => /mingw64/bin/libsndfile-1.dll (0x70440000)
        shcore.dll => /c/WINDOWS/System32/shcore.dll (0x7ffcbf560000)
        winmmbase.dll => /c/WINDOWS/SYSTEM32/winmmbase.dll (0x7ffcbbd70000)
        ??? => ??? (0x140000)
        windows.storage.dll => /c/WINDOWS/System32/windows.storage.dll (0x7ffcbec10000)
        libtermcap-0.dll => /mingw64/bin/libtermcap-0.dll (0x6ac40000)
        shlwapi.dll => /c/WINDOWS/System32/shlwapi.dll (0x7ffcc1180000)
        libwinpthread-1.dll => /mingw64/bin/libwinpthread-1.dll (0x64940000)
        kernel.appcore.dll => /c/WINDOWS/System32/kernel.appcore.dll (0x7ffcbe370000)
        libFLAC-8.dll => /mingw64/bin/libFLAC-8.dll (0x64080000)
        libogg-0.dll => /mingw64/bin/libogg-0.dll (0x70680000)
        profapi.dll => /c/WINDOWS/System32/profapi.dll (0x7ffcbe3e0000)
        bcryptPrimitives.dll => /c/WINDOWS/System32/bcryptPrimitives.dll (0x7ffcbeb30000)
        libspeex-1.dll => /mingw64/bin/libspeex-1.dll (0x69580000)
        libvorbis-0.dll => /mingw64/bin/libvorbis-0.dll (0x6d540000)
        FLTLIB.DLL => /c/WINDOWS/System32/FLTLIB.DLL (0x7ffcbe360000)
        libvorbisenc-2.dll => /mingw64/bin/libvorbisenc-2.dll (0x6b680000)
        libintl-8.dll => /mingw64/bin/libintl-8.dll (0x61cc0000)
        libpcre-1.dll => /mingw64/bin/libpcre-1.dll (0x69140000)
        libiconv-2.dll => /mingw64/bin/libiconv-2.dll (0x66000000)
        IMM32.DLL => /c/WINDOWS/System32/IMM32.DLL (0x7ffcc1560000)
```

6) Install CLion

https://www.jetbrains.com/clion/nextversion/

6) Install MinGW toolchain

Required for CLion integration.

https://stackoverflow.com/questions/36375081/how-to-run-clion-with-msys2-on-windows

You don't need all the packages here (like Ada, Fortran, Objective-C...), but space is cheap so just install all.

```bash
pacman -S --needed mingw-w64-x86_64-toolchain
```

7) Configure CLion

Add MinGW Toolchain:

```
C:\msys64\mingw64
```

8) Install [VST3 Audio Plug-Ins SDK](https://www.steinberg.net/en/company/developers.html)

Such that this folder exists:

```
C:\SDKs\VST_SDK\VST3_SDK
```

9) Install JUCE and Projucer

https://shop.juce.com/get-juce

JUCE should be installed to C:\\Juce

10) With Projucer, open juicysfplugin/juicysfplugin.jucer



5.onsecondthoughtsdon't) Configure MSYS2 environment

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