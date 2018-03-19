//
// Created by Alex Birch on 18/03/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "StateChangeSubscriber.h"
#include "PluginProcessor.h"

class State : public StateChangeSubscriber {
public:
    State(StateChangeNotifier& p);
    ~State();

    int getLastUIWidth();
    int getLastUIHeight();

    void setLastUIWidth(int width);
    void setLastUIHeight(int height);

    void getStateInformation (XmlElement& xml) override;
    void setStateInformation (XmlElement* xmlState) override;
private:
    StateChangeNotifier& notifier;

    int lastUIWidth, lastUIHeight;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (State)
};

