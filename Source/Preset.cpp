//
// Created by Alex Birch on 17/09/2017.
//

#include "Preset.h"

using namespace std;

Preset::Preset(
        int preset,
        string name
) : preset(preset),
    name(name) {}

int Preset::getPreset() {
    return preset;
}

string Preset::getName() {
    return name;
}