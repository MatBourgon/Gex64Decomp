#include "common.h"

#include "types/Level.h"

void spy_qsofa_OnCreate(void) {
}

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_qsofa_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_qsofa_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_80159EEC_EB5BC);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_80159F3C_EB60C);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_8015A014_EB6E4);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_8015A098_EB768);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_btimer_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AD70_EC440);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE00_EC4D0);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE0C_EC4DC);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE10_EC4E0);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_btimer_OnUpdate);
