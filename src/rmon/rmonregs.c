#include "common.h"

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonGetGRegisters);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonSetGRegisters);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonGetFRegisters);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", func_80067034);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", func_800670C0);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonGetSRegs);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonSetSRegs);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonGetVRegs);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonSetVRegs);

INCLUDE_ASM("asm/nonmatchings/rmon/rmonregs", __rmonGetRegisterContents);
