#pragma once

#include "SharesParams.h"
#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class Params: public SharesParams {
public:
    Params() noexcept;
    
    virtual void setAttributesOnXml(shared_ptr<XmlElement> xml) override;
    virtual void loadAttributesFromXml(shared_ptr<XmlElement> xmlState) override;
//    virtual void acceptMidiControlEvent(int controller, int value) override;

    virtual void setSoundFontPath(const String& value) override;
    virtual String& getSoundFontPath() override;
    // virtual int getPreset() override;
    // virtual void setPreset(int value) override;
    // virtual int getBank() override;
    // virtual void setBank(int value) override;

    // virtual int getUiWidth() override;
    // virtual void setUiWidth(int value) override;
    // virtual int getUiHeight() override;
    // virtual void setUiHeight(int value) override;

    // virtual int getAttack() override;
    // virtual void setAttack(int value) override;
    // virtual int getDecay() override;
    // virtual void setDecay(int value) override;
    // virtual int getSustain() override;
    // virtual void setSustain(int value) override;
    // virtual int getRelease() override;
    // virtual void setRelease(int value) override;

    // virtual int getFilterCutOff() override;
    // virtual void setFilterCutOff(int value) override;
    // virtual int getFilterResonance() override;
    // virtual void setFilterResonance(int value) override;

private:
    // int uiWidth;
    // int uiHeight;

    String soundFontPath;
    // int preset;
    // int bank;

    // int attack;
    // int decay;
    // int sustain;
    // int release;

    // int filterCutOff;
    // int filterResonance;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Params)
};
