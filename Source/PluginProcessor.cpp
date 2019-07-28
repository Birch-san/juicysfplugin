/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SoundfontSynthVoice.h"
#include "SoundfontSynthSound.h"
#include "ExposesComponents.h"
#include "MidiConstants.h"
#include "Util.h"
#include "SharesParams.h"
#include "Params.h"
#include "GuiConstants.h"

using namespace std;
using Parameter = AudioProcessorValueTreeState::Parameter;

AudioProcessor* JUCE_CALLTYPE createPluginFilter();


//==============================================================================
//, sharedParams{static_pointer_cast<SharesParams>(make_shared<Params>())}
JuicySFAudioProcessor::JuicySFAudioProcessor()
: AudioProcessor{getBusesProperties()}
// , sharedParams{}
, valueTreeState{
    *this,
    nullptr,
    "MYPLUGINSETTINGS",
    createParameterLayout()}
, fluidSynthModel{valueTreeState}
//, fluidSynthModel{*this}
//, pluginEditor(nullptr)
{
    valueTreeState.state.appendChild({ "uiState", {
            { "width", GuiConstants::minWidth },
            { "height", GuiConstants::minHeight }
        }, {} }, nullptr);
    valueTreeState.state.appendChild({ "soundFont", {
        { "path", "" },
    }, {} }, nullptr);
    // no properties, no subtrees (yet)
    // valueTreeState.state.appendChild({ "presets", {}, {} }, nullptr);
    // no properties, no subtrees (yet)
    valueTreeState.state.appendChild({ "banks", {}, {} }, nullptr);
    // valueTreeState.state.setProperty("soundFontPath", "", nullptr);
//    valueTreeState.state.appendChild({ "soundFontPath", {} }, nullptr);
    
    initialiseSynth();
}

