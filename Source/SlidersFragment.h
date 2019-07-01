#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SlidersFragment {
public:
    virtual ~SlidersFragment() {}

    virtual void acceptMidiControlEvent(int controller, int value) = 0;
    
    // virtual void updateAttackSlider(int value) = 0;
    // virtual void updateDecaySlider(int value) = 0;
    // virtual void updateSustainSlider(int value) = 0;
    // virtual void updateReleaseSlider(int value) = 0;

    // virtual void updateFilterCutOffSlider(int value) = 0;
    // virtual void updateFilterResonanceSlider(int value) = 0;
};
