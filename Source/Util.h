#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef DEBUG_PRINT
  #if JUCE_DEBUG
    #define DEBUG_PRINT(str) Logger::outputDebugString(str)
  #else
    #define DEBUG_PRINT(str)
  #endif
#endif

namespace Util {
  inline int compare(int a, int b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
  }
}