AudioProcessorValueTreeState::ParameterLayout JuicySFAudioProcessor::createParameterLayout() {
    // std::vector<std::unique_ptr<AudioParameterInt>> params;

    // for (int i = 1; i < 9; ++i)
    //     params.push_back (std::make_unique<AudioParameterInt> (String (i), String (i), 0, i, 0));
    
    
//    make_unique<AudioParameter>("soundfontPath", "filepath to soundfont", 0, 127, 0, "A" ),

    // https://stackoverflow.com/a/8469002/5257399
    unique_ptr<AudioParameterInt> params[] {
        // make_unique<AudioParameterInt>("uiWidthPersist", "width of this plugin's GUI. Editor listens for changes (e.g. on load)", GuiConstants::minWidth, GuiConstants::maxWidth, GuiConstants::minWidth, "UI Width Persist" ),
        // make_unique<AudioParameterInt>("uiHeightPersist", "height of this plugin's GUI. Editor listens for changes (e.g. on load)", GuiConstants::minHeight, GuiConstants::maxHeight, GuiConstants::minHeight, "UI Height Persist" ),
        // make_unique<AudioParameterInt>("uiWidthTemp", "width of this plugin's GUI. Editor writes here on change (e.g. on window resize). Processor copies this into Persist before any save.", GuiConstants::minWidth, GuiConstants::maxWidth, GuiConstants::minWidth, "UI Width Temp" ),
        // make_unique<AudioParameterInt>("uiHeightTemp", "height of this plugin's GUI. Editor writes here on change (e.g. on window resize). Processor copies this into Persist before any save.", GuiConstants::minHeight, GuiConstants::maxHeight, GuiConstants::minHeight, "UI Height Temp" ),
    //    make_unique<AudioParameterInt>("uiWidth", "width of this plugin's GUI", GuiConstants::minWidth, GuiConstants::maxWidth, GuiConstants::minWidth, "UI Width" ),
    //    make_unique<AudioParameterInt>("uiHeight", "height of this plugin's GUI", GuiConstants::minHeight, GuiConstants::maxHeight, GuiConstants::minHeight, "UI Height" ),
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
//    delete fluidSynthModel;
}

void JuicySFAudioProcessor::initialiseSynth() {
    fluidSynthModel.initialise();

//    fluidSynth = fluidSynthModel.getSynth();

    // const int numVoices = 8;

    // Add some voices...
    // for (int i = numVoices; --i >= 0;)
    //     synth.addVoice(new SoundfontSynthVoice(fluidSynthModel.getSynth()));

    // ..and give the synth a sound to play
    // synth.addSound(new SoundfontSynthSound());
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
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int JuicySFAudioProcessor::getCurrentProgram()
{
    return 0;
}

void JuicySFAudioProcessor::setCurrentProgram (int index)
{
}

const String JuicySFAudioProcessor::getProgramName (int index)
{
    return {};
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
    const int numSamples{buffer.getNumSamples()};

    // Now pass any incoming midi messages to our keyboard state object, and let it
    // add messages to the buffer if the user is clicking on the on-screen keys
    keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);
    
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
//    sharedParams->setAttributesOnXml(xml);
//    auto state{valueTreeState.copyState()};
//    unique_ptr<XmlElement> xml{state.createXml()};
//    sharedParams.setAttributesOnXml(xml);

//    list<StateChangeSubscriber*>::iterator p;
//    for(p = stateChangeSubscribers.begin(); p != stateChangeSubscribers.end(); p++) {
//        (*p)->getStateInformation(xml);
//    }

    // Store the values of all our parameters, using their param ID as the XML attribute
    XmlElement* params{xml.createNewChildElement("params")};
    for (auto* param : getParameters()) {
         if (auto* p = dynamic_cast<AudioProcessorParameterWithID*> (param)) {
//             xml.setAttribute(p->paramID, p->getValue());
//             XmlElement* param{params->createNewChildElement("PARAM")};
//             param->setAttribute(p->paramID, p->getValue());
             params->setAttribute(p->paramID, p->getValue());
         }
    }
    {
        ValueTree tree{valueTreeState.state.getChildWithName("uiState")};
        XmlElement* newElement{xml.createNewChildElement("uiState")};
//        Value value{tree.getPropertyAsValue("width", nullptr)};
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
    
    // then use this helper function to stuff it into the binary blob and return it..
//    if (xml.get() != nullptr) {
//        copyXmlToBinary(*xml, destData);
//    }
    copyXmlToBinary(xml, destData);
}

void JuicySFAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    shared_ptr<XmlElement> xmlState{getXmlFromBinary(data, sizeInBytes)};
//    unique_ptr<XmlElement> xmlState{getXmlFromBinary(data, sizeInBytes)};
    DEBUG_PRINT(xmlState->createDocument("",false,false));
/*
 <MYPLUGINSETTINGS soundFontPath="">
 <PARAM id="attack" value="0.0"/>
 <PARAM id="bank" value="0.0"/>
 <PARAM id="decay" value="0.0"/>
 <PARAM id="filterCutOff" value="0.0"/>
 <PARAM id="filterResonance" value="0.0"/>
 <PARAM id="preset" value="0.0"/>
 <PARAM id="release" value="0.0"/>
 <PARAM id="sustain" value="0.0"/>
 <uiState width="722" height="300"/>
 </MYPLUGINSETTINGS>
 */
    if (xmlState.get() != nullptr) {
        // make sure that it's actually our type of XML object..
//        if (xmlState->hasTagName ("MYPLUGINSETTINGS")) {
        if (xmlState->hasTagName(valueTreeState.state.getType())) {
            // valueTreeState.replaceState(ValueTree::fromXml(*xmlState));
//            for (auto* param : getParameters())
//                if (auto* p = dynamic_cast<AudioProcessorParameterWithID*>(param))
//                    p->setValue(static_cast<float>(xmlState->getDoubleAttribute(p->paramID, p->getValue())));
            XmlElement* params{xmlState->getChildByName("params")};
            if (params) {
                for (auto* param : getParameters())
                    if (auto* p = dynamic_cast<AudioProcessorParameterWithID*>(param))
    //                    XmlElement* xmlParam{params->getChildByAttribute("id", p->paramID)};
    //                    p->setValue(static_cast<float>(xmlState->getDoubleAttribute(p->paramID, p->getValue())));
                        p->setValue(static_cast<float>(params->getDoubleAttribute(p->paramID, p->getValue())));
            }
            
            {
                // Value value{valueTreeState.state.getPropertyAsValue("soundFontPath", nullptr)};
                // value = xmlState->getStringAttribute("soundFontPath", value.getValue());
                XmlElement* xmlElement{xmlState->getChildByName("soundFont")};
                if (xmlElement) {
                    ValueTree tree{valueTreeState.state.getChildWithName("soundFont")};
                    Value value{tree.getPropertyAsValue("path", nullptr)};
                    value = xmlElement->getStringAttribute("path", value.getValue());
                }

                // valueTreeState.getParameter("soundFontPath")->getValue()
                // valueTreeState.getParameter("soundFontPath")->getValue();
                // RangedAudioParameter *param {valueTreeState.getParameter("release")};
                // jassert(dynamic_cast<AudioParameterInt*> (param) != nullptr);
                // AudioParameterInt* castParam {dynamic_cast<AudioParameterInt*> (param)};
                // *castParam = m.getControllerValue();
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
                
//                tree.getPropertyAsValue("width", nullptr)
//                tree.
//                valueTreeState.replaceState(ValueTree::fromXml(*xmlState))
//                value = xmlState->getStringAttribute("soundFontPath", value.getValue());
            }

//            list<StateChangeSubscriber*>::iterator p;
//            for(p = stateChangeSubscribers.begin(); p != stateChangeSubscribers.end(); p++) {
//                (*p)->setStateInformation(xmlState);
//            }

            // ok, now pull out our last window size..
//           sharedParams.loadAttributesFromXml(xmlState);

            // Now reload our parameters..
            
//            for (auto* param : getParameters())
//                if (auto* p = dynamic_cast<AudioProcessorParameterWithID*> (param))
//                    p->setValue ((float) xmlState->getDoubleAttribute (p->paramID, p->getValue()));
//
//            fluidSynthModel.onFileNameChanged(
//                sharedParams->getSoundFontPath(),
//                sharedParams->getBank(),
//                sharedParams->getPreset());
//
//            AudioProcessorEditor* editor{getActiveEditor()};
//            if (editor != nullptr) {
//                editor->setSize(
//                    sharedParams->getUiWidth(),
//                    sharedParams->getUiHeight());
//
//                jassert(dynamic_cast<ExposesComponents*> (editor) != nullptr);
//                ExposesComponents* exposesComponents = dynamic_cast<ExposesComponents*> (editor);
//                exposesComponents->getFilePicker().setDisplayedFilePath(sharedParams->getSoundFontPath());
//            }

//            const String& currentSoundFontAbsPath = fluidSynthModel->getCurrentSoundFontAbsPath();
//            if (currentSoundFontAbsPath.isNotEmpty()) {
//                fileChooser.setCurrentFile(File(currentSoundFontAbsPath), true, dontSendNotification);
//            }
        }
    }
}

//void JuicySFAudioProcessor::subscribeToStateChanges(StateChangeSubscriber* subscriber) {
//    stateChangeSubscribers.push_back(subscriber);
//}
//
//void JuicySFAudioProcessor::unsubscribeFromStateChanges(StateChangeSubscriber* subscriber) {
//    stateChangeSubscribers.remove(subscriber);
//}

// FluidSynth only supports float in its process function, so that's all we can support.
bool JuicySFAudioProcessor::supportsDoublePrecisionProcessing() const {
    return false;
}

FluidSynthModel& JuicySFAudioProcessor::getFluidSynthModel() {
    return fluidSynthModel;
}

//SharesParams& JuicySFAudioProcessor::getSharedParams() {
//    return sharedParams;
//}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JuicySFAudioProcessor();
}
