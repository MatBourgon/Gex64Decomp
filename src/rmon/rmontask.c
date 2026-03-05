#include "common.h"

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonMaskIdleThreadInts);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonGetTCB);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonStopUserThreads);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonListThreads);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonGetThreadStatus);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonThreadStatus);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", func_80067D80);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonStopThread);

INCLUDE_ASM("asm/nonmatchings/rmon/rmontask", __rmonRunThread);
