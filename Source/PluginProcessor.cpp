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

AudioProcessor* JUCE_CALLTYPE createPluginFilter();


//==============================================================================
JuicySFAudioProcessor::JuicySFAudioProcessor()
     : AudioProcessor (getBusesProperties()),
       lastUIWidth(400),
       lastUIHeight(300),
       soundFontPath(String()),
       lastPreset(-1),
       lastBank(-1),
       fluidSynthModel(*this)/*,
       pluginEditor(nullptr)*/
{
    initialiseSynth();
}

JuicySFAudioProcessor::~JuicySFAudioProcessor()
{
//    delete fluidSynthModel;
}

void JuicySFAudioProcessor::initialiseSynth() {
    fluidSynthModel.initialise();

    fluidSynth = fluidSynthModel.getSynth();

    const int numVoices = 8;

    // Add some voices...
    for (int i = numVoices; --i >= 0;)
        synth.addVoice (new SoundfontSynthVoice(fluidSynthModel.getSynth()));

    // ..and give the synth a sound to play
    synth.addSound (new SoundfontSynthSound());
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

void JuicySFAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    jassert (!isUsingDoublePrecision());
    const int numSamples = buffer.getNumSamples();

    // Now pass any incoming midi messages to our keyboard state object, and let it
    // add messages to the buffer if the user is clicking on the on-screen keys
    keyboardState.processNextMidiBuffer (midiMessages, 0, numSamples, true);
    
    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    
    // TODO: factor into a MidiCollector
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);) {
        Logger::outputDebugString ( m.getDescription() );
        
        // explicitly not handling note_on/off, or pitch_bend, because these are (for better or worse)
        // responsibilities of SoundfontSynthVoice.
        // well, by that logic maybe I should move program change onto Voice. but it doesn't feel like a per-voice concern.
        if (m.isController()) {
            fluid_midi_event_t *midi_event(new_fluid_midi_event());
            fluid_midi_event_set_type(midi_event, static_cast<int>(CONTROL_CHANGE));
            fluid_midi_event_set_channel(midi_event, fluidSynthModel.getChannel());
            fluid_midi_event_set_control(midi_event, m.getControllerNumber());
            fluid_midi_event_set_value(midi_event, m.getControllerValue());
            fluid_synth_handle_midi_event(fluidSynth, midi_event);
            delete_fluid_midi_event(midi_event);
        } else if (m.isProgramChange()) {
            fluid_midi_event_t *midi_event(new_fluid_midi_event());
            fluid_midi_event_set_type(midi_event, static_cast<int>(PROGRAM_CHANGE));
            fluid_midi_event_set_channel(midi_event, fluidSynthModel.getChannel());
            fluid_midi_event_set_program(midi_event, m.getProgramChangeNumber());
            fluid_synth_handle_midi_event(fluidSynth, midi_event);
            delete_fluid_midi_event(midi_event);
        } else if (m.isChannelPressure()) {
            fluid_midi_event_t *midi_event(new_fluid_midi_event());
            fluid_midi_event_set_type(midi_event, static_cast<int>(CHANNEL_PRESSURE));
            fluid_midi_event_set_channel(midi_event, fluidSynthModel.getChannel());
            fluid_midi_event_set_program(midi_event, m.getChannelPressureValue());
            fluid_synth_handle_midi_event(fluidSynth, midi_event);
            delete_fluid_midi_event(midi_event);
        } else if (m.isResetAllControllers()) {
            fluid_midi_event_t *midi_event(new_fluid_midi_event());
            fluid_midi_event_set_type(midi_event, static_cast<int>(MIDI_SYSTEM_RESET));
            fluid_synth_handle_midi_event(fluidSynth, midi_event);
            delete_fluid_midi_event(midi_event);
        } else if (m.isSysEx()) {
            fluid_midi_event_t *midi_event(new_fluid_midi_event());
            fluid_midi_event_set_type(midi_event, static_cast<int>(MIDI_SYSEX));
            // I assume that the MidiMessage's sysex buffer would be freed anyway when MidiMessage is destroyed, so set dynamic=false
            // to ensure that fluidsynth does not attempt to free the sysex buffer during delete_fluid_midi_event()
            fluid_midi_event_set_sysex(midi_event, const_cast<juce::uint8*>(m.getSysExData()), m.getSysExDataSize(), static_cast<int>(false));
            fluid_synth_handle_midi_event(fluidSynth, midi_event);
            delete_fluid_midi_event(midi_event);
        }
    }

    // and now get our synth to process these midi events and generate its output.
    synth.renderNextBlock (buffer, midiMessages, 0, numSamples);
    fluid_synth_process(fluidSynth, numSamples, 0, nullptr, buffer.getNumChannels(), buffer.getArrayOfWritePointers());

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
    return /*pluginEditor = */new JuicySFAudioProcessorEditor (*this);
}

