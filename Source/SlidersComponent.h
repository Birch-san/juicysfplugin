# pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"
#include "SharesParams.h"
#include "SlidersFragment.h"

using namespace std;

class SlidersComponent : public Component,
                         public SlidersFragment
{
public:
    SlidersComponent(
        shared_ptr<SharesParams> sharedParams,
        FluidSynthModel* fluidSynthModel);
    ~SlidersComponent();

    void resized() override;

    const int getDesiredWidth();

    virtual void acceptMidiControlEvent(int controller, int value) override;
    
    // virtual void updateAttackSlider(int value) override;
    // virtual void updateDecaySlider(int value) override;
    // virtual void updateSustainSlider(int value) override;
    // virtual void updateReleaseSlider(int value) override;
    
    // virtual void updateFilterCutOffSlider(int value) override;
    // virtual void updateFilterResonanceSlider(int value) override;

private:
    std::function<void()> makeSliderListener(Slider& slider, int controller);

    shared_ptr<SharesParams> sharedParams;
    FluidSynthModel* fluidSynthModel;

    GroupComponent envelopeGroup;

    Slider attackSlider;
    Label attackLabel;

    Slider decaySlider;
    Label decayLabel;

    Slider sustainSlider;
    Label sustainLabel;

    Slider releaseSlider;
    Label releaseLabel;

    GroupComponent filterGroup;

    Slider filterCutOffSlider;
    Label filterCutOffLabel;

    Slider filterResonanceSlider;
    Label filterResonanceLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidersComponent)
};
