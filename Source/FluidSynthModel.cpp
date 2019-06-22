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
          channel(0),
          mod(nullptr)

{}

FluidSynthModel::~FluidSynthModel() {
    if (initialised) {
//        delete_fluid_audio_driver(driver);
        delete_fluid_synth(synth);
        delete_fluid_settings(settings);
//        delete driver;
//        delete settings;
        delete_fluid_mod(mod);
    }
}

void FluidSynthModel::initialise() {
//    if (initialised) {
//        delete_fluid_synth(synth);
//        delete_fluid_settings(settings);
//    }
    // deactivate all audio drivers in fluidsynth to avoid FL Studio deadlock when initialising CoreAudio
    // after all: we only use fluidsynth to render blocks of audio. it doesn't output to audio driver.
    const char *DRV[] = {NULL};
    fluid_audio_driver_register(DRV);

    settings = new_fluid_settings();
    // https://sourceforge.net/p/fluidsynth/wiki/FluidSettings/
//    fluid_settings_setint(settings, "synth.verbose", 1);

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
    
    

//    mod = new_fluid_mod();
//
//    // modulator's primary source controller and flags
//    // fluid_mod_src:
//    // https://github.com/FluidSynth/fluidsynth/blob/master/include/fluidsynth/mod.h#L61
//    // fluid_mod_flags:
//    // https://github.com/FluidSynth/fluidsynth/blob/master/include/fluidsynth/mod.h#L41
//    // diagrams showing what negative and concave mean:
//    // https://musescore.org/en/user/527826/blog/2016/05/23/volume-fluidsynth
//    // fluid_gen_type:
//    // https://github.com/FluidSynth/fluidsynth/blob/master/include/fluidsynth/gen.h#L36
//    // https://github.com/FluidSynth/fluidsynth/blob/master/src/synth/fluid_gen.c#L27
//    fluid_mod_set_source1(mod,
//            FLUID_MOD_KEYPRESSURE,
//            FLUID_MOD_CC |
//                    FLUID_MOD_POSITIVE |
//                    FLUID_MOD_UNIPOLAR |
//                    FLUID_MOD_CONCAVE);
//    // modulator's secondary source controller and flags
//    // MIDI CC 74
//    fluid_mod_set_source2(mod, 74, FLUID_MOD_CC);
//    // generator for filter cutoff
//    fluid_mod_set_dest(mod, GEN_FILTERFC);
//    fluid_mod_set_amount(mod, 13500.0f);
//
//    fluid_synth_add_default_mod(synth, mod, FLUID_SYNTH_ADD);
    
    

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

fluid_preset_t* FluidSynthModel::getFirstPreset() {
    fluid_sfont_t* sfont = fluid_synth_get_sfont_by_id(synth, sfont_id);

    jassert(sfont != nullptr);
    fluid_sfont_iteration_start(sfont);

    return fluid_sfont_iteration_next(sfont);
}

unique_ptr<BankAndPreset> FluidSynthModel::getFirstBankAndPreset() {
    fluid_preset_t* preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth, sfont_id);

    return make_unique<BankAndPreset>(fluid_preset_get_banknum(preset) + offset, fluid_preset_get_num(preset));
};

void FluidSynthModel::selectFirstPreset() {
    fluid_preset_t* preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth, sfont_id);

    changePreset(fluid_preset_get_banknum(preset) + offset, fluid_preset_get_num(preset));
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

    fluid_sfont_iteration_start(sfont);

    for(fluid_preset_t* preset = fluid_sfont_iteration_next(sfont);
    preset != nullptr;
    preset = fluid_sfont_iteration_next(sfont)) {
        banksToPresets.insert(BanksToPresets::value_type(
                fluid_preset_get_banknum(preset) + offset,
                *new Preset(
                        fluid_preset_get_num(preset),
                        fluid_preset_get_name(preset)
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
