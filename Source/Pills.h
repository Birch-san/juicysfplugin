//
// Created by Alex Birch on 01/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class Pill
: public Button::Listener
, public AudioProcessorValueTreeState::Listener
{
public:
    Pill(
        AudioProcessorValueTreeState& valueTreeState,
        int bank,
        bool isFirst,
        bool isLast
    );
    ~Pill();

    void buttonClicked (Button* button) override;

    virtual void parameterChanged (const String& parameterID, float newValue) override;
private:
    void loadToggleState();

    AudioProcessorValueTreeState& valueTreeState;
    int bank;
    TextButton textButton;

    friend class Pills;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pill)
}

class Pills
: public Component
, public ValueTree::Listener
{
public:
    Pills(
        AudioProcessorValueTreeState& valueTreeState
        // string label
        // const vector<string> &items,
        // const function<void (int)> &onItemSelected,
        // const function<int (const string&)> &itemToIDMapper,
        // int initiallySelectedItem
    );
    ~Pills();

    // void setItems(
    //         const vector<string> &items,
    //         int initiallySelectedItem
    // );

    // void buttonClicked (Button* button) override;
    void cycle(bool right);

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
    void loadModelFrom(ValueTree& banks);

    AudioProcessorValueTreeState& valueTreeState;
    // string label;
    // vector<string> items;
    // function<void (int)> onItemSelected;
    // function<int (const string&)> itemToIDMapper;

    // OwnedArray<Pill> buttons;
    vector<unique_ptr<Pill>> pills;
    Button *selected;

    // Pill* addToList (Pill* newButton);

    void populate(int initiallySelectedItem);
    void resized() override;
    void paint(Graphics& g) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pills)
};