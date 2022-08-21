# cmake -B build -DCMAKE_INSTALL_PREFIX="$HOME/juicydeps" -DCMAKE_BUILD_TYPE=Debug
# cmake --build build

# To get started on a new plugin, copy this entire folder (containing this file and C++ sources) to
# a convenient location, and then start making modifications.

# The first line of any CMake project should be a call to `cmake_minimum_required`, which checks
# that the installed CMake will be able to understand the following CMakeLists, and ensures that
# CMake's behaviour is compatible with the named version. This is a standard CMake command, so more
# information can be found in the CMake docs.

cmake_minimum_required(VERSION 3.15)

# The top-level CMakeLists.txt file for a project must contain a literal, direct call to the
# `project()` command. `project()` sets up some helpful variables that describe source/binary
# directories, and the current project version. This is a standard CMake command.

project(JUICY_SF_PLUGIN VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If you've installed JUCE somehow (via a package manager, or directly using the CMake install
# target), you'll need to tell this project that it depends on the installed copy of JUCE. If you've
# included JUCE directly in your source tree (perhaps as a submodule), you'll need to tell CMake to
# include that subdirectory as part of the build.

# find_package(JUCE CONFIG REQUIRED)        # If you've installed JUCE to your system
# or
add_subdirectory(JUCE)                    # If you've put JUCE in a subdirectory called JUCE
add_subdirectory(fluidsynth)

# default to static libraries, since distribution is easier
option(BUILD_SHARED_LIBS "Build using shared libraries" off)
set(VST2_SDK_PATH "" CACHE STRING "VST2 SDK path")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(PkgConfig REQUIRED)

if (BUILD_SHARED_LIBS)
  set(TARGET_STATIC_QUALIFIER "")
else (BUILD_SHARED_LIBS)
  set(TARGET_STATIC_QUALIFIER "-static")
  set(PACKAGE_STATIC_QUALIFIER "_STATIC")
endif (BUILD_SHARED_LIBS)

set(PKG_CONFIG_USE_CMAKE_PREFIX_PATH off)
pkg_search_module(FLUIDSYNTH REQUIRED IMPORTED_TARGET fluidsynth>=2)
set(FLUIDSYNTH_TARGET "PkgConfig::FLUIDSYNTH${TARGET_STATIC_QUALIFIER}")

if (EXTRA_ARCH_PKG_CONFIG_PATH)
  set(ENV{PKG_CONFIG_PATH} "${EXTRA_ARCH_PKG_CONFIG_PATH}")
  pkg_search_module(EXTRA_ARCH_FLUIDSYNTH REQUIRED IMPORTED_TARGET fluidsynth>=2)
  set(EXTRA_ARCH_FLUIDSYNTH_TARGET "PkgConfig::EXTRA_ARCH_FLUIDSYNTH${TARGET_STATIC_QUALIFIER}")
endif (EXTRA_ARCH_PKG_CONFIG_PATH)

set(VST_COPY_DIR "${JUCE_VST_COPY_DIR}" CACHE STRING "VST2 installation dir")
set(VST3_COPY_DIR "${JUCE_VST3_COPY_DIR}" CACHE STRING "VST3 installation dir")
set(AU_COPY_DIR "${JUCE_AU_COPY_DIR}" CACHE STRING "AU installation dir")

# If you are building a VST2 or AAX plugin, CMake needs to be told where to find these SDKs on your
# system. This setup should be done before calling `juce_add_plugin`.

if (VST2_SDK_PATH)
  set(HAS_VST2_SDK_PATH 1)
  set(VST2_FORMAT "VST")
  juce_set_vst2_sdk_path(${VST2_SDK_PATH})
else (VST2_SDK_PATH)
  set(HAS_VST2_SDK_PATH 0)
endif (VST2_SDK_PATH)

if (VST3_SDK_PATH)
  juce_set_vst3_sdk_path(${VST3_SDK_PATH})
endif (VST3_SDK_PATH)

# juce_set_aax_sdk_path(...)

# `juce_add_plugin` adds a static library target with the name passed as the first argument
# (AudioPluginExample here). This target is a normal CMake target, but has a lot of extra properties set
# up by default. As well as this shared code static library, this function adds targets for each of
# the formats specified by the FORMATS arguments. This function accepts many optional arguments.
# Check the readme at `docs/CMake API.md` in the JUCE repo for the full list.

# building of AUv3 requires -DCMAKE_GENERATOR=Xcode or -GXcode
# and your "XCode > Preferences > Locations > Command Line Tools" set to "XCode"
# otherwise you'll get error:
# Run Build Command(s):/usr/bin/xcodebuild -project CMAKE_TRY_COMPILE.xcodeproj build -target cmTC_33f26 -parallelizeTargets -configuration Debug -hideShellScriptEnvironment && xcode-select: error: tool 'xcodebuild' requires Xcode, but active developer directory '/Library/Developer/CommandLineTools' is a command line tools instance

# https://github.com/juce-framework/JUCE/blob/master/docs/CMake%20API.md
juce_add_plugin(JuicySFPlugin
    # VERSION ...                               # Set this if the plugin version is different to the project version
    ICON_BIG resources/Logo512.png                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
    COMPANY_NAME Birchlabs                          # Specify the name of the plugin's author
    COMPANY_WEBSITE "https://birchlabs.co.uk"
    DESCRIPTION "Audio plugin to play soundfonts"
    IS_SYNTH TRUE                       # Is this a synth or an effect?
    NEEDS_MIDI_INPUT TRUE               # Does the plugin need midi input?
    NEEDS_MIDI_OUTPUT FALSE              # Does the plugin need midi output?
    IS_MIDI_EFFECT FALSE                 # Is this plugin a MIDI effect?
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE    # Does the editor need keyboard focus?
    COPY_PLUGIN_AFTER_BUILD TRUE        # Should the plugin be installed to a default location after building?
    APP_SANDBOX_ENABLED TRUE
    APP_SANDBOX_OPTIONS com.apple.security.files.user-selected.read-only
    HARDENED_RUNTIME_ENABLED TRUE
    VST2_CATEGORY kPlugCategSynth
    VST3_CATEGORIES Instrument Synth
    AU_MAIN_TYPE kAudioUnitType_MusicDevice
    AU_SANDBOX_SAFE TRUE
    PLUGIN_MANUFACTURER_CODE Blbs               # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE Jsfp                            # A unique four-character plugin id with exactly one upper-case character
                                                # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS AU AUv3 ${VST2_FORMAT} VST3 Standalone                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    VST_COPY_DIR "${VST_COPY_DIR}"
    VST3_COPY_DIR "${VST3_COPY_DIR}"
    AU_COPY_DIR "${AU_COPY_DIR}"
    PRODUCT_NAME "juicysfplugin")        # The name of the final executable, which can differ from the target name

# https://cmake.org/cmake/help/latest/guide/tutorial/Selecting%20Static%20or%20Shared%20Libraries.html
set_target_properties(JuicySFPlugin PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})

