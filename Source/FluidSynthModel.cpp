//
// Created by Alex Birch on 10/09/2017.
//

#include <iostream>
#include "FluidSynthModel.h"

using namespace std;

FluidSynthModel::FluidSynthModel() {
    initialised = false;
    channel = 0;
    sfont_id = 0;
    settings = nullptr;
    synth = nullptr;
}

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
    settings = new_fluid_settings();
    // https://sourceforge.net/p/fluidsynth/wiki/FluidSettings/
    fluid_settings_setstr(settings, "synth.verbose", "yes");

    synth = new_fluid_synth(settings);

//    loadFont("/Users/birch/Documents/soundfont/EarthBound.sf2");


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

void FluidSynthModel::onFileNameChanged(const string &absPath) {
    unloadAndLoadFont(absPath);
    eventListeners.call(&FluidSynthModel::Listener::fontChanged, this);
}

void FluidSynthModel::unloadAndLoadFont(const string &absPath) {
    fluid_synth_sfunload(synth, sfont_id, 1);
    loadFont(absPath);
}

void FluidSynthModel::loadFont(const string &absPath) {
    sfont_id++;
    fluid_synth_sfload(synth, absPath.c_str(), 1);
    selectFirstPreset();
}

FluidSynthModel::Listener::~Listener() {
}

void FluidSynthModel::Listener::fontChanged(FluidSynthModel *) {
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