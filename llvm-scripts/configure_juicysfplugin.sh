#!/usr/bin/env bash

if test -n "$1"; then
  declare -a ARCHS=("$1")
else
  declare -a ARCHS=("x64" "x86" "arm64")
fi

declare -A TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )

# declare UIA constants that JUCE relies on but which are missing from juce_win32_ComInterfaces.h
declare -A UIA_CONSTS=(
  [UIA_NamePropertyId]=30005
  [UIA_ValueValuePropertyId]=30045
  [UIA_RangeValueValuePropertyId]=30047
  [UIA_ToggleToggleStatePropertyId]=30086
  [UIA_AutomationIdPropertyId]=30011
  [UIA_ControlTypePropertyId]=30003
  [UIA_FrameworkIdPropertyId]=30024
  [UIA_FullDescriptionPropertyId]=30159
  [UIA_HelpTextPropertyId]=30013
  [UIA_IsContentElementPropertyId]=30017
  [UIA_IsControlElementPropertyId]=30016
  [UIA_IsDialogPropertyId]=30174
  [UIA_IsEnabledPropertyId]=30010
  [UIA_IsKeyboardFocusablePropertyId]=30009
  [UIA_HasKeyboardFocusPropertyId]=30008
  [UIA_IsOffscreenPropertyId]=30022
  [UIA_IsPasswordPropertyId]=30019
  [UIA_ProcessIdPropertyId]=30002
  [UIA_NativeWindowHandlePropertyId]=30020
)

UIA_DEFINES=''
for UIA_CONST in "${!UIA_CONSTS[@]}"
do
  UIA_DEFINES="$UIA_DEFINES -D${UIA_CONST}=\"(${UIA_CONSTS[$UIA_CONST]})\""
done

TEST_DIR=/VST2_SDK/pluginterfaces
if [ -d "$TEST_DIR" ]; then
  echo "$TEST_DIR found; enabling VST2 build"
  VST2_OPTION='-DVST2_SDK_PATH=/VST2_SDK'
else
  echo "$TEST_DIR not found found; disabling VST2 build"
  VST2_OPTION=''
fi
 
for ARCH in ${ARCHS[@]}; do
  echo "arch: $ARCH"

  REPO="${REPOS[$ARCH]}"
  echo "repo: $REPO"

  TOOLCHAIN="${TOOLCHAINS[$ARCH]}"
  echo "toolchain: $TOOLCHAIN"
  TOOLCHAIN_FILE="/win32_${TOOLCHAIN}_toolchain.cmake"
  echo "toolchain file: $TOOLCHAIN_FILE"
  TOOLCHAIN_LIB_DIR="/opt/llvm-mingw/${TOOLCHAIN}-w64-mingw32/lib"
  echo "toolchain lib dir: $TOOLCHAIN_LIB_DIR"

  BUILD="build_$ARCH"

  # we don't have pkg-config files for system libraries (e.g. libintl),
  # so pkg-config doesn't know that it depends on libiconv.
  # hence we introduce libiconv via CMAKE_EXE_LINKER_FLAGS.

  # the advice in pkg-config "libs other" (to provide -pthread flag to linker)
  # ends up dynamically linking it, even if we preface with -Wl,Bstatic
  # so I've told CMakeFiles not to use the "libs other" advice.
  # consequentially it's up to us to link in a suitable pthread archive via CMAKE_EXE_LINKER_FLAGS
  LINKER_FLAGS="/$REPO/lib/libiconv.a $TOOLCHAIN_LIB_DIR/libwinpthread.a"

  # For correct compilation of juce_gui_basics module on LLVM 14.0.0RC1's Clang,
  # we undefine any MinGW macros which would clash with
  # the constants which JUCE defines in juce_win32_ComInterfaces.h:
  # https://github.com/juce-framework/JUCE/blob/53b04877c6ebc7ef3cb42e84cb11a48e0cf809b5/modules/juce_gui_basics/native/accessibility/juce_win32_ComInterfaces.h#L123-L174
  # https://github.com/mingw-w64/mingw-w64/blob/2f6d8b806107cc8d543de2c9415a328a780a8267/mingw-w64-headers/include/uiautomationclient.h#L34-L450
  # unfortunately juce_win32_ComInterfaces.h isn't a complete list, so we have to define any constant that's absent
  CMAKE_CXX_FLAGS="-D__UIAutomationClient_LIBRARY_DEFINED__ $UIA_DEFINES"

  # MODULE_LINKER flags are for the VST2/VST3 modules (they don't listen to the EXE_LINKER flags)
  VERBOSE=1 PKG_CONFIG_PATH="/$REPO/lib/pkgconfig" cmake -B"$BUILD" \
-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
-DCMAKE_PREFIX_PATH="/linux_native" \
-DCMAKE_EXE_LINKER_FLAGS="$LINKER_FLAGS" \
-DCMAKE_MODULE_LINKER_FLAGS="$LINKER_FLAGS" \
-DCMAKE_INSTALL_PREFIX="/$REPO" \
"$VST2_OPTION" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
-DCMAKE_CXX_FLAGS="$CMAKE_CXX_FLAGS" \
-DCMAKE_BUILD_TYPE=Release
done