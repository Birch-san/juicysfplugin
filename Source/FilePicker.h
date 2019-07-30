//
// Created by Alex Birch on 03/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"

class FilePicker: public Component,
                  public ValueTree::Listener,
                  private FilenameComponentListener
{
public:
    FilePicker(
        AudioProcessorValueTreeState& valueTreeState
        // FluidSynthModel& fluidSynthModel
    );
    ~FilePicker();

    void resized() override;
    void paint (Graphics& g) override;

    void setDisplayedFilePath(const String&);
    

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
    FilenameComponent fileChooser;

    AudioProcessorValueTreeState& valueTreeState;
    // FluidSynthModel& fluidSynthModel;

    String currentPath;

    void filenameComponentChanged (FilenameComponent*) override;

    bool shouldChangeDisplayedFilePath(const String &path);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePicker)
};
