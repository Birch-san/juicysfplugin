//
// Created by Alex Birch on 07/09/2017.
//

#pragma once

#include<memory>
#include<fluidsynth.h>
#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class SoundfontSynthVoice : public SynthesiserVoice {
public:
    SoundfontSynthVoice(shared_ptr<fluid_synth_t> synth);

    bool canPlaySound (SynthesiserSound* sound) override;
    void startNote (
            int midiNoteNumber,
            float velocity,
            SynthesiserSound* /*sound*/,
            int /*currentPitchWheelPosition*/) override;

    void stopNote (float /*velocity*/, bool allowTailOff) override;
    void pitchWheelMoved (int /*newValue*/) override;

    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override;

    void renderNextBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    double tailOff;
    double level;
    double currentAngle;
    double angleDelta;
    int midiNoteNumber;

    shared_ptr<fluid_synth_t> synth;
};
