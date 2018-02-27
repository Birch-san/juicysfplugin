//
// Created by Alex Birch on 03/10/2017.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MyColours {
public:
    static Colour getUIColourIfAvailable (LookAndFeel_V4::ColourScheme::UIColour uiColour, Colour fallback);

};