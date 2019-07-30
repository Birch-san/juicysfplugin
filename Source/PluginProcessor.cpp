/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "MidiConstants.h"
#include "Util.h"
#include "GuiConstants.h"

using namespace std;
using Parameter = AudioProcessorValueTreeState::Parameter;

AudioProcessor* JUCE_CALLTYPE createPluginFilter();


//==============================================================================
JuicySFAudioProcessor::JuicySFAudioProcessor()
: AudioProcessor{getBusesProperties()}
, valueTreeState{
    *this,
    nullptr,
    "MYPLUGINSETTINGS",
    createParameterLayout()}
, fluidSynthModel{valueTreeState}
{
    valueTreeState.state.appendChild({ "uiState", {
            { "width", GuiConstants::minWidth },
            { "height", GuiConstants::minHeight }
        }, {} }, nullptr);
    valueTreeState.state.appendChild({ "soundFont", {
        { "path", "" },
    }, {} }, nullptr);
    // no properties, no subtrees (yet)
    valueTreeState.state.appendChild({ "banks", {}, {} }, nullptr);
    
    initialiseSynth();
}

AudioProcessorValueTreeState::ParameterLayout JuicySFAudioProcessor::createParameterLayout() {
    // https://stackoverflow.com/a/8469002/5257399
    unique_ptr<AudioParameterInt> params[] {
        // SoundFont 2.4 spec section 7.2: zero through 127, or 128.
        make_unique<AudioParameterInt>("bank", "which bank is selected in the soundfont", MidiConstants::midiMinValue, 128, MidiConstants::midiMinValue, "Bank" ),
        // note: banks may be sparse, and lack a 0th preset. so defend against this.
        make_unique<AudioParameterInt>("preset", "which patch (aka patch, program, instrument) is selected in the soundfont", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "Preset" ),
        make_unique<AudioParameterInt>("attack", "volume envelope attack time", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "A" ),
        make_unique<AudioParameterInt>("decay", "volume envelope sustain attentuation", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "D" ),
        make_unique<AudioParameterInt>("sustain", "volume envelope decay time", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "S" ),
        make_unique<AudioParameterInt>("release", "volume envelope release time", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "R" ),
        make_unique<AudioParameterInt>("filterCutOff", "low-pass filter cut-off frequency", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "Cut" ),
        make_unique<AudioParameterInt>("filterResonance", "low-pass filter resonance attentuation", MidiConstants::midiMinValue, MidiConstants::midiMaxValue, MidiConstants::midiMinValue, "Res" ),
    };
    
    return {
        make_move_iterator(begin(params)),
        make_move_iterator(end(params))
    };
}

JuicySFAudioProcessor::~JuicySFAudioProcessor()
{
}

void JuicySFAudioProcessor::initialiseSynth() {
    fluidSynthModel.initialise();
}

//==============================================================================
const String JuicySFAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool JuicySFAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool JuicySFAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double JuicySFAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int JuicySFAudioProcessor::getNumPrograms()
{
    return fluidSynthModel.getNumPrograms();   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int JuicySFAudioProcessor::getCurrentProgram()
{
    return fluidSynthModel.getCurrentProgram();
}

void JuicySFAudioProcessor::setCurrentProgram(int index)
{
    fluidSynthModel.setCurrentProgram(index);
}

const String JuicySFAudioProcessor::getProgramName(int index)
{
    return fluidSynthModel.getProgramName(index);
}

void JuicySFAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void JuicySFAudioProcessor::prepareToPlay (double sampleRate, int /*samplesPerBlock*/)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synth.setCurrentPlaybackSampleRate (sampleRate);
    keyboardState.reset();
    fluidSynthModel.setSampleRate(static_cast<float>(sampleRate));

    reset();
}

void JuicySFAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    keyboardState.reset();
}

bool JuicySFAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // Only mono/stereo and input/output must have same layout
    const AudioChannelSet& mainOutput = layouts.getMainOutputChannelSet();
    const AudioChannelSet& mainInput  = layouts.getMainInputChannelSet();

    // input and output layout must either be the same or the input must be disabled altogether
    if (! mainInput.isDisabled() && mainInput != mainOutput)
        return false;

    // do not allow disabling the main buses
    if (mainOutput.isDisabled())
        return false;

    // only allow stereo and mono
    return mainOutput.size() <= 2;
}

