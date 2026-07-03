#include "common.h"

#include <PR/libaudio.h>

ALGlobals *alGlobals=0;

INCLUDE_ASM("asm/nonmatchings/audio/sl", alInit);

INCLUDE_ASM("asm/nonmatchings/audio/sl", alClose);

INCLUDE_ASM("asm/nonmatchings/audio/sl", alLink);

INCLUDE_ASM("asm/nonmatchings/audio/sl", alUnlink);
