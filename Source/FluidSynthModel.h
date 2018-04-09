//
// Created by Alex Birch on 10/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include <fluidsynth.h>
#include <memory>
#include "PresetsToBanks.h"


// https://stackoverflow.com/a/13446565/5257399
using std::shared_ptr;

class FluidSynthModel {
public:
    FluidSynthModel();
    ~FluidSynthModel();

    fluid_synth_t* getSynth();
    void initialise(JuicySFAudioProcessor& p);

    BanksToPresets getBanks();

    void changePreset(int bank, int preset);
    int getChannel();

    void onFileNameChanged(const string &absPath);

    //==============================================================================
    /**
        Used to receive callbacks when a button is clicked.

        @see Button::addListener, Button::removeListener
    */
    class Listener
    {
    public:
        /** Destructor. */
        virtual ~Listener();

        /** Called when the button is clicked. */
        virtual void fontChanged (FluidSynthModel*, const string &absPath);
    };

    /** Registers a listener to receive events when this button's state changes.
        If the listener is already registered, this will not register it again.
        @see removeListener
    */
    void addListener (Listener* newListener);

    /** Removes a previously-registered button listener
        @see addListener
    */
    void removeListener (Listener* listener);

private:
    JuicySFAudioProcessor* processor;

    fluid_synth_t* synth;
    fluid_settings_t* settings;
//    fluid_audio_driver_t* driver;

    const fluid_preset_t getFirstPreset();
    void selectFirstPreset();

    void unloadAndLoadFont(const string &absPath);
    void loadFont(const string &absPath);

    bool initialised;
    unsigned int sfont_id;
    unsigned int channel;

    ListenerList<Listener> eventListeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FluidSynthModel)
};