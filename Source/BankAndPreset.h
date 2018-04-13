//
// Created by Alex Birch on 13/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class BankAndPreset {
public:
    BankAndPreset(int bank, int preset);

    int getBank();
    int getPreset();

private:
    int bank;
    int preset;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankAndPreset)
};

