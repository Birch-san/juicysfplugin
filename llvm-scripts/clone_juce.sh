#!/usr/bin/env bash
# exec git clone --branch 6.1.6 --depth 1 https://github.com/juce-framework/JUCE.git

# fix compilation of UUIDGetter template in MinGW on x86
# https://github.com/juce-framework/JUCE/issues/1029
exec git clone --branch 6.1.6-fix-x86 --depth 1 https://github.com/Birch-san/JUCE.git