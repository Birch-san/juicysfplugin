/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"
#include "StateChangeSubscriber.h"
#include "StateChangeNotifier.h"
#include "State.h"
#include <list>

using namespace std;

//==============================================================================
/**
*/
class JuicySFAudioProcessor  : public AudioProcessor,
public StateChangeNotifier
{
public:
    //==============================================================================
    JuicySFAudioProcessor();
    ~JuicySFAudioProcessor();

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

    void subscribeToStateChanges(StateChangeSubscriber* subscriber) override;
    void unsubscribeFromStateChanges(StateChangeSubscriber* subscriber) override;

    State* getState();

private:
    void initialiseSynth();

    State state;
    FluidSynthModel fluidSynthModel;
    fluid_synth_t* fluidSynth;
    Synthesiser synth;

    list<StateChangeSubscriber*> stateChangeSubscribers;

    static BusesProperties getBusesProperties();

//    Model* model;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuicySFAudioProcessor)
};
