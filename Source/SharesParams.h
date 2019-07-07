//
// Created by Alex Birch on 10/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class SharesParams {
public:
    virtual ~SharesParams() {}

    virtual void setAttributesOnXml(shared_ptr<XmlElement> xml) = 0;
    virtual void loadAttributesFromXml(shared_ptr<XmlElement> xmlState) = 0;
//    virtual void acceptMidiControlEvent(int controller, int value) = 0;

    virtual void setSoundFontPath(const String& value) = 0;
    virtual String& getSoundFontPath() = 0;
    // virtual int getPreset() = 0;
    // virtual void setPreset(int value) = 0;
    // virtual int getBank() = 0;
    // virtual void setBank(int value) = 0;

    // virtual int getUiWidth() = 0;
    // virtual void setUiWidth(int value) = 0;
    // virtual int getUiHeight() = 0;
    // virtual void setUiHeight(int value) = 0;
    
    // virtual int getAttack() = 0;
    // virtual void setAttack(int value) = 0;
    // virtual int getDecay() = 0;
    // virtual void setDecay(int value) = 0;
    // virtual int getSustain() = 0;
    // virtual void setSustain(int value) = 0;
    // virtual int getRelease() = 0;
    // virtual void setRelease(int value) = 0;

    // virtual int getFilterCutOff() = 0;
    // virtual void setFilterCutOff(int value) = 0;
    // virtual int getFilterResonance() = 0;
    // virtual void setFilterResonance(int value) = 0;
    
};



