//
// Created by Alex Birch on 17/09/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class Preset {
public:
    Preset(
            int preset,
            string name
    );

    int getPreset();
    string getName();

private:
    int preset;
    string name;
};