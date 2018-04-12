//
// Created by Alex Birch on 10/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SharesParams {
public:
    virtual ~SharesParams() {}

    virtual void setSoundFontPath(const String& value) = 0;
    virtual String& getSoundFontPath() = 0;
    virtual int getPreset() = 0;
    virtual void setPreset(int preset) = 0;
    virtual int getBank() = 0;
    virtual void setBank(int bank) = 0;
};



