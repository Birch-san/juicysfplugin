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


// https://stackoverflow.com/a/13446565/5257399
//using std::shared_ptr;

using namespace std;

class FluidSynthModel
: public ValueTree::Listener
, public AudioProcessorValueTreeState::Listener {
public:
    FluidSynthModel(
        AudioProcessorValueTreeState& valueTreeState
        // SharesParams& sharedParams
        // ValueTree& valueTree
        );
     ~FluidSynthModel();

    shared_ptr<fluid_synth_t> getSynth();
    void initialise();

    BanksToPresets getBanks();

    void changePreset(int bank, int preset);
    int getChannel();

    void onFileNameChanged(const String &absPath, int bank, int preset);
    void setControllerValue(int controller, int value);

    //==============================================================================
    /**
        Used to receive callbacks when a button is clicked.

        @see Button::addListener, Button::removeListener
    */
    // class Listener
    // {
    // public:
    //     /** Destructor. */
    //     virtual ~Listener();

    //     /** Called when the button is clicked. */
    //     virtual void fontChanged (FluidSynthModel*, const String &absPath);
    // };

    /** Registers a listener to receive events when this button's state changes.
        If the listener is already registered, this will not register it again.
        @see removeListener
    */
    // void addListener (Listener* newListener);

    /** Removes a previously-registered button listener
        @see addListener
    */
    // void removeListener (Listener* listener);

    void setSampleRate(float sampleRate);

    const String& getCurrentSoundFontAbsPath();
    
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

private:
//    class ValueTreeListener: public ValueTree::Listener {
//    public:
////        ValueTreeListener();
////        ~ValueTreeListener();
//        virtual void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged,
//                                               const Identifier& property) override;
//        inline virtual void valueTreeChildAdded (ValueTree& parentTree,
//                                          ValueTree& childWhichHasBeenAdded) override {};
//        inline virtual void valueTreeChildRemoved (ValueTree& parentTree,
//                                            ValueTree& childWhichHasBeenRemoved,
//                                            int indexFromWhichChildWasRemoved) override {};
//        inline virtual void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved,
//                                                 int oldIndex, int newIndex) override {};
//        inline virtual void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override {};
//        inline virtual void valueTreeRedirected (ValueTree& treeWhichHasBeenChanged) override {};
//        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ValueTreeListener)
//    };

    int handleMidiEvent(void* data, fluid_midi_event_t* event);
    void refreshBanks();
    // void refreshPresets();
    // void refreshBanksAndPresets();
    
//    ValueTreeListener valueTreeListener;

    AudioProcessorValueTreeState& valueTreeState;
    // SharesParams& sharedParams;
    // ValueTree& valueTree;

    // https://stackoverflow.com/questions/38980315/is-stdunique-ptr-deletion-order-guaranteed
    // members are destroyed in reverse of the order they're declared
    // http://www.fluidsynth.org/api/
    // in their examples, they destroy the synth before destroying the settings
    unique_ptr<fluid_settings_t, decltype(&delete_fluid_settings)> settings;
    // TODO: shared_ptr may ruin our guarantee of synth's being destroyed first, so consider changing the access we expose
    shared_ptr<fluid_synth_t> synth;
    // unique_ptr<fluid_midi_driver_t, decltype(&delete_fluid_midi_driver)> midiDriver;

    String currentSoundFontAbsPath;

    float currentSampleRate;

    fluid_preset_t* getFirstPreset();
    void selectFirstPreset();
    unique_ptr<BankAndPreset> getFirstBankAndPreset();

    void unloadAndLoadFont(const String &absPath);
    void loadFont(const String &absPath);
    bool shouldLoadFont(const String &absPath);

    void changePresetImpl(int bank, int preset);

    bool initialised;
    unsigned int sfont_id;
    unsigned int channel;

//    fluid_mod_t* mod;

    // ListenerList<Listener> eventListeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FluidSynthModel)
};
