//
// Created by Alex Birch on 18/03/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#include "State.h"

State::State(StateChangeNotifier& n) :
notifier(n),
lastUIWidth(400),
lastUIHeight(300)
{
    notifier.subscribeToStateChanges(this);
}

State::~State() {
    notifier.unsubscribeFromStateChanges(this);
}

void State::getStateInformation (XmlElement& xml) {
    // save
    xml.setAttribute ("uiWidth", lastUIWidth);
    xml.setAttribute ("uiHeight", lastUIHeight);
}

void State::setStateInformation (XmlElement* xmlState) {
    lastUIWidth = xmlState->getIntAttribute ("uiWidth", lastUIWidth);
    lastUIHeight = xmlState->getIntAttribute ("uiWidth", lastUIHeight);
}

void State::setLastUIWidth(int width) {
    this->lastUIWidth = width;
}
void State::setLastUIHeight(int height) {
    this->lastUIHeight = height;
}

int State::getLastUIWidth() {
    return lastUIWidth;
}
int State::getLastUIHeight() {
    return lastUIHeight;
}