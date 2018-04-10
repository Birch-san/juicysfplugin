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
#include "FilePickerFragment.h"
#include "ExposesComponents.h"
#include "FilePicker.h"
#include "StateChangeSubscriber.h"

//==============================================================================
/**
*/
class JuicySFAudioProcessorEditor  : public AudioProcessorEditor,
                                     public ExposesComponents/*,
                                     public StateChangeSubscriber*/
{
public:
    JuicySFAudioProcessorEditor (JuicySFAudioProcessor&);
    ~JuicySFAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    bool keyPressed(const KeyPress &key) override;
    bool keyStateChanged (bool isKeyDown) override;

//    void getStateInformation (XmlElement& xml) override;
//    void setStateInformation (XmlElement* xmlState) override;

    virtual FilePickerFragment& getFilePicker() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuicySFAudioProcessor& processor;

    SurjectiveMidiKeyboardComponent midiKeyboard;
    TablesComponent tablesComponent;
    FilePicker filePicker;

    bool focusInitialized;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuicySFAudioProcessorEditor)
};
