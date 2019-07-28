# pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FluidSynthModel.h"

using namespace std;
using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class SlidersComponent : public Component
{
public:
    SlidersComponent(
        AudioProcessorValueTreeState& valueTreeState,
        FluidSynthModel& fluidSynthModel);
    ~SlidersComponent();

    void resized() override;

    const int getDesiredWidth();

    void acceptMidiControlEvent(int controller, int value);

private:
    std::function<void()> makeSliderListener(Slider& slider, int controller);

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
