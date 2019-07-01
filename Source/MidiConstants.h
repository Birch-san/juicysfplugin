#pragma once

/* Taken from:
 * fluidsynth/src/midi/fluid_midi.h
 * fluidsynth/src/utils/fluid_conv_tables.h
 * https://github.com/FluidSynth/fluidsynth/blob/master/src/midi/fluid_midi.h
 * https://github.com/FluidSynth/fluidsynth/blob/master/src/utils/fluid_conv_tables.h
 *
 * FluidSynth - A Software Synthesizer
 *
 * Copyright (C) 2003  Peter Hanappe and others.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

enum fluid_midi_event_type
{
    /* channel messages */
    NOTE_OFF = 0x80,
    NOTE_ON = 0x90,
    KEY_PRESSURE = 0xa0,
    CONTROL_CHANGE = 0xb0,
    PROGRAM_CHANGE = 0xc0,
    CHANNEL_PRESSURE = 0xd0,
    PITCH_BEND = 0xe0,
    /* system exclusive */
    MIDI_SYSEX = 0xf0,
    /* system common - never in midi files */
    MIDI_TIME_CODE = 0xf1,
    MIDI_SONG_POSITION = 0xf2,
    MIDI_SONG_SELECT = 0xf3,
    MIDI_TUNE_REQUEST = 0xf6,
    MIDI_EOX = 0xf7,
    /* system real-time - never in midi files */
    MIDI_SYNC = 0xf8,
    MIDI_TICK = 0xf9,
    MIDI_START = 0xfa,
    MIDI_CONTINUE = 0xfb,
    MIDI_STOP = 0xfc,
    MIDI_ACTIVE_SENSING = 0xfe,
    MIDI_SYSTEM_RESET = 0xff,
    /* meta event - for midi files only */
    MIDI_META_EVENT = 0xff
};

enum fluid_midi_control_change
{
    BANK_SELECT_MSB = 0x00,
    MODULATION_MSB = 0x01,
    BREATH_MSB = 0x02,
    FOOT_MSB = 0x04,
    PORTAMENTO_TIME_MSB = 0x05,
    DATA_ENTRY_MSB = 0x06,
    VOLUME_MSB = 0x07,
    BALANCE_MSB = 0x08,
    PAN_MSB = 0x0A,
    EXPRESSION_MSB = 0x0B,
    EFFECTS1_MSB = 0x0C,
    EFFECTS2_MSB = 0x0D,
    GPC1_MSB = 0x10, /* general purpose controller */
    GPC2_MSB = 0x11,
    GPC3_MSB = 0x12,
    GPC4_MSB = 0x13,
    BANK_SELECT_LSB = 0x20,
    MODULATION_WHEEL_LSB = 0x21,
    BREATH_LSB = 0x22,
    FOOT_LSB = 0x24,
    PORTAMENTO_TIME_LSB = 0x25,
    DATA_ENTRY_LSB = 0x26,
    VOLUME_LSB = 0x27,
    BALANCE_LSB = 0x28,
    PAN_LSB = 0x2A,
    EXPRESSION_LSB = 0x2B,
    EFFECTS1_LSB = 0x2C,
    EFFECTS2_LSB = 0x2D,
    GPC1_LSB = 0x30,
    GPC2_LSB = 0x31,
    GPC3_LSB = 0x32,
    GPC4_LSB = 0x33,
    SUSTAIN_SWITCH = 0x40,
    PORTAMENTO_SWITCH = 0x41,
    SOSTENUTO_SWITCH = 0x42,
    SOFT_PEDAL_SWITCH = 0x43,
    LEGATO_SWITCH = 0x44,
    HOLD2_SWITCH = 0x45,
    SOUND_CTRL1 = 0x46,
    SOUND_CTRL2 = 0x47, // MIDI CC 71 Timbre/Harmonic Intensity (filter resonance)
    SOUND_CTRL3 = 0x48, // MIDI CC 72 Release time
    SOUND_CTRL4 = 0x49, // MIDI CC 73 Attack time
    SOUND_CTRL5 = 0x4A, // MIDI CC 74 Brightness (cutoff frequency, FILTERFC)
    SOUND_CTRL6 = 0x4B, // MIDI CC 75 Decay Time
    SOUND_CTRL7 = 0x4C,
    SOUND_CTRL8 = 0x4D,
    SOUND_CTRL9 = 0x4E,
    SOUND_CTRL10 = 0x4F, // MIDI CC 79 undefined
    GPC5 = 0x50,
    GPC6 = 0x51,
    GPC7 = 0x52,
    GPC8 = 0x53,
    PORTAMENTO_CTRL = 0x54,
    EFFECTS_DEPTH1 = 0x5B,
    EFFECTS_DEPTH2 = 0x5C,
    EFFECTS_DEPTH3 = 0x5D,
    EFFECTS_DEPTH4 = 0x5E,
    EFFECTS_DEPTH5 = 0x5F,
    DATA_ENTRY_INCR = 0x60,
    DATA_ENTRY_DECR = 0x61,
    NRPN_LSB = 0x62,
    NRPN_MSB = 0x63,
    RPN_LSB = 0x64,
    RPN_MSB = 0x65,
    ALL_SOUND_OFF = 0x78,
    ALL_CTRL_OFF = 0x79,
    LOCAL_CONTROL = 0x7A,
    ALL_NOTES_OFF = 0x7B,
    OMNI_OFF = 0x7C,
    OMNI_ON = 0x7D,
    POLY_OFF = 0x7E,
    POLY_ON = 0x7F
};

/*
 Attenuation range in centibels.
 Attenuation range is the dynamic range of the volume envelope generator
 from 0 to the end of attack segment.
 fluidsynth is a 24 bit synth, it could (should??) be 144 dB of attenuation.
 However the spec makes no distinction between 16 or 24 bit synths, so use
 96 dB here.
 
 Note about usefulness of 24 bits:
 1)Even fluidsynth is a 24 bit synth, this format is only relevant if
 the sample format coming from the soundfont is 24 bits and the audio sample format
 choosen by the application (audio.sample.format) is not 16 bits.
 
 2)When the sample soundfont is 16 bits, the internal 24 bits number have
 16 bits msb and lsb to 0. Consequently, at the DAC output, the dynamic range of
 this 24 bit sample is reduced to the the dynamic of a 16 bits sample (ie 90 db)
 even if this sample is produced by the audio driver using an audio sample format
 compatible for a 24 bit DAC.
 
 3)When the audio sample format settings is 16 bits (audio.sample.format), the
 audio driver will make use of a 16 bit DAC, and the dynamic will be reduced to 96 dB
 even if the initial sample comes from a 24 bits soundfont.
 
 In both cases (2) or (3), the real dynamic range is only 96 dB.
 
 Other consideration for FLUID_NOISE_FLOOR related to case (1),(2,3):
 - for case (1), FLUID_NOISE_FLOOR should be the noise floor for 24 bits (i.e -138 dB).
 - for case (2) or (3), FLUID_NOISE_FLOOR should be the noise floor for 16 bits (i.e -90 dB).
 */
#define FLUID_PEAK_ATTENUATION  960.0f

struct MidiConstants {
    inline static const int midiMinValue = 0;
    inline static const int midiMaxValue = 127;
};
