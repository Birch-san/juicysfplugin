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
#include "SlidersComponent.h"

//==============================================================================
/**
*/
class JuicySFAudioProcessorEditor
: public AudioProcessorEditor
// , public AudioProcessorValueTreeState::Listener
, private Value::Listener
// , public ValueTree::Listener
                      /*,
                                     , public ExposesComponents
                                     public StateChangeSubscriber*/
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

//    void getStateInformation (XmlElement& xml) override;
//    void setStateInformation (XmlElement* xmlState) override;

    // virtual FilePickerFragment& getFilePicker() override;
    // virtual SlidersFragment& getSliders() override;
    // virtual void parameterChanged (const String& parameterID, float newValue) override;

    // int getWidth();
    // int getHeight();

    // virtual void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged,
    //                                        const Identifier& property) override;
    // inline virtual void valueTreeChildAdded (ValueTree& parentTree,
    //                                          ValueTree& childWhichHasBeenAdded) override {};
    // inline virtual void valueTreeChildRemoved (ValueTree& parentTree,
    //                                            ValueTree& childWhichHasBeenRemoved,
    //                                            int indexFromWhichChildWasRemoved) override {};
    // inline virtual void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved,
    //                                                 int oldIndex, int newIndex) override {};
    // inline virtual void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override {};
    // inline virtual void valueTreeRedirected (ValueTree& treeWhichHasBeenChanged) override {};

private:
    void valueChanged (Value&) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuicySFAudioProcessor& processor;

    AudioProcessorValueTreeState& valueTreeState;
    // SharesParams& sharedParams;

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
