//
// Created by Alex Birch on 18/03/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class StateChangeSubscriber {
public:
    virtual ~StateChangeSubscriber() {} // pass pointer ownership to another party without exposing the concrete derived class
    virtual void getStateInformation (XmlElement& xml) = 0;
    virtual void setStateInformation (XmlElement* xmlState) = 0;
};
