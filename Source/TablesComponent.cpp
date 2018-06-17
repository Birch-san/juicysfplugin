//
// Created by Alex Birch on 17/09/2017.
//

#include "TablesComponent.h"

using namespace std;
using namespace placeholders;

TablesComponent::TablesComponent(
        FluidSynthModel* fluidSynthModel
) : fluidSynthModel(fluidSynthModel),
    banksToPresets(fluidSynthModel->getBanks()),
    initialised(false)
{
    fluid_preset_t* currentPreset = getCurrentPreset();
    selectedBank = -1;
    int selectedPreset = -1;

    if (currentPreset != nullptr) {
        selectedBank = fluid_preset_get_banknum(currentPreset);
        selectedPreset = fluid_preset_get_num(currentPreset);
    }

    auto rowToPresetMapper = [this](const vector<string> &row) {
        return stoi(row[0]);
    };
    auto itemToBankMapper = [](const string &item) {
        return stoi(item);
    };

    presetTable = new TableComponent(
            {"Preset", "Name"},
            mapPresets(
                    banksToPresets,
                    selectedBank
            ),
            [this](int preset){
                this->onPresetSelected(preset);
            },
            rowToPresetMapper,
            presetToIndexMapper(selectedPreset)
    );
    banks = new Pills(
            "Banks",
            mapBanks(banksToPresets),
            [this](int bank){
                this->onBankSelected(bank);
            },
            itemToBankMapper,
            selectedBank
    );

    presetTable->setWantsKeyboardFocus(false);

    addAndMakeVisible(presetTable);

    addAndMakeVisible(banks);

    initialised = true;

    fluidSynthModel->addListener(this);
}

fluid_preset_t* TablesComponent::getCurrentPreset() {
    fluid_synth_t* synth = fluidSynthModel->getSynth();

    return fluid_synth_get_channel_preset(synth, fluidSynthModel->getChannel());
}

Preset TablesComponent::getFirstPresetInBank(int bank) {
    pair<BanksToPresets::const_iterator, BanksToPresets::const_iterator> iterators = banksToPresets.equal_range(bank);
    BanksToPresets::const_iterator it = iterators.first;
    return it->second;
}

void TablesComponent::onBankSelected(int bank) {
    if (!initialised || bank == -1) {
        return;
    }
    cout << "Bank " << bank << endl;
    selectedBank = bank;
    Preset firstPresetInBank = getFirstPresetInBank(bank);
    presetTable->setRows(
            mapPresets(
                    banksToPresets,
                    bank
            ),
            presetToIndexMapper(firstPresetInBank.getPreset())
    );
}

int TablesComponent::presetToIndexMapper(int preset) {
    int ix = 0;
    pair<BanksToPresets::const_iterator, BanksToPresets::const_iterator> iterators = this->banksToPresets.equal_range(this->selectedBank);
    for (auto it = iterators.first; it != iterators.second; ++it, ix++) {
        Preset b = it->second;
        if (preset == b.getPreset()) {
            return ix;
        }
    }
    return 0;
}

void TablesComponent::onPresetSelected(int preset) {
    if (!initialised || preset == -1) {
        return;
    }
    cout << "Preset " << preset << endl;
//    selectedPreset = preset;
    fluidSynthModel->changePreset(selectedBank, preset);
}

TablesComponent::~TablesComponent() {
    delete presetTable;
    delete banks;
    fluidSynthModel->removeListener(this);
}

vector<string> TablesComponent::mapBanks(const BanksToPresets &banksToPresets) {
    vector<string> rows;

    const auto compareKey = [](const BanksToPresets::value_type& lhs, const BanksToPresets::value_type& rhs) {
        return lhs.first < rhs.first;
    };

    for(auto i = banksToPresets.begin(); i != banksToPresets.end(); i = std::upper_bound(i, banksToPresets.end(), *i, compareKey)) {
        rows.push_back(to_string(i->first));
    }

    return rows;
}


vector<vector<string>> TablesComponent::mapPresets(const BanksToPresets &banksToPresets, int bank) {
    vector<vector<string>> rows;

    pair<BanksToPresets::const_iterator, BanksToPresets::const_iterator> iterators = banksToPresets.equal_range(bank);
    for (auto it = iterators.first; it != iterators.second; ++it) {
        Preset b = it->second;
        vector<string> row;
        row.push_back(to_string(b.getPreset()));
        row.push_back(b.getName());

        rows.push_back(row);
    }

    return rows;
}

void TablesComponent::resized() {
    Rectangle<int> r (getLocalBounds());
    banks->setBounds (r.removeFromTop(27).reduced(5,0));

    presetTable->setBounds (r);
}

bool TablesComponent::keyPressed(const KeyPress &key) {
    if (key.getKeyCode() == KeyPress::leftKey
            || key.getKeyCode() == KeyPress::rightKey) {
        banks->cycle(key.getKeyCode() == KeyPress::rightKey);
        return true;
    }
    return presetTable->keyPressed(key);
}

void TablesComponent::fontChanged(FluidSynthModel *, const String &) {
    banksToPresets = fluidSynthModel->getBanks();

    fluid_preset_t* currentPreset = getCurrentPreset();

    selectedBank = fluid_preset_get_banknum(currentPreset);
    int selectedPreset = fluid_preset_get_num(currentPreset);

    presetTable->setRows(
            mapPresets(
                    banksToPresets,
                    selectedBank
            ),
            presetToIndexMapper(selectedPreset)
    );

    banks->setItems(
            mapBanks(banksToPresets),
            selectedBank
    );
}