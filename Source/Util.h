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
  inline String getHomeDirectory() {
    static String homeDirectory = []() -> String {
    #if JUCE_WINDOWS
      const char* homeDir = std::getenv("USERPROFILE");
    #else
      const char* homeDir = std::getenv("HOME");
    #endif
      return homeDir != nullptr ? String(homeDir) : String();
    }();

    return homeDirectory;
  }

  inline String getAbsolutePath(const String& relativePath) {
    String homeDir = getHomeDirectory();
    String normalizedRelativePath = relativePath.replace("~", homeDir);
    #if JUCE_WINDOWS
    #else
      normalizedRelativePath = normalizedRelativePath.replace("\\", "/");
    #endif
    File absoluteFile(normalizedRelativePath);
    return absoluteFile.getFullPathName();
  }

  inline String getRelativeToHomePath(const String& absolutePath) {
    String homeDir = getHomeDirectory();

    if (absolutePath.startsWith(homeDir)) {
      String resultPath = "~/" + absolutePath.substring(homeDir.length() + 1);
      #if JUCE_WINDOWS
        resultPath = resultPath.replace("\\", "/");
      #else
      #endif
      
      return resultPath;
    }

    return absolutePath;
  }
  
  inline int compare(int a, int b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
  }
}
