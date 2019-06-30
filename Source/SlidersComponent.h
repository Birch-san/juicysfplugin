# pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

class SlidersComponent : public Component
{
public:
    SlidersComponent();
    ~SlidersComponent();

    void resized() override;

private:
    std::function<void()> makeSliderListener(Slider& slider);

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
