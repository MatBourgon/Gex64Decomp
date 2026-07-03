#include "common.h"
#include "audio/synthInternals.h"

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", alSynNew);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", alAudioFrame);

ALParam *__allocParam() 
{
    ALParam *update = 0;
    ALSynth *drvr = &alGlobals->drvr;

    if (drvr->paramList) {        
        update = drvr->paramList;
        drvr->paramList = drvr->paramList->next;
        update->next = 0;
    }
    return update;
}

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", __freeParam);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _collectPVoices);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _freePVoice);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _timeToSamplesNoRound);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", _timeToSamples);

INCLUDE_ASM("asm/nonmatchings/audio/synthesizer", __nextSampleTime);
