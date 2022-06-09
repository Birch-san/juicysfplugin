#!/usr/bin/env bash

TARGET_OS="$1"
ARCH="$2"

declare -A win32_TOOLCHAINS=( [x64]=x86_64 [x86]=i686 [arm64]=aarch64 )
declare -A linux_TOOLCHAINS=( [x64]=amd64 [x86]=i386 [arm64]=arm64 )
declare -A win32_REPOS=( [x64]=clang64 [x86]=clang32 [arm64]=clangarm64 )
declare -A linux_REPOS=( [x64]=x86_64 [x86]=i386 [arm64]=aarch64 )
# for some reason the llvm-mingw toolchain gets the linker right by default
# so no override needed; we can leave it OFF on win32
declare -A LLVM_ENABLE_LLD=( [win32]=OFF [linux]=ON )
# turning off Jack because it didn't solve the "no audio output devices detected"
# and because there's no static distribution on apt
declare -A USE_JACK=( [win32]=OFF [linux]=OFF )

# TODO: set back to Release
CMAKE_BUILD_TYPE=Debug

TEST_DIR=/VST2_SDK/pluginterfaces
if [ -d "$TEST_DIR" ]; then
  echo "$TEST_DIR found; enabling VST2 build"
  VST2_OPTION='-DVST2_SDK_PATH=/VST2_SDK'
else
  echo "$TEST_DIR not found found; disabling VST2 build"
  VST2_OPTION=''
fi

# builds lib paths such as the following:
# /clang64/lib
# /usr/lib/x86_64-linux-gnu
resolve_lib_install_path () {
  local TARGET_OS="$1"
  local ARCH="$2"
  local REPO_ARCH="${TARGET_OS}_REPOS[$ARCH]"
  local REPO="${!REPO_ARCH}"
  case $TARGET_OS in
    win32)
      echo "/$REPO/lib"
      ;;

    linux)
      echo "/usr/lib/$REPO-linux-gnu"
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

# builds PKG_CONFIG_PATHs such as the following:
# /clang64/lib/pkgconfig
# /usr/lib/x86_64-linux-gnu/pkgconfig
resolve_pkg_config_path () {
  local LIB_INSTALL_PATH="$1"
  echo "$LIB_INSTALL_PATH/pkgconfig"
}

resolve_toolchain_lib_dir () {
  local TARGET_OS="$1"
  local TOOLCHAIN_ARCH="$2"
  case $TARGET_OS in
    win32)
      echo "/opt/llvm-mingw/${TOOLCHAIN_ARCH}-w64-mingw32/lib"
      ;;

    linux)
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

resolve_linker_flags () {
  local TARGET_OS="$1"
  local LIB_INSTALL_PATH="$2"
  local TOOLCHAIN_LIB_DIR="$3"
  case $TARGET_OS in
    win32)
      # we don't have pkg-config files for system libraries (e.g. libintl),
      # so pkg-config doesn't know that it depends on libiconv.
      # hence we introduce libiconv via CMAKE_EXE_LINKER_FLAGS.
      # the advice in pkg-config "libs other" (to provide -pthread flag to linker)
      # ends up dynamically linking it, even if we preface with -Wl,Bstatic
      # so I've told CMakeFiles not to use the "libs other" advice.
      # consequentially it's up to us to link in a suitable pthread archive via CMAKE_EXE_LINKER_FLAGS
      echo "/$LIB_INSTALL_PATH/libiconv.a $TOOLCHAIN_LIB_DIR/libwinpthread.a"
      ;;

    linux)
      echo "-fuse-ld=lld"
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

