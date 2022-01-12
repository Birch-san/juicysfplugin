#!/usr/bin/env bash
cd JUCE

cmake -B build -DCMAKE_INSTALL_PREFIX="/linux_native"
cmake --build build --target install