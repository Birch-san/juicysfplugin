//
// Created by Alex Birch on 03/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"

class FilePicker: public Component,
                  private FilenameComponentListener
{
public:
    FilePicker(
            FluidSynthModel* fluidSynthModel
    );
    ~FilePicker();

    void resized() override;
    void paint (Graphics& g) override;
private:
    FilenameComponent fileChooser;

    FluidSynthModel* fluidSynthModel;

    void filenameComponentChanged (FilenameComponent*) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePicker)
};