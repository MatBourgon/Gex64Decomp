#include "common.h"

// Music library needs to be semi-reversed, as it seems to be its own version

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntMain);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntGetNewNote);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntFlushPending);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntSetVolumeAndPan);

INCLUDE_RODATA("asm/nonmatchings/libmus/player", D_8007EB70);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntSetPitch);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntInitEnvelope);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessEnvelope);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntInitSweep);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessSweep);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessWobble);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessVibrato);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessContinuousVolume);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntProcessContinuousPitchBend);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntPowerOf2);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntRemapPtrBank);

INCLUDE_ASM("asm/nonmatchings/libmus/player", func_80055740);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntInitialiseChannel);

INCLUDE_ASM("asm/nonmatchings/libmus/player", func_80055908);

INCLUDE_ASM("asm/nonmatchings/libmus/player", func_80055A88);

INCLUDE_ASM("asm/nonmatchings/libmus/player", func_80055AB4);

INCLUDE_ASM("asm/nonmatchings/libmus/player", __MusIntStartEffect);
