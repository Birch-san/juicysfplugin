//
// Created by Alex Birch on 10/09/2017.
//

#include <iostream>
#include <fluidsynth.h>
#include "FluidSynthModel.h"
#include "MidiConstants.h"
#include "Util.h"

using namespace std;

FluidSynthModel::FluidSynthModel(
    AudioProcessorValueTreeState& valueTreeState
    // ValueTree& valueTree
    // SharesParams& sharedParams
    )
: valueTreeState{valueTreeState}
// , valueTree{valueTree}
// , sharedParams{sharedParams}
//, synth{nullptr}
, settings{nullptr, nullptr}
, currentSoundFontAbsPath{}
, currentSampleRate{44100}
, initialised{false}
, sfont_id{0}
, channel{0}/*,
mod(nullptr)*/
{
    valueTreeState.state.addListener(this);
}

FluidSynthModel::~FluidSynthModel() {
    valueTreeState.state.removeListener(this);
    // if (initialised) {
//        delete_fluid_audio_driver(driver);
        // delete_fluid_synth(synth);
//        delete_fluid_settings(settings);
//        delete driver;
//        delete settings;
//        delete_fluid_mod(mod);
    // }
 }

int FluidSynthModel::handleMidiEvent(void* data, fluid_midi_event_t* event)
{
//    DEBUG_PRINT(fluid_midi_event_get_type(event));
    // printf("event type: %d\n", fluid_midi_event_get_type(event));
    return 0;
}

void FluidSynthModel::initialise() {
//    if (initialised) {
//        delete_fluid_synth(synth);
//        delete_fluid_settings(settings);
//    }
    settings = { new_fluid_settings(), delete_fluid_settings };

    // deactivate all audio drivers in fluidsynth to avoid FL Studio deadlock when initialising CoreAudio
    // after all: we only use fluidsynth to render blocks of audio. it doesn't output to audio driver.
    const char *DRV[] {NULL};
    fluid_audio_driver_register(DRV);
    
//    handle_midi_event_func_t handler = [](void* data, fluid_midi_event_t* event) -> int {
//
//    };
    
//    midiDriver = unique_ptr<fluid_midi_driver_t, decltype(&delete_fluid_midi_driver)>(
//        new_fluid_midi_driver(
//            settings.get(),
//              [](void* data, fluid_midi_event_t* event) -> int {
//
//              },
//            nullptr),
//        delete_fluid_midi_driver);

    
    // https://sourceforge.net/p/fluidsynth/wiki/FluidSettings/
#if JUCE_DEBUG
    fluid_settings_setint(settings.get(), "synth.verbose", 1);
#endif

    synth = { new_fluid_synth(settings.get()), delete_fluid_synth };
    fluid_synth_set_sample_rate(synth.get(), currentSampleRate);

    // valueTreeState.getParameter("soundFontPath")->getValue();
    // RangedAudioParameter *param {valueTreeState.getParameter("release")};
    // jassert(dynamic_cast<AudioParameterInt*> (param) != nullptr);
    // AudioParameterInt* castParam {dynamic_cast<AudioParameterInt*> (param)};
    // *castParam = m.getControllerValue();
    
//    if (sharedParams.getSoundFontPath().isNotEmpty()) {
//        loadFont(sharedParams.getSoundFontPath());
//        changePreset(sharedParams->getBank(), sharedParams->getPreset());
//    }

    fluid_synth_set_gain(synth.get(), 2.0);
    
    for(int i{SOUND_CTRL1}; i <= SOUND_CTRL10; i++)
    {
        setControllerValue(i, 0);
    }

//    fluid_synth_bank_select(synth, 0, 3);

//    fluid_handle_inst

//    driver = new_fluid_audio_driver(settings, synth);

//    changePreset(128, 13);
    
//    float env_amount(12000.0f);
    
//     http://www.synthfont.com/SoundFont_NRPNs.PDF
    float env_amount(20000.0f);
//    float env_amount(24000.0f);
    
    // note: fluid_chan.c#fluid_channel_init_ctrl()
    // all SOUND_CTRL are inited with value of 64, not zero.
    // "Just like panning, a value of 64 indicates no change for sound ctrls"
    
    unique_ptr<fluid_mod_t, decltype(&delete_fluid_mod)> mod{new_fluid_mod(), delete_fluid_mod};
//
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL2), // MIDI CC 71 Timbre/Harmonic Intensity (filter resonance)
                          FLUID_MOD_CC
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_CONCAVE
                          | FLUID_MOD_POSITIVE);
    fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_FILTERQ);
    fluid_mod_set_amount(mod.get(), FLUID_PEAK_ATTENUATION);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    mod = {new_fluid_mod(), delete_fluid_mod};
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL3), // MIDI CC 72 Release time
                          FLUID_MOD_CC
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_LINEAR
                          | FLUID_MOD_POSITIVE);
    fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_VOLENVRELEASE);
