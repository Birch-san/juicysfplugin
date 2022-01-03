# https://github.com/RetroEvolved/zdoom/blob/master/FindFluidSynth.cmake
# - Find fluidsynth
# Find the native fluidsynth includes and library
#
#  FLUIDSYNTH_INCLUDE_DIR - where to find fluidsynth.h
#  FLUIDSYNTH_LIBRARIES   - List of libraries when using fluidsynth.
#  fluidsynth_FOUND       - True if fluidsynth found.


if (FLUIDSYNTH_INCLUDE_DIR AND FLUIDSYNTH_LIBRARIES)
  # Already in cache, be silent
  set(FLUIDSYNTH_FIND_QUIETLY TRUE)
endif (FLUIDSYNTH_INCLUDE_DIR AND FLUIDSYNTH_LIBRARIES)

find_path(FLUIDSYNTH_INCLUDE_DIR fluidsynth.h)

find_library(FLUIDSYNTH_LIBRARIES NAMES fluidsynth)
mark_as_advanced(FLUIDSYNTH_LIBRARIES FLUIDSYNTH_INCLUDE_DIR)

# handle the QUIETLY and REQUIRED arguments and set fluidsynth_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(fluidsynth DEFAULT_MSG FLUIDSYNTH_LIBRARIES FLUIDSYNTH_INCLUDE_DIR)

