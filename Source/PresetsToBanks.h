// http://www.synthfont.com/Tutorial6.html
// a bank can hold many (128) presets
// bank 128 is reserved for percussion

#pragma once

#include "Preset.h"
#include <map>

typedef std::multimap<int, Preset> BanksToPresets;