# `juce_generate_juce_header` will create a JuceHeader.h for a given target, which will be generated
# into your build tree. This should be included with `#include <JuceHeader.h>`. The include path for
# this header will be automatically added to the target. The main function of the JuceHeader is to
# include all your JUCE module headers; if you're happy to include module headers directly, you
# probably don't need to call this.

# juce_generate_juce_header(JuicySFPlugin)

# `target_sources` adds source files to a target. We pass the target that needs the sources as the
# first argument, then a visibility parameter for the sources which should normally be PRIVATE.
# Finally, we supply a list of source files that will be built into the target. This is a standard
# CMake command.

add_subdirectory(Source)

# `target_compile_definitions` adds some preprocessor definitions to our target. In a Projucer
# project, these might be passed in the 'Preprocessor Definitions' field. JUCE modules also make use
# of compile definitions to switch certain features on/off, so if there's a particular feature you
# need that's not on by default, check the module header for the correct flag to set here. These
# definitions will be visible both to your code, and also the JUCE module code, so for new
# definitions, pick unique names that are unlikely to collide! This is a standard CMake command.

target_compile_definitions(JuicySFPlugin
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        # JUCE_CORE_INCLUDE_OBJC_HELPERS=1
        DONT_SET_USING_JUCE_NAMESPACE=1
        JUCE_VST3_CAN_REPLACE_VST2=${HAS_VST2_SDK_PATH})

# If your target needs extra binary assets, you can add them here. The first argument is the name of
# a new static library target that will include all the binary resources. There is an optional
# `NAMESPACE` argument that can specify the namespace of the generated binary data class. Finally,
# the SOURCES argument should be followed by a list of source files that should be built into the
# static library. These source files can be of any kind (wav data, images, fonts, icons etc.).
# Conversion to binary-data will happen when your target is built.

# juce_add_binary_data(AudioPluginData SOURCES ...)

# `target_link_libraries` links libraries and JUCE modules to other libraries or executables. Here,
# we're linking our executable target to the `juce::juce_audio_utils` module. Inter-module
# dependencies are resolved automatically, so `juce_core`, `juce_events` and so on will also be
# linked automatically. If we'd generated a binary data target above, we would need to link to it
# here too. This is a standard CMake command.

target_link_libraries(JuicySFPlugin
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        ${FLUIDSYNTH_TARGET}
        ${EXTRA_ARCH_FLUIDSYNTH_TARGET}
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

# Apple clang doesn't support -static-libgcc flag, but seems to make a portable binary regardless
if (NOT BUILD_SHARED_LIBS AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ${CMAKE_EXE_LINKER_FLAGS}")
  # the VST2 and VST3 distributions are "modules", so they don't listen to the EXE_LINKER flags
  set(CMAKE_MODULE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ${CMAKE_MODULE_LINKER_FLAGS}")
endif (NOT BUILD_SHARED_LIBS AND CMAKE_SYSTEM_NAME STREQUAL "Windows")