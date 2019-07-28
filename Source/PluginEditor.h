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
#include "SlidersComponent.h"

//==============================================================================
/**
*/
class JuicySFAudioProcessorEditor
: public AudioProcessorEditor
, private Value::Listener
{
public:
    JuicySFAudioProcessorEditor(
      JuicySFAudioProcessor&,
      AudioProcessorValueTreeState& valueTreeState
      );
    ~JuicySFAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    bool keyPressed(const KeyPress &key) override;
    bool keyStateChanged (bool isKeyDown) override;

private:
    void valueChanged (Value&) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuicySFAudioProcessor& processor;

    AudioProcessorValueTreeState& valueTreeState;

    // these are used to persist the UI's size - the values are stored along with the
    // filter's other parameters, and the UI component will update them when it gets
    // resized.
    Value lastUIWidth, lastUIHeight;

    SurjectiveMidiKeyboardComponent midiKeyboard;
    TablesComponent tablesComponent;
    FilePicker filePicker;
    SlidersComponent slidersComponent;

    bool focusInitialized;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuicySFAudioProcessorEditor)
};
