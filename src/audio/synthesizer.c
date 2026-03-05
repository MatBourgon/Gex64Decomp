#include "common.h"

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", alSynNew);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", alAudioFrame);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", __allocParam);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", __freeParam);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _collectPVoices);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _freePVoice);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _timeToSamplesNoRound);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _timeToSamples);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", __nextSampleTime);
