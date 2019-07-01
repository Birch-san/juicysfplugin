#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef DEBUG_PRINT
  #if JUCE_DEBUG
    #define DEBUG_PRINT(str) Logger::outputDebugString(str)
  #else
    #define DEBUG_PRINT(str)
  #endif
#endif
