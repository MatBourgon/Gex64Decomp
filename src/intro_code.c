#include "common.h"

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_rezzull_OnCreate);

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_rezzull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_gextext_OnCreate);

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_gextext_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_enttext_OnCreate);

void intro_enttext_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_gectext_OnCreate);

void intro_gectext_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_remtext_OnCreate);

void intro_remtext_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_gexcopy_OnCreate);

INCLUDE_ASM("asm/nonmatchings/intro_code", intro_gexcopy_OnUpdate);
