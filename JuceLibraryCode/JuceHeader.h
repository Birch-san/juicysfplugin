/*
    IMPORTANT! This file is auto-generated.
    If you alter its contents, your changes may be overwritten!

    This is the header file that your files should include in order to get all the
    JUCE library headers. You should avoid including the JUCE headers directly in
    your own source files, because that wouldn't pick up the correct configuration
    options for your app.

*/

#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include <juce_events/juce_events.h>
#include <juce_audio_formats/juce_audio_formats.h>
#include <juce_audio_plugin_client/juce_audio_plugin_client.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_data_structures/juce_data_structures.h>
#include <juce_audio_utils/juce_audio_utils.h>


#if JUCE_TARGET_HAS_BINARY_DATA
 #include "BinaryData.h"
#endif

#if ! DONT_SET_USING_JUCE_NAMESPACE
 // If your code uses a lot of JUCE classes, then this will obviously save you
 // a lot of typing, but can be disabled by setting DONT_SET_USING_JUCE_NAMESPACE.
 using namespace juce;
#endif

using juce::AudioBuffer;
using juce::AudioChannelSet;
using juce::AudioParameterInt;
using juce::AudioProcessor;
using juce::AudioProcessorEditor;
using juce::AudioProcessorParameterWithID;
using juce::AudioProcessorValueTreeState;
using juce::BorderSize;
using juce::Button;
using juce::Colour;
using juce::Component;
using juce::dontSendNotification;
using juce::File;
using juce::FilenameComponent;
using juce::FilenameComponentListener;
using juce::Font;
using juce::Graphics;
using juce::GroupComponent;
using juce::Identifier;
using juce::jmax;
using juce::Justification;
using juce::KeyPress;
using juce::Label;
using juce::ListBox;
using juce::Logger;
using juce::LookAndFeel_V4;
using juce::LookAndFeel;
using juce::MemoryBlock;
using juce::MessageManagerLock;
using juce::MidiBuffer;
using juce::MidiKeyboardState;
using juce::MidiMessage;
using juce::NotificationType;
using juce::RangedAudioParameter;
using juce::Rectangle;
using juce::ResizableWindow;
using juce::Slider;
using juce::String;
using juce::StringArray;
using juce::StringRef;
using juce::Synthesiser;
using juce::TableHeaderComponent;
using juce::TableListBox;
using juce::TableListBoxModel;
using juce::TextButton;
using juce::Value;
using juce::ValueTree;
using juce::var;
using juce::XmlElement;

#if ! JUCE_DONT_DECLARE_PROJECTINFO
namespace ProjectInfo
{
    const char* const  projectName    = "juicysfplugin";
    const char* const  companyName    = "Birchlabs";
    const char* const  versionString  = "3.0.0";
    const int          versionNumber  =  0x30000;
}
#endif
