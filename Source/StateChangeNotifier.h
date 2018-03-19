//
// Created by Alex Birch on 19/03/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#import "StateChangeSubscriber.h"

class StateChangeNotifier {
public:
    StateChangeNotifier() {}
    virtual ~StateChangeNotifier() {}

    virtual void subscribeToStateChanges(StateChangeSubscriber* subscriber) = 0;
    virtual void unsubscribeFromStateChanges(StateChangeSubscriber* subscriber) = 0;
};

