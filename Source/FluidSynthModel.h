//
// Created by Alex Birch on 10/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SharesParams.h"
#include <fluidsynth.h>
#include <memory>
#include "BankAndPreset.h"
#include "PresetsToBanks.h"

using namespace std;

class FluidSynthModel
: public ValueTree::Listener
, public AudioProcessorValueTreeState::Listener {
public:
    FluidSynthModel(
        AudioProcessorValueTreeState& valueTreeState
        );
     ~FluidSynthModel();

    void initialise();
    
    int getChannel();

    void setControllerValue(int controller, int value);

    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages);


    void setSampleRate(float sampleRate);
    
    //==============================================================================
    virtual void parameterChanged (const String& parameterID, float newValue) override;
    
    virtual void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged,
                                           const Identifier& property) override;
    inline virtual void valueTreeChildAdded (ValueTree& parentTree,
                                             ValueTree& childWhichHasBeenAdded) override {};
    inline virtual void valueTreeChildRemoved (ValueTree& parentTree,
                                               ValueTree& childWhichHasBeenRemoved,
                                               int indexFromWhichChildWasRemoved) override {};
    inline virtual void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved,
                                                    int oldIndex, int newIndex) override {};
    inline virtual void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override {};
    inline virtual void valueTreeRedirected (ValueTree& treeWhichHasBeenChanged) override {};

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram(int index);
    const String getProgramName(int index);
    void changeProgramName(int index, const String& newName);

private:
    int handleMidiEvent(void* data, fluid_midi_event_t* event);
    void refreshBanks();

    AudioProcessorValueTreeState& valueTreeState;

    // https://stackoverflow.com/questions/38980315/is-stdunique-ptr-deletion-order-guaranteed
    // members are destroyed in reverse of the order they're declared
    // http://www.fluidsynth.org/api/
    // in their examples, they destroy the synth before destroying the settings
    unique_ptr<fluid_settings_t, decltype(&delete_fluid_settings)> settings;
    // TODO: shared_ptr may ruin our guarantee of synth's being destroyed first, so consider changing the access we expose
    shared_ptr<fluid_synth_t> synth;
    // unique_ptr<fluid_midi_driver_t, decltype(&delete_fluid_midi_driver)> midiDriver;

    float currentSampleRate;

    fluid_preset_t* getFirstPreset();
    void selectFirstPreset();
    unique_ptr<BankAndPreset> getFirstBankAndPreset();

    void unloadAndLoadFont(const String &absPath);
    void loadFont(const String &absPath);

    void changePresetImpl(int bank, int preset);
    
    int sfont_id;
    unsigned int channel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FluidSynthModel)
};
