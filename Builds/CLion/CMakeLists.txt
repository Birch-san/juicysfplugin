# Automatically generated CMakeLists, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required (VERSION 3.4.1)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug"  CACHE STRING "Choose the type of build." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

###############################################################################
# Xcode (MacOSX)
###############################################################################

if (APPLE)

project ("juicysfplugin" C CXX)

add_library (VST MODULE
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST2.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_VST2.cpp"
)

set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)

add_library (VST3 MODULE
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp"
)

set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)

add_executable (STANDALONE_PLUGIN
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_Standalone.cpp"
)

set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)

add_library (SHARED_CODE STATIC
    "../../Source/BankAndPreset.cpp"
    "../../Source/BankAndPreset.h"
    "../../Source/ExposesComponents.h"
    "../../Source/FilePickerFragment.h"
    "../../Source/FilePicker.cpp"
    "../../Source/FilePicker.h"
    "../../Source/FluidSynthModel.cpp"
    "../../Source/FluidSynthModel.h"
    "../../Source/MyColours.cpp"
    "../../Source/MyColours.h"
    "../../Source/Pills.cpp"
    "../../Source/Pills.h"
    "../../Source/Preset.cpp"
    "../../Source/Preset.h"
    "../../Source/PresetsToBanks.h"
    "../../Source/SoundfontSynthSound.cpp"
    "../../Source/SoundfontSynthSound.h"
    "../../Source/SoundfontSynthVoice.cpp"
    "../../Source/SoundfontSynthVoice.h"
    "../../Source/SurjectiveMidiKeyboardComponent.cpp"
    "../../Source/SurjectiveMidiKeyboardComponent.h"
    "../../Source/TableComponent.cpp"
    "../../Source/TableComponent.h"
    "../../Source/TablesComponent.cpp"
    "../../Source/TablesComponent.h"
    "../../Source/PluginProcessor.cpp"
    "../../Source/PluginProcessor.h"
    "../../Source/PluginEditor.cpp"
    "../../Source/PluginEditor.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/all.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/assert.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/callback.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/compat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/export.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/format.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.mm"
    "../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Array.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SparseSet.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_File.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_File.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../../../../../Applications/JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../../../../../Applications/JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Random.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Range.h"
    "../../../../../../Applications/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../../../../../Applications/JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Result.h"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../../../../../Applications/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_Socket.h"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_URL.h"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../../../../../Applications/JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_Base64.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_String.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_String.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Process.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../../../../../Applications/JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/time/juce_Time.h"
    "../../../../../../Applications/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../../../../../Applications/JUCE/modules/juce_core/juce_core.cpp"
    "../../../../../../Applications/JUCE/modules/juce_core/juce_core.mm"
    "../../../../../../Applications/JUCE/modules/juce_core/juce_core.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_Primes.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_MD5.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.cpp"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.mm"
    "../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_Message.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../../../../../Applications/JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../../../../../Applications/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../../../../../Applications/JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../../../../../Applications/JUCE/modules/juce_events/juce_events.cpp"
    "../../../../../../Applications/JUCE/modules/juce_events/juce_events.mm"
    "../../../../../../Applications/JUCE/modules/juce_events/juce_events.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Desktop.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.cpp"
    "../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.mm"
    "../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.h"
    "../../../../../../Applications/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp"
    "../../../../../../Applications/JUCE/modules/juce_video/capture/juce_CameraDevice.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_android_CameraDevice.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_ios_CameraDevice.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_mac_Video.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h"
    "../../../../../../Applications/JUCE/modules/juce_video/native/juce_win32_Video.h"
    "../../../../../../Applications/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp"
    "../../../../../../Applications/JUCE/modules/juce_video/playback/juce_VideoComponent.h"
    "../../../../../../Applications/JUCE/modules/juce_video/juce_video.cpp"
    "../../../../../../Applications/JUCE/modules/juce_video/juce_video.mm"
    "../../../../../../Applications/JUCE/modules/juce_video/juce_video.h"
    "../../JuceLibraryCode/AppConfig.h"
    "../../JuceLibraryCode/include_juce_audio_basics.mm"
    "../../JuceLibraryCode/include_juce_audio_devices.mm"
    "../../JuceLibraryCode/include_juce_audio_formats.mm"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp"
    "../../JuceLibraryCode/include_juce_audio_plugin_client_VST_utils.mm"
    "../../JuceLibraryCode/include_juce_audio_processors.mm"
    "../../JuceLibraryCode/include_juce_audio_utils.mm"
    "../../JuceLibraryCode/include_juce_core.mm"
    "../../JuceLibraryCode/include_juce_cryptography.mm"
    "../../JuceLibraryCode/include_juce_data_structures.mm"
    "../../JuceLibraryCode/include_juce_events.mm"
    "../../JuceLibraryCode/include_juce_graphics.mm"
    "../../JuceLibraryCode/include_juce_gui_basics.mm"
    "../../JuceLibraryCode/include_juce_gui_extra.mm"
    "../../JuceLibraryCode/include_juce_opengl.mm"
    "../../JuceLibraryCode/include_juce_video.mm"
    "../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties ("../../Source/BankAndPreset.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/ExposesComponents.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/FilePickerFragment.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/FilePicker.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/FluidSynthModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/MyColours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Pills.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/Preset.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PresetsToBanks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/SoundfontSynthSound.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/SoundfontSynthVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/SurjectiveMidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/TableComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/TablesComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../Source/PluginEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_CatmullRomInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LagrangeInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_LinearSmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/effects/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiInput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/midi_io/juce_MidiOutput.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.2/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBaseHelper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewControl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUCarbonViewDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUInputFormatConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUMIDIBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUOutputElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUPlugInDispatch.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUScopeElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUSilentTimeout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUTimestampGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/AUViewLocalizedStringKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAtomicStack.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAudioChannelLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAUParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAAutoDisposer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CADebugPrintf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAHostTimeBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAMutex.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CarbonEventHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAReferenceCounted.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAStreamBasicDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAThreadSafeList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnit.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAVectorUnitTypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/CAXException.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/ComponentBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/AU/CoreAudioUtilityClasses/MusicDeviceBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterApp.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_CarbonVisibility.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_CheckSettingMacros.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_FakeMouseMoveGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeModuleHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_IncludeSystemHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/utility/juce_WindowsHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/VST/juce_VSTCallbackHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_plugin_client/juce_audio_plugin_client.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTInterface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_BlowFish.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_Primes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_Primes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/encryption/juce_RSAKey.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_MD5.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_MD5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_SHA256.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_SHA256.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/hashing/juce_Whirlpool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_cryptography/juce_cryptography.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Quaternion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/geometry/juce_Vector3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_android.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_opengl/juce_opengl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/capture/juce_CameraDevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/capture/juce_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_android_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_ios_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_mac_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_mac_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_win32_CameraDevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/native/juce_win32_Video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/playback/juce_VideoComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/playback/juce_VideoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/juce_video.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/juce_video.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../../../../../Applications/JUCE/modules/juce_video/juce_video.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties ("../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

set_target_properties (SHARED_CODE PROPERTIES SUFFIX ".a")

#------------------------------------------------------------------------------
# Config: Debug
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Debug)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

target_include_directories (VST PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (VST PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=1"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=0"
)

target_compile_options (VST PRIVATE
    -mmacosx-version-min=10.11
    -O0
    -stdlib=libc++
)

set_target_properties (VST PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_DEPLOYMENT_LOCATION YES
    XCODE_ATTRIBUTE_DSTROOT /
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_GENERATE_PKGINFO_FILE YES
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-VST.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_INSTALL_PATH "$(HOME)/Library/Audio/Plug-Ins/VST/"
    XCODE_ATTRIBUTE_LIBRARY_STYLE Bundle
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    XCODE_ATTRIBUTE_WRAPPER_EXTENSION vst
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-VST.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    BUNDLE TRUE
    BUNDLE_EXTENSION vst
    XCODE_ATTRIBUTE_MACH_O_TYPE "mh_bundle"
)

target_link_libraries (VST PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

add_custom_command (TARGET VST POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory "$ENV{HOME}/Library/Audio/Plug-Ins/VST/juicysfplugin.vst"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/juicysfplugin.vst" "$ENV{HOME}/Library/Audio/Plug-Ins/VST/juicysfplugin.vst"
    COMMENT "Copying \"juicysfplugin.vst\" to \"$ENV{HOME}/Library/Audio/Plug-Ins/VST/\""
)

target_include_directories (VST3 PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (VST3 PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=1"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=0"
)

target_compile_options (VST3 PRIVATE
    -mmacosx-version-min=10.11
    -O0
    -stdlib=libc++
)

set_target_properties (VST3 PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_DEPLOYMENT_LOCATION YES
    XCODE_ATTRIBUTE_DSTROOT /
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_GENERATE_PKGINFO_FILE YES
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-VST3.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_INSTALL_PATH "$(HOME)/Library/Audio/Plug-Ins/VST3/"
    XCODE_ATTRIBUTE_LIBRARY_STYLE Bundle
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    XCODE_ATTRIBUTE_WRAPPER_EXTENSION vst3
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-VST3.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    BUNDLE TRUE
    BUNDLE_EXTENSION vst3
    XCODE_ATTRIBUTE_MACH_O_TYPE "mh_bundle"
)

target_link_libraries (VST3 PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

add_custom_command (TARGET VST3 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory "$ENV{HOME}/Library/Audio/Plug-Ins/VST3/juicysfplugin.vst3"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/juicysfplugin.vst3" "$ENV{HOME}/Library/Audio/Plug-Ins/VST3/juicysfplugin.vst3"
    COMMENT "Copying \"juicysfplugin.vst3\" to \"$ENV{HOME}/Library/Audio/Plug-Ins/VST3/\""
)

target_include_directories (STANDALONE_PLUGIN PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
)

target_compile_options (STANDALONE_PLUGIN PRIVATE
    -mmacosx-version-min=10.11
    -O0
    -stdlib=libc++
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Debug-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    MACOSX_BUNDLE TRUE
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

target_include_directories (SHARED_CODE PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (SHARED_CODE PRIVATE
    "_DEBUG=1"
    "DEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=1"
    "JucePlugin_Build_VST3=1"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
    "JUCE_SHARED_CODE=1"
)

target_compile_options (SHARED_CODE PRIVATE
    -mmacosx-version-min=10.11
    -O0
    -stdlib=libc++
)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_COPY_PHASE_STRIP NO
    XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC NO
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INSTALL_PATH "@executable_path/../Frameworks"
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
)

target_link_libraries (SHARED_CODE PRIVATE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -Wswitch -Wunused-variable -Wparentheses -Wnon-virtual-dtor -Wshorten-64-to-32 -Wundeclared-selector -Wuninitialized -Wunused-function -Wbool-conversion -Wcomma -Wconstant-conversion -Wempty-body -Wenum-conversion -Winfinite-recursion -Wint-conversion -Wrange-loop-analysis -Wstrict-prototypes -Wmove -Wunreachable-code -Wduplicate-method-match -Wreorder -fvisibility-inlines-hidden")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

endif (CMAKE_BUILD_TYPE STREQUAL Debug)

#------------------------------------------------------------------------------
# Config: Release
#------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL Release)

execute_process (COMMAND uname -m OUTPUT_VARIABLE JUCE_ARCH_LABEL OUTPUT_STRIP_TRAILING_WHITESPACE)

target_include_directories (VST PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (VST PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=1"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=0"
)

target_compile_options (VST PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
    -stdlib=libc++
)

set_target_properties (VST PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_DEPLOYMENT_LOCATION YES
    XCODE_ATTRIBUTE_DSTROOT /
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_GENERATE_PKGINFO_FILE YES
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-VST.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_INSTALL_PATH "$(HOME)/Library/Audio/Plug-Ins/VST/"
    XCODE_ATTRIBUTE_LIBRARY_STYLE Bundle
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    XCODE_ATTRIBUTE_WRAPPER_EXTENSION vst
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-VST.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    BUNDLE TRUE
    BUNDLE_EXTENSION vst
    XCODE_ATTRIBUTE_MACH_O_TYPE "mh_bundle"
)

target_link_libraries (VST PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

add_custom_command (TARGET VST POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory "$ENV{HOME}/Library/Audio/Plug-Ins/VST/juicysfplugin.vst"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/juicysfplugin.vst" "$ENV{HOME}/Library/Audio/Plug-Ins/VST/juicysfplugin.vst"
    COMMENT "Copying \"juicysfplugin.vst\" to \"$ENV{HOME}/Library/Audio/Plug-Ins/VST/\""
)

target_include_directories (VST3 PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (VST3 PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=1"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=0"
)

target_compile_options (VST3 PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
    -stdlib=libc++
)

set_target_properties (VST3 PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_DEPLOYMENT_LOCATION YES
    XCODE_ATTRIBUTE_DSTROOT /
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_GENERATE_PKGINFO_FILE YES
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-VST3.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_INSTALL_PATH "$(HOME)/Library/Audio/Plug-Ins/VST3/"
    XCODE_ATTRIBUTE_LIBRARY_STYLE Bundle
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    XCODE_ATTRIBUTE_WRAPPER_EXTENSION vst3
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-VST3.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    BUNDLE TRUE
    BUNDLE_EXTENSION vst3
    XCODE_ATTRIBUTE_MACH_O_TYPE "mh_bundle"
)

target_link_libraries (VST3 PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

add_custom_command (TARGET VST3 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory "$ENV{HOME}/Library/Audio/Plug-Ins/VST3/juicysfplugin.vst3"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/juicysfplugin.vst3" "$ENV{HOME}/Library/Audio/Plug-Ins/VST3/juicysfplugin.vst3"
    COMMENT "Copying \"juicysfplugin.vst3\" to \"$ENV{HOME}/Library/Audio/Plug-Ins/VST3/\""
)

target_include_directories (STANDALONE_PLUGIN PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (STANDALONE_PLUGIN PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=0"
    "JucePlugin_Build_VST3=0"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
)

target_compile_options (STANDALONE_PLUGIN PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
    -stdlib=libc++
)

set_target_properties (STANDALONE_PLUGIN PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INFOPLIST_FILE "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS NO
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
    MACOSX_BUNDLE_INFO_PLIST "/Users/birch/git/juicysfplugin/Builds/CLion/Release-Info-Standalone_Plugin.plist"
    XCODE_ATTRIBUTE_PRODUCT_NAME "juicysfplugin"
    MACOSX_BUNDLE TRUE
)

target_link_libraries (STANDALONE_PLUGIN PRIVATE
    SHARED_CODE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

target_include_directories (SHARED_CODE PRIVATE
    "$ENV{HOME}/SDKs/VST_SDK/VST3_SDK"
    "../../JuceLibraryCode"
    "/Applications/JUCE/modules"
    "../../include"
    "../../modules"
    "/Applications/JUCE/modules/juce_audio_plugin_client"
)

target_compile_definitions (SHARED_CODE PRIVATE
    "_NDEBUG=1"
    "NDEBUG=1"
    "JUCER_XCODE_MAC_F6D2F4CF=1"
    "JUCE_APP_VERSION=1.0.0"
    "JUCE_APP_VERSION_HEX=0x10000"
    "JucePlugin_Build_VST=1"
    "JucePlugin_Build_VST3=1"
    "JucePlugin_Build_AU=0"
    "JucePlugin_Build_AUv3=0"
    "JucePlugin_Build_RTAS=0"
    "JucePlugin_Build_AAX=0"
    "JucePlugin_Build_Standalone=1"
    "JUCE_SHARED_CODE=1"
)

target_compile_options (SHARED_CODE PRIVATE
    -mmacosx-version-min=10.11
    -O3
    -flto
    -stdlib=libc++
)

set_target_properties (SHARED_CODE PROPERTIES
    OUTPUT_NAME "juicysfplugin"
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    XCODE_ATTRIBUTE_CLANG_LINK_OBJC_RUNTIME NO
    XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES YES
    XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "$(PROJECT_DIR)/build/$(CONFIGURATION)"
    XCODE_ATTRIBUTE_DEAD_CODE_STRIPPING YES
    XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS NO
    XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
    XCODE_ATTRIBUTE_GCC_VERSION com.apple.compilers.llvm.clang.1_0
    XCODE_ATTRIBUTE_INSTALL_PATH "@executable_path/../Frameworks"
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET_ppc 10.4
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER uk.co.birchlabs.juicysfplugin
    XCODE_ATTRIBUTE_SDKROOT_ppc macosx10.5
    XCODE_ATTRIBUTE_USE_HEADERMAP NO
)

target_link_libraries (SHARED_CODE PRIVATE
    "-Llib"
    "-lfluidsynth"
    "-framework Accelerate"
    "-framework AudioToolbox"
    "-framework AVFoundation"
    "-framework AVKit"
    "-framework Carbon"
    "-framework Cocoa"
    "-framework CoreAudio"
    "-framework CoreMedia"
    "-framework CoreMIDI"
    "-framework DiscRecording"
    "-framework IOKit"
    "-framework OpenGL"
    "-framework QuartzCore"
    "-framework WebKit"
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-common -Wswitch -Wunused-variable -Wparentheses -Wnon-virtual-dtor -Wshorten-64-to-32 -Wundeclared-selector -Wuninitialized -Wunused-function -Wbool-conversion -Wcomma -Wconstant-conversion -Wempty-body -Wenum-conversion -Winfinite-recursion -Wint-conversion -Wrange-loop-analysis -Wstrict-prototypes -Wmove -Wunreachable-code -Wduplicate-method-match -Wreorder -fvisibility-inlines-hidden")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

endif (CMAKE_BUILD_TYPE STREQUAL Release)

endif()

