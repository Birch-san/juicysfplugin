/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuicySFAudioProcessorEditor::JuicySFAudioProcessorEditor (JuicySFAudioProcessor& p)
    : AudioProcessorEditor (&p),
      processor (p),
      midiKeyboard (p.keyboardState, SurjectiveMidiKeyboardComponent::horizontalKeyboard),
      tablesComponent(p.getFluidSynthModel()),
      filePicker(p.getFluidSynthModel())
{
    // set resize limits for this plug-in
    setResizeLimits (400, 300, 1900, 1000);

    setSize (p.lastUIWidth, p.lastUIHeight);

//    processor.subscribeToStateChanges(this);

    midiKeyboard.setName ("MIDI Keyboard");

    midiKeyboard.setWantsKeyboardFocus(false);
    tablesComponent.setWantsKeyboardFocus(false);

    setWantsKeyboardFocus(true);
    addAndMakeVisible (midiKeyboard);

    addAndMakeVisible(slidersComponent);
    addAndMakeVisible(tablesComponent);
    addAndMakeVisible(filePicker);

}

JuicySFAudioProcessorEditor::~JuicySFAudioProcessorEditor()
{
//    processor.unsubscribeFromStateChanges(this);
}

//void JuicySFAudioProcessorEditor::getStateInformation (XmlElement& xml) {
//    // save
//    xml.setAttribute ("uiWidth", getWidth());
//    xml.setAttribute ("uiHeight", getHeight());
//}
//
//void JuicySFAudioProcessorEditor::setStateInformation (XmlElement* xmlState) {
//    // load
//    setSize (xmlState->getIntAttribute ("uiWidth", getWidth()),
//            xmlState->getIntAttribute ("uiHeight", getHeight()));
//}

//==============================================================================
void JuicySFAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

//    g.setColour (Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);

    if (!focusInitialized) {
        if (!hasKeyboardFocus(false) && isVisible()) {
            grabKeyboardFocus();
        }
        if (getCurrentlyFocusedComponent() == this) {
            focusInitialized = true;
        }
    }
}

void JuicySFAudioProcessorEditor::resized()
{
    const int padding{8};
    const int pianoHeight{70};
    const int filePickerHeight{25};
    const int slidersHeight{150};
    Rectangle<int> r (getLocalBounds());
    filePicker.setBounds(r.removeFromTop(filePickerHeight + padding).reduced(padding, 0).withTrimmedTop(padding));
    slidersComponent.setBounds(r.removeFromTop(slidersHeight + padding).reduced(padding, 0).withTrimmedTop(padding));

    // Rectangle<int> r2 (getLocalBounds());
    // slidersComponent.setBounds(r2.removeFromLeft(filePickerWidth + padding).reduced(padding, 0).withTrimmedLeft(padding));

    midiKeyboard.setBounds (r.removeFromBottom (pianoHeight).reduced(padding, 0));
    tablesComponent.setBounds(r.reduced(0, padding));

    processor.lastUIWidth = getWidth();
    processor.lastUIHeight = getHeight();

//    Rectangle<int> r2 (getLocalBounds());
//    r2.reduce(0, padding);
//    r2.removeFromBottom(pianoHeight);
//    r2.removeFromTop(filePickerHeight);
//    tablesComponent.setBounds (r2);
//
//    Rectangle<int> r3 (getLocalBounds());
//    r3.removeFromTop(filePickerHeight);
//
//    filePicker.setBounds(r3);
}

bool JuicySFAudioProcessorEditor::keyPressed(const KeyPress &key) {
//    if (!hasKeyboardFocus(false))
//        return false;
//    if (key.getKeyCode() == KeyPress::upKey){
//    }
//    cout << "hey\n";
    const int cursorKeys[] = {
            KeyPress::leftKey,
            KeyPress::rightKey,
            KeyPress::upKey,
            KeyPress::downKey
    };
    if (any_of(
            begin(cursorKeys),
            end(cursorKeys),
            [&](int i) { return i == key.getKeyCode(); }
    )) {
        return tablesComponent.keyPressed(key);
    } else {
        return midiKeyboard.keyPressed(key);
    }
//    for(auto childComponent : getChildren()) {
//        if (childComponent->keyPressed(key)) return true;
//    }
    return false;
}

bool JuicySFAudioProcessorEditor::keyStateChanged (bool isKeyDown) {
    return midiKeyboard.keyStateChanged(isKeyDown);
//    for(auto childComponent : getChildren()) {
//        if (childComponent->keyStateChanged(isKeyDown)) return true;
//    }
//    return false;
}

FilePickerFragment& JuicySFAudioProcessorEditor::getFilePicker() {
    return filePicker;
}