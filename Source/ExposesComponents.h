//
// Created by Alex Birch on 11/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#pragma once

#include "FilePickerFragment.h"

class ExposesComponents {
public:
    virtual ~ExposesComponents() {}

    virtual FilePickerFragment& getFilePicker() = 0;

};