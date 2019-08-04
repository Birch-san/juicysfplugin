//
// Created by Alex Birch on 03/10/2017.
//

#include "FilePicker.h"
#include "MyColours.h"
#include "Util.h"

FilePicker::FilePicker(
    AudioProcessorValueTreeState& valueTreeState
    // FluidSynthModel& fluidSynthModel
)
: fileChooser{
    "File",
    File(),
    true,
    false,
    false,
    "*.sf2;*.sf3",
    String(),
    "Choose a Soundfont file to load into the synthesizer"}
, valueTreeState{valueTreeState}
// , fluidSynthModel{fluidSynthModel}
// , currentPath{}
{
    // faster (rounded edges introduce transparency)
    setOpaque (true);

    // setDisplayedFilePath(fluidSynthModel.getCurrentSoundFontAbsPath());
    setDisplayedFilePath(valueTreeState.state.getChildWithName("soundFont").getProperty("path", ""));

    addAndMakeVisible (fileChooser);
    fileChooser.addListener (this);
    valueTreeState.state.addListener(this);
//    valueTreeState.state.getChildWithName("soundFont").sendPropertyChangeMessage("path");
}
FilePicker::~FilePicker() {
    fileChooser.removeListener (this);
    valueTreeState.state.removeListener(this);
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
    // currentPath = fileChooser.getCurrentFile().getFullPathName();
    // fluidSynthModel.onFileNameChanged(fileChooser.getCurrentFile().getFullPathName(), -1, -1);
    Value value{valueTreeState.state.getChildWithName("soundFont").getPropertyAsValue("path", nullptr)};
    value.setValue(fileChooser.getCurrentFile().getFullPathName());
//    value = fileChooser.getCurrentFile().getFullPathName();
}

void FilePicker::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged,
                                               const Identifier& property) {
    if (treeWhosePropertyHasChanged.getType() == StringRef("soundFont")) {
    // if (&treeWhosePropertyHasChanged == &valueTree) {
        if (property == StringRef("path")) {
            String soundFontPath = treeWhosePropertyHasChanged.getProperty("path", "");
            DEBUG_PRINT(soundFontPath);
            setDisplayedFilePath(soundFontPath);
            // if (soundFontPath.isNotEmpty()) {
            //     loadFont(soundFontPath);
            // }
        }
    }
}

void FilePicker::setDisplayedFilePath(const String& path) {
     if (!shouldChangeDisplayedFilePath(path)) {
         return;
     }
    // currentPath = path;
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