//    fluid_mod_set_amount(mod.get(), 15200.0f);
    fluid_mod_set_amount(mod.get(), env_amount);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    mod = {new_fluid_mod(), delete_fluid_mod};
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL4), // MIDI CC 73 Attack time
                          FLUID_MOD_CC
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_LINEAR
                          | FLUID_MOD_POSITIVE);
    fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_VOLENVATTACK);
    fluid_mod_set_amount(mod.get(), env_amount);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    // soundfont spec says that if cutoff is >20kHz and resonance Q is 0, then no filtering occurs
    mod = {new_fluid_mod(), delete_fluid_mod};
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL5), // MIDI CC 74 Brightness (cutoff frequency, FILTERFC)
                          FLUID_MOD_CC
                          | FLUID_MOD_LINEAR
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_POSITIVE);
        fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_FILTERFC);
    fluid_mod_set_amount(mod.get(), -2400.0f);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    mod = {new_fluid_mod(), delete_fluid_mod};
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL6), // MIDI CC 75 Decay Time
                          FLUID_MOD_CC
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_LINEAR
                          | FLUID_MOD_POSITIVE);
    fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_VOLENVDECAY);
    fluid_mod_set_amount(mod.get(), env_amount);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    mod = {new_fluid_mod(), delete_fluid_mod};
    fluid_mod_set_source1(mod.get(),
                          static_cast<int>(SOUND_CTRL10), // MIDI CC 79 undefined
                          FLUID_MOD_CC
                          | FLUID_MOD_UNIPOLAR
                          | FLUID_MOD_CONCAVE
                          | FLUID_MOD_POSITIVE);
    fluid_mod_set_source2(mod.get(), 0, 0);
    fluid_mod_set_dest(mod.get(), GEN_VOLENVSUSTAIN);
    // fluice_voice.c#fluid_voice_update_param()
    // clamps the range to between 0 and 1000, so we'll copy that
    fluid_mod_set_amount(mod.get(), 1000.0f);
    fluid_synth_add_default_mod(synth.get(), mod.get(), FLUID_SYNTH_ADD);
    
    valueTreeState.state.getChildWithName("soundFont").sendPropertyChangeMessage("path");
    // valueTree.sendPropertyChangeMessage("soundFontPath");

    // initialised = true;
}

void FluidSynthModel::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged,
                                               const Identifier& property) {
    if (treeWhosePropertyHasChanged.getType() == StringRef("soundFont")) {
    // if (&treeWhosePropertyHasChanged == &valueTree) {
        if (property == StringRef("path")) {
            String soundFontPath{treeWhosePropertyHasChanged.getProperty("path", "")};
            if (soundFontPath.isNotEmpty()) {
                loadFont(soundFontPath);
            }
        }
    }
}

void FluidSynthModel::setControllerValue(int controller, int value) {
    fluid_midi_event_t *midi_event(new_fluid_midi_event());
    fluid_midi_event_set_type(midi_event, static_cast<int>(CONTROL_CHANGE));
    fluid_midi_event_set_channel(midi_event, channel);
    fluid_midi_event_set_control(midi_event, controller);
    fluid_midi_event_set_value(midi_event, value);
    fluid_synth_handle_midi_event(synth.get(), midi_event);
    delete_fluid_midi_event(midi_event);
    //        fluid_channel_set_cc(channel, i, 0);
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
//    sharedParams->setPreset(preset);
//    sharedParams->setBank(bank);
}

void FluidSynthModel::changePresetImpl(int bank, int preset) {
    fluid_synth_program_select(synth.get(), channel, sfont_id, static_cast<unsigned int>(bank), static_cast<unsigned int>(preset));
}

fluid_preset_t* FluidSynthModel::getFirstPreset() {
    fluid_sfont_t* sfont = fluid_synth_get_sfont_by_id(synth.get(), sfont_id);

    jassert(sfont != nullptr);
    fluid_sfont_iteration_start(sfont);

    return fluid_sfont_iteration_next(sfont);
}

unique_ptr<BankAndPreset> FluidSynthModel::getFirstBankAndPreset() {
    fluid_preset_t* preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth.get(), sfont_id);

    return make_unique<BankAndPreset>(fluid_preset_get_banknum(preset) + offset, fluid_preset_get_num(preset));
};

void FluidSynthModel::selectFirstPreset() {
    fluid_preset_t* preset = getFirstPreset();

    int offset = fluid_synth_get_bank_offset(synth.get(), sfont_id);

    changePreset(fluid_preset_get_banknum(preset) + offset, fluid_preset_get_num(preset));
}

BanksToPresets FluidSynthModel::getBanks() {
    BanksToPresets banksToPresets;

    int soundfontCount = fluid_synth_sfcount(synth.get());

    if (soundfontCount == 0) {
        // no soundfont selected
        return banksToPresets;
    }

    fluid_sfont_t* sfont = fluid_synth_get_sfont_by_id(synth.get(), sfont_id);
    if(sfont == nullptr) {
        // no soundfont found by that ID
        // the above guard (soundfontCount) protects us for the
        // main case we're expecting. this guard is just defensive programming.
        return banksToPresets;
    }

    int offset = fluid_synth_get_bank_offset(synth.get(), sfont_id);

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

shared_ptr<fluid_synth_t> FluidSynthModel::getSynth() {
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
    ValueTree valueTree{valueTreeState.state.getChildWithName("soundFont")};
    valueTree.setPropertyExcludingListener(this, "path", absPath, nullptr);
    // valueTree.setPropertyExcludingListener(this, "soundFontPath", absPath, nullptr);
//    sharedParams.setSoundFontPath(absPath);
    eventListeners.call(&FluidSynthModel::Listener::fontChanged, this, absPath);
}

void FluidSynthModel::unloadAndLoadFont(const String &absPath) {
    // in the base case, there is no font loaded
    if (fluid_synth_sfcount(synth.get()) > 0) {
        fluid_synth_sfunload(synth.get(), sfont_id, 1);
    }
    loadFont(absPath);
}

void FluidSynthModel::loadFont(const String &absPath) {
    currentSoundFontAbsPath = absPath;
    sfont_id++;
    fluid_synth_sfload(synth.get(), absPath.toStdString().c_str(), 1);
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
    // https://stackoverflow.com/a/40856043/5257399
    // test if a smart pointer is null
    if (!synth) {
        // don't worry; we'll do this in initialise phase regardless
        return;
    }
    fluid_synth_set_sample_rate(synth.get(), sampleRate);
}
