//
// Created by Alex Birch on 11/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class FilePickerFragment {
public:
    virtual ~FilePickerFragment() {}

    virtual void setDisplayedFilePath(const String&) = 0;
};