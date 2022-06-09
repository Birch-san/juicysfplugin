#!/usr/bin/env bash
# exec git clone --branch 6.1.6 --depth 1 https://github.com/juce-framework/JUCE.git

# fix compilation of UUIDGetter template in MinGW on x86
# https://github.com/juce-framework/JUCE/issues/1029
# fix also detection of ARM Windows;
# win32 aarch64 build would otherwise fail due to "invalid output constraint '=a' in asm" in juce_ByteOrder.h
# https://github.com/juce-framework/JUCE/blob/2f980209cc4091a4490bb1bafc5d530f16834e58/modules/juce_core/memory/juce_ByteOrder.h
exec git clone --branch 6.1.6-fix-x86-and-aarch64-17 --depth 1 https://github.com/Birch-san/JUCE.git