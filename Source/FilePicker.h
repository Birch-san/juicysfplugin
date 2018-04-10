//
// Created by Alex Birch on 03/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"
#import "FilePickerFragment.h"

class FilePicker: public Component,
                  public FilePickerFragment,
                  private FilenameComponentListener
{
public:
    FilePicker(
            FluidSynthModel* fluidSynthModel
    );
    ~FilePicker();

    void resized() override;
    void paint (Graphics& g) override;

    virtual void setDisplayedFilePath(const String&) override;
private:
    FilenameComponent fileChooser;

    FluidSynthModel* fluidSynthModel;

    String currentPath;

    void filenameComponentChanged (FilenameComponent*) override;

    bool shouldChangeDisplayedFilePath(const String &path);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePicker)
};