#!/usr/bin/env bash
set -eo pipefail

# rename parameter `new` to `new_`,
# to avoid this error in LLVM 14.0.0RC1's Clang:
#   In file included from /linux_native/include/JUCE-6.1.5/modules/juce_gui_basics/juce_gui_basics.cpp:70:
#   In file included from /opt/llvm-mingw/i686-w64-mingw32/include/UIAutomation.h:21:
#   /opt/llvm-mingw/i686-w64-mingw32/include/uiautomationcoreapi.h:69:128: error: invalid parameter name: 'new' is a keyword
# HRESULT WINAPI UiaRaiseAutomationPropertyChangedEvent(IRawElementProviderSimple *provider, PROPERTYID id, VARIANT old, VARIANT new);
sed -i -E '/WINAPI UiaRaiseAutomationPropertyChangedEvent/ s/(VARIANT new)/\1_/g' /opt/llvm-mingw/generic-w64-mingw32/include/uiautomationcoreapi.h

# JUCE includes UIAutomation.h
# but mingw headers are lowercase, and filesystem is case-sensitive
ln -s ./uiautomation.h /opt/llvm-mingw/generic-w64-mingw32/include/UIAutomation.h