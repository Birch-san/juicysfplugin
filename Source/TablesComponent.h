//
// Created by Alex Birch on 17/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Pills.h"
#include "TableComponent.h"
#include "Preset.h"
#include "PresetsToBanks.h"
#include "FluidSynthModel.h"
#include <memory>
#include <fluidsynth.h>

using namespace std;

class TablesComponent : public Component,
                        public FluidSynthModel::Listener
{
public:
    TablesComponent(
            FluidSynthModel* fluidSynthModel
    );
    ~TablesComponent();

    void resized() override;

    bool keyPressed(const KeyPress &key) override;
    void fontChanged(FluidSynthModel *, const string &) override;

private:
    FluidSynthModel* fluidSynthModel;
    int selectedBank;

    Pills* banks;
    TableComponent* presetTable;

    BanksToPresets banksToPresets;

    static vector<vector<string>> mapPresets(const BanksToPresets &banksToPresets, int bank);
    static vector<string> mapBanks(const BanksToPresets &banksToPresets);

    void onBankSelected(int bank);
    void onPresetSelected(int preset);
    int presetToIndexMapper(int preset);

    fluid_preset_t* getCurrentPreset();
    Preset getFirstPresetInBank(int bank);

    bool initialised;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TablesComponent)
};
