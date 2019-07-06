//
//  Params.cpp
//  juicysfplugin - Shared Code
//
//  Created by Alex Birch on 01/07/2019.
//  Copyright © 2019 Birchlabs. All rights reserved.
//

#include "Params.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiConstants.h"
#include "GuiConstants.h"
#include "SharesParams.h"

using namespace std;

Params::Params() noexcept
: uiWidth{GuiConstants::minWidth}
, uiHeight{GuiConstants::minHeight}
, soundFontPath{String()}
// , preset{-1}
// , bank{-1}
// , attack{0}
// , decay{0}
// , sustain{0}
// , release{0}
// , filterCutOff{0}
// .filterResonance{0}
{
}

void Params::setAttributesOnXml(shared_ptr<XmlElement> xml) {
    xml->setAttribute("uiWidth", uiWidth);
    xml->setAttribute("uiHeight", uiHeight);
    xml->setAttribute("soundFontPath", soundFontPath);
    // xml.setAttribute("preset", preset);
    // xml.setAttribute("bank", bank);
    // xml.setAttribute("attack", attack);
    // xml.setAttribute("decay", decay);
    // xml.setAttribute("sustain", sustain);
    // xml.setAttribute("release", release);
    // xml.setAttribute("filterCutOff", filterCutOff);
    // xml.setAttribute("filterResonance", filterResonance);
}

void Params::loadAttributesFromXml(shared_ptr<XmlElement> xmlState) {
    uiWidth = jmin(jmax(xmlState->getIntAttribute("uiWidth", uiWidth), GuiConstants::minWidth), GuiConstants::maxWidth);
    uiHeight = jmin(jmax(xmlState->getIntAttribute("uiHeight", uiHeight), GuiConstants::minHeight), GuiConstants::maxHeight);
    soundFontPath = xmlState->getStringAttribute("soundFontPath", soundFontPath);
    // preset = xmlState->getIntAttribute("preset", preset);
    // bank = xmlState->getIntAttribute("bank", bank);
    // attack = jmin(jmax(xmlState->getIntAttribute("attack", attack), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
    // decay = jmin(jmax(xmlState->getIntAttribute("decay", decay), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
    // sustain = jmin(jmax(xmlState->getIntAttribute("sustain", sustain), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
    // release = jmin(jmax(xmlState->getIntAttribute("release", release), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
    // filterCutOff = jmin(jmax(xmlState->getIntAttribute("filterCutOff", filterCutOff), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
    // filterResonance = jmin(jmax(xmlState->getIntAttribute("filterResonance", filterResonance), MidiConstants::midiMinValue), MidiConstants::midiMaxValue);
}

//void Params::acceptMidiControlEvent(int controller, int value) {
//    switch(static_cast<fluid_midi_control_change>(controller)) {
//        case SOUND_CTRL2: // MIDI CC 71 Timbre/Harmonic Intensity (filter resonance)
//            filterResonance = value;
//            break;
//        case SOUND_CTRL3: // MIDI CC 72 Release time
//            release = value;
//            break;
//        case SOUND_CTRL4: // MIDI CC 73 Attack time
//            attack = value;
//            break;
//        case SOUND_CTRL5: // MIDI CC 74 Brightness (cutoff frequency, FILTERFC)
//            filterCutOff = value;
//            break;
//        case SOUND_CTRL6: // MIDI CC 75 Decay Time
//            decay = value;
//            break;
//        case SOUND_CTRL10: // MIDI CC 79 undefined
//            sustain = value;
//            break;
//        default:
//            break;
//    }
//}

void Params::setSoundFontPath(const String& value) {
    soundFontPath = value;
}

String& Params::getSoundFontPath() {
    return soundFontPath;
}
//int Params::getPreset() {
//    return preset;
//}
//int Params::getBank() {
//    return bank;
//}
int Params::getUiWidth() {
    return uiWidth;
}
int Params::getUiHeight() {
    return uiHeight;
}
//int Params::getAttack() {
//    return attack;
//}
//int Params::getDecay() {
//    return decay;
//}
//int Params::getSustain() {
//    return sustain;
//}
//int Params::getRelease() {
//    return release;
//}
//int Params::getFilterCutOff() {
//    return filterCutOff;
//}
//int Params::getFilterResonance() {
//    return filterResonance;
//}

//void Params::setPreset(int value) {
//    preset = value;
//}
//void Params::setBank(int value) {
//    bank = value;
//}
void Params::setUiWidth(int value) {
    uiWidth = value;
}
void Params::setUiHeight(int value) {
    uiHeight = value;
}
//void Params::setAttack(int value) {
//    attack = value;
//}
//void Params::setDecay(int value) {
//    decay = value;
//}
//void Params::setSustain(int value) {
//    sustain = value;
//}
//void Params::setRelease(int value) {
//    release = value;
//}
//void Params::setFilterCutOff(int value) {
//    filterCutOff = value;
//}
//void Params::setFilterResonance(int value) {
//    filterResonance = value;
//}
