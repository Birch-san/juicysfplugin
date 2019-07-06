# pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"
#include "SharesParams.h"
#include "SlidersFragment.h"

using namespace std;
using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class SlidersComponent : public Component,
                         public SlidersFragment
{
public:
    SlidersComponent(
        SharesParams& sharedParams,
        AudioProcessorValueTreeState& valueTreeState,
        FluidSynthModel& fluidSynthModel);
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

    SharesParams& sharedParams;
    AudioProcessorValueTreeState& valueTreeState;
    FluidSynthModel& fluidSynthModel;

    GroupComponent envelopeGroup;

    Slider attackSlider;
    Label attackLabel;
    unique_ptr<SliderAttachment> attackSliderAttachment;

    Slider decaySlider;
    Label decayLabel;
    unique_ptr<SliderAttachment> decaySliderAttachment;

    Slider sustainSlider;
    Label sustainLabel;
    unique_ptr<SliderAttachment> sustainSliderAttachment;

    Slider releaseSlider;
    Label releaseLabel;
    unique_ptr<SliderAttachment> releaseSliderAttachment;

    GroupComponent filterGroup;

    Slider filterCutOffSlider;
    Label filterCutOffLabel;
    unique_ptr<SliderAttachment> filterCutOffSliderAttachment;

    Slider filterResonanceSlider;
    Label filterResonanceLabel;
    unique_ptr<SliderAttachment> filterResonanceSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidersComponent)
};
