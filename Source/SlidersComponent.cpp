//
//  SlidersComponent.cpp
//  juicysfplugin - Shared Code
//
//  Created by Alex Birch on 29/06/2019.
//  Copyright © 2019 Birchlabs. All rights reserved.
//

#include "SlidersComponent.h"

std::function<void()> SlidersComponent::makeSliderListener(Slider& slider) {
    return [&slider]{
        slider.setValue(slider.getValue(), NotificationType::dontSendNotification);
    };
}

SlidersComponent::~SlidersComponent()
{
}

const int SlidersComponent::getDesiredWidth() {
    const int envelopeSliders{4};
    const int filterSliders{2};
    const int groupXMargin{8};
    const int groupXPadding{8};
    const int sliderXMargin{3};
    const int sliderWidth{30};

    return envelopeSliders * sliderWidth + (envelopeSliders-1) * sliderXMargin + 2 * groupXPadding
    + filterSliders * sliderWidth + (filterSliders-1) * sliderXMargin + 2 * groupXPadding + groupXMargin;
}

void SlidersComponent::resized() {
    const int envelopeSliders{4};
    const int filterSliders{2};
    const int groupXMargin{8};
    const int groupXPadding{8};
    const int groupYPadding{9};
    const int sliderXMargin{3};
    const int labelHeight{25};
    const int sliderWidth{30};
    Rectangle<int> r{getLocalBounds()};
    Rectangle<int> rEnvelope{r.removeFromLeft(envelopeSliders * sliderWidth + (envelopeSliders-1) * sliderXMargin + 2 * groupXPadding)};
    Rectangle<int> rFilter{r.removeFromLeft(filterSliders * sliderWidth + (filterSliders-1) * sliderXMargin + 2 * groupXPadding + groupXMargin).withTrimmedLeft(groupXMargin)};
    envelopeGroup.setBounds(rEnvelope);
    filterGroup.setBounds(rFilter);

    rEnvelope.reduce(groupXPadding, groupYPadding);
    rFilter.reduce(groupXPadding, groupYPadding);
    attackSlider.setBounds(rEnvelope.removeFromLeft(sliderWidth).withTrimmedTop(labelHeight));
    decaySlider.setBounds(rEnvelope.removeFromLeft(sliderWidth + sliderXMargin).withTrimmedTop(labelHeight).withTrimmedLeft(sliderXMargin));
    sustainSlider.setBounds(rEnvelope.removeFromLeft(sliderWidth + sliderXMargin).withTrimmedTop(labelHeight).withTrimmedLeft(sliderXMargin));
    releaseSlider.setBounds(rEnvelope.removeFromLeft(sliderWidth + sliderXMargin).withTrimmedTop(labelHeight).withTrimmedLeft(sliderXMargin));
    filterCutOffSlider.setBounds(rFilter.removeFromLeft(sliderWidth).withTrimmedTop(labelHeight));
    filterResonanceSlider.setBounds(rFilter.removeFromLeft(sliderWidth + sliderXMargin).withTrimmedTop(labelHeight).withTrimmedLeft(sliderXMargin));
}

SlidersComponent::SlidersComponent() :
envelopeGroup{"envelopeGroup", "Envelope"},
filterGroup{"filterGroup", "Filter"}
{
    const Slider::SliderStyle style{Slider::SliderStyle::LinearVertical};
    const double rangeMin(0);
    const double rangeMax(127);
    const double rangeStep(1);

    attackSlider.setSliderStyle(style);
    attackSlider.setRange(rangeMin, rangeMax, rangeStep);
    // attackSlider.onValueChange = makeSliderListener(attackSlider);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, attackSlider.getTextBoxWidth(), attackSlider.getTextBoxHeight());

    decaySlider.setSliderStyle(style);
    decaySlider.setRange(rangeMin, rangeMax, rangeStep);
    // decaySlider.onValueChange = makeSliderListener(decaySlider);
    decaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, decaySlider.getTextBoxWidth(), decaySlider.getTextBoxHeight());

    sustainSlider.setSliderStyle(style);
    sustainSlider.setRange(rangeMin, rangeMax, rangeStep);
    // sustainSlider.onValueChange = makeSliderListener(sustainSlider);
    sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, sustainSlider.getTextBoxWidth(), sustainSlider.getTextBoxHeight());

    releaseSlider.setSliderStyle(style);
    releaseSlider.setRange(rangeMin, rangeMax, rangeStep);
    // releaseSlider.onValueChange = makeSliderListener(releaseSlider);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, releaseSlider.getTextBoxWidth(), releaseSlider.getTextBoxHeight());

    filterCutOffSlider.setSliderStyle(style);
    filterCutOffSlider.setRange(rangeMin, rangeMax, rangeStep);
    // filterCutOffSlider.onValueChange = makeSliderListener(filterCutOffSlider);
    filterCutOffSlider.setTextBoxStyle(Slider::TextBoxBelow, true, filterCutOffSlider.getTextBoxWidth(), filterCutOffSlider.getTextBoxHeight());

    filterResonanceSlider.setSliderStyle(style);
    filterResonanceSlider.setRange(rangeMin, rangeMax, rangeStep);
    // filterResonanceSlider.onValueChange = makeSliderListener(filterResonanceSlider);
    filterResonanceSlider.setTextBoxStyle(Slider::TextBoxBelow, true, filterResonanceSlider.getTextBoxWidth(), filterResonanceSlider.getTextBoxHeight());

    addAndMakeVisible(attackSlider);
    addAndMakeVisible(decaySlider);
    addAndMakeVisible(sustainSlider);
    addAndMakeVisible(releaseSlider);
    addAndMakeVisible(filterCutOffSlider);
    addAndMakeVisible(filterResonanceSlider);

    attackLabel.setText("A", NotificationType::dontSendNotification);
    attackLabel.setJustificationType(Justification::centredBottom);
    attackLabel.attachToComponent(&attackSlider, false);

    decayLabel.setText("D", NotificationType::dontSendNotification);
    decayLabel.setJustificationType(Justification::centredBottom);
    decayLabel.attachToComponent(&decaySlider, false);

    sustainLabel.setText("S", NotificationType::dontSendNotification);
    sustainLabel.setJustificationType(Justification::centredBottom);
    sustainLabel.attachToComponent(&sustainSlider, false);
    
    releaseLabel.setText("R", NotificationType::dontSendNotification);
    releaseLabel.setJustificationType(Justification::centredBottom);
    releaseLabel.attachToComponent(&releaseSlider, false);

    filterCutOffLabel.setText("Cut", NotificationType::dontSendNotification);
    filterCutOffLabel.setJustificationType(Justification::centredBottom);
    filterCutOffLabel.attachToComponent(&filterCutOffSlider, false);

    filterResonanceLabel.setText("Res", NotificationType::dontSendNotification);
    filterResonanceLabel.setJustificationType(Justification::centredBottom);
    filterResonanceLabel.attachToComponent(&filterResonanceSlider, false);

    addAndMakeVisible(attackLabel);
    addAndMakeVisible(decayLabel);
    addAndMakeVisible(sustainLabel);
    addAndMakeVisible(releaseLabel);
    addAndMakeVisible(filterCutOffLabel);
    addAndMakeVisible(filterResonanceLabel);

    addAndMakeVisible(envelopeGroup);
    addAndMakeVisible(filterGroup);
}