# Juicy Soundfont Plugin

https://github.com/Birch-san/juicysfplugin

Targets Windows 7 i686
Commonly this means a 32-bit Intel or AMD processor.

## Installation

If the folder "C:\Program Files (x86)\Common Files\VST3" does not yet exist: make the folder yourself.  
If the folder "C:\Program Files (x86)\Common Files\VST2" does not yet exist: make the folder yourself.

VST2\libjuicysfplugin.dll -> "C:\Program Files (x86)\Common Files\VST2\libjuicysfplugin.dll"
VST3\juicysfplugin.vst3 -> "C:\Program Files (x86)\Common Files\VST3\juicysfplugin.vst3"
Standalone\juicysfplugin.exe -> "C:\Program Files (x86)\Birchlabs\juicysfplugin.exe"

### Upgrading from a previous version of juicysfplugin

Run the uninstaller that came with juicysfplugin, or delete the files that are described in these release notes:  
https://github.com/Birch-san/juicysfplugin/releases/tag/2.3.3

You may notice that opening SF3 soundfonts is slower than before.  
This is because juicysfplugin is now linked statically which means we can no longer use OpenMP to load SF3 soundfonts via multi-threading.  
(OpenMP does not support static linking on MinGW).  
The upside is that installation is now easier (single-file binary).

## Warning

The VST3 plugin is known to be incompatible with FL Studio (tested on v20.9, on Windows 11 ARM).  
The error message from FL Studio does not give any details explaining why the plugin is considered invalid.  
The VST3 plugin is nevertheless included, in case you fancy trying it with another DAW.

## Usage

Pick a soundfont from the file-picker (drag-and-drop works too).

### Soundfonts

Here's some soundfonts to get you started:

- Fatboy (no specific license stated, but described as "free")
  - https://fatboy.site/
- MuseScore's recommended soundfonts (includes MIT, GPL, other licenses)
  - https://musescore.org/en/handbook/soundfonts-and-sfz-files#list
- FlameStudios' guitar soundfonts (GPL-licensed)
  - http://www.flamestudios.org/free/Soundfonts
