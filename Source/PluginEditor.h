/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "TablesComponent.h"
#include "SurjectiveMidiKeyboardComponent.h"
#include "FilePicker.h"

//==============================================================================
/**
*/
class LazarusAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    LazarusAudioProcessorEditor (LazarusAudioProcessor&);
    ~LazarusAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    bool keyPressed(const KeyPress &key) override;
    bool keyStateChanged (bool isKeyDown) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LazarusAudioProcessor& processor;

    SurjectiveMidiKeyboardComponent midiKeyboard;
    TablesComponent tablesComponent;
    FilePicker filePicker;

    bool focusInitialized;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LazarusAudioProcessorEditor)
};