resolve_cxx_flags_option () {
  local TARGET_OS="$1"
  case $TARGET_OS in
    win32)
      # https://github.com/juce-framework/JUCE/issues/1028
      # For correct compilation of juce_gui_basics module on LLVM 14.0.0RC1's Clang,
      # we undefine any MinGW macros which would clash with
      # the constants which JUCE defines in juce_win32_ComInterfaces.h:
      # https://github.com/juce-framework/JUCE/blob/53b04877c6ebc7ef3cb42e84cb11a48e0cf809b5/modules/juce_gui_basics/native/accessibility/juce_win32_ComInterfaces.h#L123-L174
      # https://github.com/mingw-w64/mingw-w64/blob/2f6d8b806107cc8d543de2c9415a328a780a8267/mingw-w64-headers/include/uiautomationclient.h#L34-L450
      # unfortunately juce_win32_ComInterfaces.h isn't a complete list, so we have to define any constant that's absent

      # declare UIA constants that JUCE relies on but which are missing from juce_win32_ComInterfaces.h
      local -A UIA_CONSTS=(
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

      local UIA_DEFINES=()
      for UIA_CONST in "${!UIA_CONSTS[@]}"; do
        UIA_DEFINES+=(
          "-D${UIA_CONST}=\"(${UIA_CONSTS[$UIA_CONST]})\""
        )
      done
      local CMAKE_CXX_FLAGS=(
        "-D__UIAutomationClient_LIBRARY_DEFINED__"
        "${UIA_DEFINES[@]}"
      )
      if [ "$CMAKE_BUILD_TYPE" == 'Debug' ]; then
        # JUCE doesn't have extensive support for win32 aarch64
        # so juce_PlatformDefs.h implements debug breakpoints
        # with a non-clang-compatible style of ASM expression.
        # if we're building Debug, it's only because we want the
        # build to go faster (than Release)
        # so we can tolerate having breakpoints and assertions not work.

        # actually nevermind; my JUCE branch patches juce_PlatformDefs.h
        # to fix this properly
        # CMAKE_CXX_FLAGS+=('-DJUCE_NO_INLINE_ASM')
      fi
      echo "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS[*]}"
      ;;

    linux)
      local DPKG_ARCH="${linux_TOOLCHAINS[$ARCH]}"
      local LINUX_ARCH="${linux_REPOS[$ARCH]}"
      if [ "$(dpkg --print-architecture)" != "$DPKG_ARCH" ]; then
        local TARGET_TRIPLE="$LINUX_ARCH-linux-gnu"
        local CMAKE_CXX_FLAGS=(
          "--target=$TARGET_TRIPLE"
        )
        echo "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS[*]}"
      fi
      ;;
    *)
      >&2 echo "Unsupported TARGET_OS '$TARGET_OS'"
      exit 1
  esac
}

echo "arch: $ARCH"

REPO="${REPOS[$ARCH]}"
echo "repo: $REPO"

TOOLCHAIN_ARCH_VAR="${TARGET_OS}_TOOLCHAINS[$ARCH]"
TOOLCHAIN_ARCH="${!TOOLCHAIN_ARCH_VAR}"
echo "toolchain arch: $TOOLCHAIN_ARCH"
TOOLCHAIN_FILE="/${TARGET_OS}_${TOOLCHAIN_ARCH}_toolchain.cmake"
echo "toolchain file: $TOOLCHAIN_FILE"

TOOLCHAIN_LIB_DIR="$(resolve_toolchain_lib_dir "$TARGET_OS" "$TOOLCHAIN_ARCH")"
echo "toolchain lib dir: $TOOLCHAIN_LIB_DIR"

BUILD="build_${TARGET_OS}_${ARCH}"

LIB_INSTALL_PATH="$(resolve_lib_install_path "$TARGET_OS" "$ARCH")"
echo "LIB_INSTALL_PATH: $LIB_INSTALL_PATH"

PKG_CONFIG_PATH="$(resolve_pkg_config_path "$LIB_INSTALL_PATH")"
echo "PKG_CONFIG_PATH: $PKG_CONFIG_PATH"

LINKER_FLAGS="$(resolve_linker_flags "$TARGET_OS" "$LIB_INSTALL_PATH" "$TOOLCHAIN_LIB_DIR")"

CMAKE_CXX_FLAGS_OPTION="$(resolve_cxx_flags_option "$TARGET_OS")"

# MODULE_LINKER flags are for the VST2/VST3 modules (they don't listen to the EXE_LINKER flags)
VERBOSE=1 PKG_CONFIG_PATH="$PKG_CONFIG_PATH" cmake -B"$BUILD" \
-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
-DCMAKE_PREFIX_PATH="/linux_native" \
-DCMAKE_EXE_LINKER_FLAGS="$LINKER_FLAGS" \
-DCMAKE_MODULE_LINKER_FLAGS="$LINKER_FLAGS" \
"$VST2_OPTION" \
-DLLVM_ENABLE_LLD="${LLVM_ENABLE_LLD[$TARGET_OS]}" \
-DUSE_JACK="${USE_JACK[$TARGET_OS]}" \
-DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
"$CMAKE_CXX_FLAGS_OPTION" \
-DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE"