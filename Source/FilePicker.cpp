//
// Created by Alex Birch on 03/10/2017.
//

#include "FilePicker.h"
#include "MyColours.h"

FilePicker::FilePicker(
        FluidSynthModel* fluidSynthModel
)
: fileChooser(
        "File",
        File(),
        true,
        false,
        false,
        "*.sf2;*.sf3",
        String(),
        "Choose a Soundfont file to load into the synthesizer"
),
  fluidSynthModel(fluidSynthModel) {
    // faster (rounded edges introduce transparency)
    setOpaque (true);

    const String& currentSoundFontAbsPath = fluidSynthModel->getCurrentSoundFontAbsPath();
    if (currentSoundFontAbsPath.isNotEmpty()) {
        fileChooser.setCurrentFile(File(currentSoundFontAbsPath), true, dontSendNotification);
    }

    addAndMakeVisible (fileChooser);
    fileChooser.addListener (this);
}
FilePicker::~FilePicker() {
    fileChooser.removeListener (this);
}

void FilePicker::resized() {
    Rectangle<int> r (getLocalBounds());
    fileChooser.setBounds (r);
}

/**
 * This is required to support setOpaque(true)
 */
void FilePicker::paint(Graphics& g)
{
    g.fillAll(MyColours::getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour::windowBackground, Colours::lightgrey));
}

void FilePicker::filenameComponentChanged (FilenameComponent*) {
    fluidSynthModel->onFileNameChanged(fileChooser.getCurrentFile().getFullPathName());
}