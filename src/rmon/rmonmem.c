#include "common.h"

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonWriteWordTo);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonReadWordAt);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonMemcpy);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonCopyWords);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonReadMem);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonWriteMem);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonListProcesses);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonLoadProgram);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonGetExeName);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonGetRegionCount);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmem", __rmonGetRegions);
