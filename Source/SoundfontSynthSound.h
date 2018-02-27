//
// Created by Alex Birch on 07/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SoundfontSynthSound : public SynthesiserSound {
public:
    bool appliesToNote (int /*midiNoteNumber*/) override;
    bool appliesToChannel (int /*midiChannel*/) override;
};