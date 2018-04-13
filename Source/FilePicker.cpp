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
  fluidSynthModel(fluidSynthModel),
  currentPath() {
    // faster (rounded edges introduce transparency)
    setOpaque (true);

    setDisplayedFilePath(fluidSynthModel->getCurrentSoundFontAbsPath());

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
    currentPath = fileChooser.getCurrentFile().getFullPathName();
    fluidSynthModel->onFileNameChanged(fileChooser.getCurrentFile().getFullPathName(), -1, -1);
}

void FilePicker::setDisplayedFilePath(const String& path) {
    if (!shouldChangeDisplayedFilePath(path)) {
        return;
    }
    currentPath = path;
    fileChooser.setCurrentFile(File(path), true, dontSendNotification);
}

bool FilePicker::shouldChangeDisplayedFilePath(const String &path) {
    if (path.isEmpty()) {
        return false;
    }
    if (path == currentPath) {
        return false;
    }
    return true;
}