#include "common.h"

INCLUDE_ASM("asm/nonmatchings/audio/reverb", alFxPull);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", alFxParam);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", alFxParamHdl);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", _loadOutputBuffer);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", _loadBuffer);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", _saveBuffer);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", _filterBuffer);

INCLUDE_ASM("asm/nonmatchings/audio/reverb", _doModFunc);
