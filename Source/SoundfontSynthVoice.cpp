//
// Created by Alex Birch on 07/09/2017.
//

#include "SoundfontSynthVoice.h"
#include "SoundfontSynthSound.h"

SoundfontSynthVoice::SoundfontSynthVoice(fluid_synth_t* synth)
: tailOff (0.0),
level(0.0),
currentAngle(0.0),
angleDelta(0.0),
midiNoteNumber(0),
synth(synth)
{
}

bool SoundfontSynthVoice::canPlaySound(SynthesiserSound* sound) {
    return dynamic_cast<SoundfontSynthSound*> (sound) != nullptr;
}
void SoundfontSynthVoice::startNote(
        int midiNoteNumber,
        float velocity,
        SynthesiserSound* sound,
        int /*currentPitchWheelPosition*/) {
    this->midiNoteNumber = midiNoteNumber;
    fluid_synth_noteon(synth, 0, midiNoteNumber, static_cast<int>(velocity * 127));

//    currentAngle = 0.0;
//    level = velocity * 0.15;
//    tailOff = 0.0;
//
//    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
//    double cyclesPerSample = cyclesPerSecond / getSampleRate();
//
//    angleDelta = cyclesPerSample * 2.0 * double_Pi;

//    jassert(dynamic_cast<SoundfontSynthSound*> (sound) != nullptr);
//    SoundfontSynthSound* sfsynth = dynamic_cast<SoundfontSynthSound*> (sound);
}

void SoundfontSynthVoice::stopNote (float /*velocity*/, bool allowTailOff) {
//    if (allowTailOff) {
//        // start a tail-off by setting this flag. The render callback will pick up on
//        // this and do a fade out, calling clearCurrentNote() when it's finished.
//
//        // we only need to begin a tail-off if it's not already doing so - the
//        if (tailOff == 0.0) {
//            // stopNote method could be called more than once.
//            tailOff = 1.0;
//        }
//    } else {
//        // we're being told to stop playing immediately, so reset everything..
//
//        clearCurrentNote();
//        angleDelta = 0.0;
//    }
    clearCurrentNote();
    fluid_synth_noteoff(synth, 0, this->midiNoteNumber);
}

// receives input as MIDI 0 to 16383, with 8192 being center
// this is also exactly the input fluidsynth requires
void SoundfontSynthVoice::pitchWheelMoved (int newValue) {
    Logger::outputDebugString ( juce::String::formatted("Pitch wheel: %d\n", newValue) );
    fluid_synth_pitch_bend(synth, 0, newValue);
}

void SoundfontSynthVoice::controllerMoved (int controllerNumber, int newValue) {
    // this seems to be "program change" event
    Logger::outputDebugString ( juce::String::formatted("Controller moved: %d, %d\n", controllerNumber, newValue) );
}

void SoundfontSynthVoice::renderNextBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {
    //fluid_synth_process(synth.get(), numSamples, 1, nullptr, outputBuffer.getNumChannels(), outputBuffer.getArrayOfWritePointers());
}

//void SoundfontSynthVoice::renderBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {
//    fluid_synth_process(synth.get(), numSamples, 1, nullptr, outputBuffer.getNumChannels(), outputBuffer.getArrayOfWritePointers());
//    if (angleDelta == 0.0) {
//        return;
//    }
//    while (--numSamples >= 0) {
//        double qualifiedTailOff = tailOff > 0 ? tailOff : 1.0;
//        auto currentSample = static_cast<FloatType> (std::sin (currentAngle) * level * qualifiedTailOff);
//        for (int i = outputBuffer.getNumChannels(); --i >= 0;)
//            outputBuffer.addSample (i, startSample, currentSample);
//
//        currentAngle += angleDelta;
//        ++startSample;
//
//        if (tailOff > 0) {
//            tailOff *= 0.99;
//
//            if (tailOff <= 0.005) {
//                clearCurrentNote();
//                angleDelta = 0.0;
//                break;
//            }
//        }
//    }
//}
