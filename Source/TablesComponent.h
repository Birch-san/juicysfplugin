//
// Created by Alex Birch on 17/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Pills.h"
#include "TableComponent.h"
#include "FluidSynthModel.h"
#include <memory>
#include <fluidsynth.h>

using namespace std;

class TablesComponent : public Component
{
public:
    TablesComponent(
        AudioProcessorValueTreeState& valueTreeState
    );

    void resized() override;

    bool keyPressed(const KeyPress &key) override;

private:
    AudioProcessorValueTreeState& valueTreeState;

    Pills banks;
    TableComponent presetTable;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TablesComponent)
};