AudioProcessor::BusesProperties JuicySFAudioProcessor::getBusesProperties() {
    return BusesProperties()
            .withOutput ("Output", AudioChannelSet::stereo(), true);
}

void JuicySFAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    jassert (!isUsingDoublePrecision());

    // Now pass any incoming midi messages to our keyboard state object, and let it
    // add messages to the buffer if the user is clicking on the on-screen keys
    keyboardState.processNextMidiBuffer(midiMessages, 0, buffer.getNumSamples(), true);
    
    fluidSynthModel.processBlock(buffer, midiMessages);

    // and now get our synth to process these midi events and generate its output.
    // synth.renderNextBlock(buffer, midiMessages, 0, numSamples);

    // (see juce_VST3_Wrapper.cpp for the assertion this would trip otherwise)
    // we are !JucePlugin_ProducesMidiOutput, so clear remaining MIDI messages from our buffer
    midiMessages.clear();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
//    for (int i = getTotalNumInputChannels(); i < getTotalNumOutputChannels(); ++i)
//        buffer.clear (i, 0, numSamples);
}

//==============================================================================
bool JuicySFAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* JuicySFAudioProcessor::createEditor()
{
    // grab a raw pointer to it for our own use
    return /*pluginEditor = */new JuicySFAudioProcessorEditor (*this, valueTreeState);
}

//==============================================================================
void JuicySFAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    // Create an outer XML element..
    XmlElement xml{"MYPLUGINSETTINGS"};

    // Store the values of all our parameters, using their param ID as the XML attribute
    XmlElement* params{xml.createNewChildElement("params")};
    for (auto* param : getParameters()) {
         if (auto* p = dynamic_cast<AudioProcessorParameterWithID*> (param)) {
             params->setAttribute(p->paramID, p->getValue());
         }
    }
    {
        ValueTree tree{valueTreeState.state.getChildWithName("uiState")};
        XmlElement* newElement{xml.createNewChildElement("uiState")};
        {
            double value{tree.getProperty("width", GuiConstants::minWidth)};
            newElement->setAttribute("width", value);
        }
        {
            double value{tree.getProperty("height", GuiConstants::minHeight)};
            newElement->setAttribute("height", value);
        }
    }
    {
        ValueTree tree{valueTreeState.state.getChildWithName("soundFont")};
        XmlElement* newElement{xml.createNewChildElement("soundFont")};
        {
            String value{tree.getProperty("path", "")};
            newElement->setAttribute("path", value);
        }
    }
    
    DEBUG_PRINT(xml.createDocument("",false,false));
    
    copyXmlToBinary(xml, destData);
}

void JuicySFAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    shared_ptr<XmlElement> xmlState{getXmlFromBinary(data, sizeInBytes)};
    DEBUG_PRINT(xmlState->createDocument("",false,false));
    
    if (xmlState.get() != nullptr) {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName(valueTreeState.state.getType())) {
            XmlElement* params{xmlState->getChildByName("params")};
            if (params)
                for (auto* param : getParameters())
                    if (auto* p = dynamic_cast<AudioProcessorParameterWithID*>(param))
                        p->setValue(static_cast<float>(params->getDoubleAttribute(p->paramID, p->getValue())));
            
            {
                XmlElement* xmlElement{xmlState->getChildByName("soundFont")};
                if (xmlElement) {
                    ValueTree tree{valueTreeState.state.getChildWithName("soundFont")};
                    Value value{tree.getPropertyAsValue("path", nullptr)};
                    value = xmlElement->getStringAttribute("path", value.getValue());
                }
            }
            {
                ValueTree tree{valueTreeState.state.getChildWithName("uiState")};
                XmlElement* xmlElement{xmlState->getChildByName("uiState")};
                if (xmlElement) {
                    {
                        Value value{tree.getPropertyAsValue("width", nullptr)};
                        value = xmlElement->getIntAttribute("width", value.getValue());
                    }
                    {
                        Value value{tree.getPropertyAsValue("height", nullptr)};
                        value = xmlElement->getIntAttribute("height", value.getValue());
                    }
                }
            }
        }
    }
}

// FluidSynth only supports float in its process function, so that's all we can support.
bool JuicySFAudioProcessor::supportsDoublePrecisionProcessing() const {
    return false;
}

FluidSynthModel& JuicySFAudioProcessor::getFluidSynthModel() {
    return fluidSynthModel;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JuicySFAudioProcessor();
}
