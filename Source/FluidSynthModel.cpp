//
// Created by Alex Birch on 10/09/2017.
//

#include <iostream>
#include "FluidSynthModel.h"

using namespace std;

FluidSynthModel::FluidSynthModel(SharesParams& p)
        : sharesParams(p),
          synth(nullptr),
          settings(nullptr),
          currentSoundFontAbsPath(),
          currentSampleRate(44100),
          initialised(false),
          sfont_id(0),
          channel(0)

{}

FluidSynthModel::~FluidSynthModel() {
    if (initialised) {
//        delete_fluid_audio_driver(driver);
        delete_fluid_synth(synth);
        delete_fluid_settings(settings);
//        delete driver;
//        delete settings;
    }
}

void FluidSynthModel::initialise() {
//    if (initialised) {
//        delete_fluid_synth(synth);
//        delete_fluid_settings(settings);
//    }
    /*
     * when our plugin is hosted inside certain DAWs (e.g. FL Studio and presumably LMMS)
     * a mutex is held (by the DAW?) which prevents fluidsynth's AudioObjectGetPropertyDataSize from completing.
     * this means
     * https://gist.github.com/tresf/230b20f083403a11a3c7
     * https://github.com/LMMS/lmms/issues/649
     * http://fluidsynth.sourceforge.net/api/
     */
    settings = new_fluid_settings();
    // https://sourceforge.net/p/fluidsynth/wiki/FluidSettings/
    fluid_settings_setstr(settings, "synth.verbose", "yes");

    synth = new_fluid_synth(settings);
    fluid_synth_set_sample_rate(synth, currentSampleRate);

    if (sharesParams.getSoundFontPath().isNotEmpty()) {
        loadFont(sharesParams.getSoundFontPath());
        changePreset(sharesParams.getBank(), sharesParams.getPreset());
    }

    fluid_synth_set_gain(synth, 2.0);

//    fluid_synth_bank_select(synth, 0, 3);

//    fluid_handle_inst

//    driver = new_fluid_audio_driver(settings, synth);

//    changePreset(128, 13);

    initialised = true;
}

int FluidSynthModel::getChannel() {
    return channel;
}

void FluidSynthModel::changePreset(int bank, int preset) {
    if (bank == -1 || preset == -1) {
        unique_ptr<BankAndPreset> bankAndPreset = getFirstBankAndPreset();
        bank = bankAndPreset->getBank();
        preset = bankAndPreset->getPreset();
    }
    changePresetImpl(bank, preset);
    sharesParams.setPreset(preset);
    sharesParams.setBank(bank);
}

void FluidSynthModel::changePresetImpl(int bank, int preset) {
    fluid_synth_program_select(synth, channel, sfont_id, static_cast<unsigned int>(bank), static_cast<unsigned int>(preset));
}

const fluid_preset_t FluidSynthModel::getFirstPreset() {
    fluid_sfont_t* sfont = fluid_synth_get_sfont_by_id(synth, sfont_id);

    jassert(sfont != nullptr);
    sfont->iteration_start(sfont);

    fluid_preset_t preset;

    sfont->iteration_next(sfont, &preset);

    return preset;
}

unique_ptr<BankAndPreset> FluidSynthModel::getFirstBankAndPreset() {
    fluid_preset_t preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth, sfont_id);

    return make_unique<BankAndPreset>(preset.get_banknum(&preset) + offset, preset.get_num(&preset));
};

void FluidSynthModel::selectFirstPreset() {
    fluid_preset_t preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth, sfont_id);

    changePreset(preset.get_banknum(&preset) + offset, preset.get_num(&preset));
}

BanksToPresets FluidSynthModel::getBanks() {
    BanksToPresets banksToPresets;

    int soundfontCount = fluid_synth_sfcount(synth);

    if (soundfontCount == 0) {
        // no soundfont selected
        return banksToPresets;
    }

    fluid_sfont_t* sfont = fluid_synth_get_sfont_by_id(synth, sfont_id);
    if(sfont == nullptr) {
        // no soundfont found by that ID
        // the above guard (soundfontCount) protects us for the
        // main case we're expecting. this guard is just defensive programming.
        return banksToPresets;
    }

    int offset = fluid_synth_get_bank_offset(synth, sfont_id);

    sfont->iteration_start(sfont);

    fluid_preset_t preset;

    while(sfont->iteration_next(sfont, &preset)) {
        banksToPresets.insert(BanksToPresets::value_type(
                preset.get_banknum(&preset) + offset,
                *new Preset(
                        preset.get_num(&preset),
                        preset.get_name(&preset)
                )
        ));
    }

    return banksToPresets;
}

fluid_synth_t* FluidSynthModel::getSynth() {
    // https://msdn.microsoft.com/en-us/library/hh279669.aspx
    // You can pass a shared_ptr to another function in the following ways:
    // Pass the shared_ptr by value. This invokes the copy constructor, increments the reference count, and makes the callee an owner.
    return synth;
}

void FluidSynthModel::onFileNameChanged(const String &absPath, int bank, int preset) {
    if (!shouldLoadFont(absPath)) {
        return;
    }
    unloadAndLoadFont(absPath);
    changePreset(bank, preset);
    sharesParams.setSoundFontPath(absPath);
    eventListeners.call(&FluidSynthModel::Listener::fontChanged, this, absPath);
}

void FluidSynthModel::unloadAndLoadFont(const String &absPath) {
    // in the base case, there is no font loaded
    if (fluid_synth_sfcount(synth) > 0) {
        fluid_synth_sfunload(synth, sfont_id, 1);
    }
    loadFont(absPath);
}

void FluidSynthModel::loadFont(const String &absPath) {
    currentSoundFontAbsPath = absPath;
    sfont_id++;
    fluid_synth_sfload(synth, absPath.toStdString().c_str(), 1);
}

FluidSynthModel::Listener::~Listener() {
}

bool FluidSynthModel::shouldLoadFont(const String &absPath) {
    if (absPath.isEmpty()) {
        return false;
    }
    if (absPath == currentSoundFontAbsPath) {
        return false;
    }
    return true;
}

void FluidSynthModel::Listener::fontChanged(FluidSynthModel * model, const String &absPath) {
}

const String& FluidSynthModel::getCurrentSoundFontAbsPath() {
    return currentSoundFontAbsPath;
}

//==============================================================================
void FluidSynthModel::addListener (FluidSynthModel::Listener* const newListener)
{
    eventListeners.add(newListener);
}

void FluidSynthModel::removeListener (FluidSynthModel::Listener* const listener)
{
    eventListeners.remove(listener);
}

void FluidSynthModel::setSampleRate(float sampleRate) {
    currentSampleRate = sampleRate;
    if (!initialised) {
        // don't worry; we'll do this in initialise phase regardless
        return;
    }
    fluid_synth_set_sample_rate(synth, sampleRate);
}

bool FluidSynthModel::isInitialised() {
    return initialised;
}