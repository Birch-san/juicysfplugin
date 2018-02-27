/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"

//==============================================================================
/**
*/
class LazarusAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    LazarusAudioProcessor();
    ~LazarusAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    bool supportsDoublePrecisionProcessing() const override;

    FluidSynthModel* getFluidSynthModel();

    MidiKeyboardState keyboardState;

    int getLastUIWidth();
    int getLastUIHeight();

    void setLastUIWidth(int width);
    void setLastUIHeight(int height);

private:
    void initialiseSynth();

    FluidSynthModel fluidSynthModel;
    fluid_synth_t* fluidSynth;
    Synthesiser synth;

    static BusesProperties getBusesProperties();

    int lastUIWidth, lastUIHeight;

//    Model* model;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LazarusAudioProcessor)
};
