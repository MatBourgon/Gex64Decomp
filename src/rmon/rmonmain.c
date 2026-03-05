#include "common.h"

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmain", __rmonSendHeader);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmain", __rmonSendReply);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmain", __rmonSendData);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmain", rmonMain);
