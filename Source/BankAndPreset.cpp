//
// Created by Alex Birch on 13/04/2018.
// Copyright (c) 2018 Birchlabs. All rights reserved.
//

#include "BankAndPreset.h"

BankAndPreset::BankAndPreset(int bank, int preset)
        : bank(bank),
          preset(preset)
{}

int BankAndPreset::getBank() {
    return bank;
}

int BankAndPreset::getPreset() {
    return preset;
}