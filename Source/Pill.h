//
// Created by Alex Birch on 01/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Pill : public TextButton {
public:
    explicit Pill(
            const String& buttonName,
            const int index,
            const int lastIx
    );

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pill)
};