//==============================================================================
void JuicySFAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    // Create an outer XML element..
    XmlElement xml ("MYPLUGINSETTINGS");

    // add some attributes to it..
    xml.setAttribute ("uiWidth", lastUIWidth);
    xml.setAttribute ("uiHeight", lastUIHeight);
    xml.setAttribute ("soundFontPath", soundFontPath);
    xml.setAttribute ("preset", lastPreset);
    xml.setAttribute ("bank", lastBank);

//    list<StateChangeSubscriber*>::iterator p;
//    for(p = stateChangeSubscribers.begin(); p != stateChangeSubscribers.end(); p++) {
//        (*p)->getStateInformation(xml);
//    }

    // Store the values of all our parameters, using their param ID as the XML attribute
    for (auto* param : getParameters())
        if (auto* p = dynamic_cast<AudioProcessorParameterWithID*> (param))
            xml.setAttribute (p->paramID, p->getValue());

    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
}

void JuicySFAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState != nullptr)
    {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName ("MYPLUGINSETTINGS"))
        {
//            list<StateChangeSubscriber*>::iterator p;
//            for(p = stateChangeSubscribers.begin(); p != stateChangeSubscribers.end(); p++) {
//                (*p)->setStateInformation(xmlState);
//            }

            // ok, now pull out our last window size..
            lastUIWidth  = jmax (xmlState->getIntAttribute ("uiWidth", lastUIWidth), 400);
            lastUIHeight = jmax (xmlState->getIntAttribute ("uiHeight", lastUIHeight), 300);
            soundFontPath = xmlState->getStringAttribute ("soundFontPath", soundFontPath);
            lastPreset = xmlState->getIntAttribute ("preset", lastPreset);
            lastBank = xmlState->getIntAttribute ("bank", lastBank);

            // Now reload our parameters..
            for (auto* param : getParameters())
                if (auto* p = dynamic_cast<AudioProcessorParameterWithID*> (param))
                    p->setValue ((float) xmlState->getDoubleAttribute (p->paramID, p->getValue()));

            fluidSynthModel.onFileNameChanged(soundFontPath, lastBank, lastPreset);

            AudioProcessorEditor* editor = getActiveEditor();
            if (editor != nullptr) {
                editor->setSize(lastUIWidth, lastUIHeight);

                jassert(dynamic_cast<ExposesComponents*> (editor) != nullptr);
                ExposesComponents* exposesComponents = dynamic_cast<ExposesComponents*> (editor);
                exposesComponents->getFilePicker().setDisplayedFilePath(soundFontPath);
            }

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

FluidSynthModel* JuicySFAudioProcessor::getFluidSynthModel() {
    return &fluidSynthModel;
}

void JuicySFAudioProcessor::setSoundFontPath(const String& value) {
    soundFontPath = value;
}

String& JuicySFAudioProcessor::getSoundFontPath() {
    return soundFontPath;
}
int JuicySFAudioProcessor::getPreset() {
    return lastPreset;
}
int JuicySFAudioProcessor::getBank() {
    return lastBank;
}
void JuicySFAudioProcessor::setPreset(int preset) {
    lastPreset = preset;
}
void JuicySFAudioProcessor::setBank(int bank) {
    lastBank = bank;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JuicySFAudioProcessor();
}
