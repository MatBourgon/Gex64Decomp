#include "common.h"

#include "types/Level.h"

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ttplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ttplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ttplat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bug_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bouncer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bouncer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bouncer_OnDestroy);

void prehst_crawler_OnCreate(Level_t* level)
{
    level->_F4[0] = 0;
    level->_4E = 0;
}

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_crawler_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_crawler_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015AC20_C84A0);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015ADA8_C8628);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_eel_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_eel_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_eel_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_stmvent_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015B47C_C8CFC);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015B5B0_C8E30);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_stmvent_OnUpdate);

void prehst_stmvent_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_sptball_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_sptball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_sptball_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavegex_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015BAFC_C937C);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavegex_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavegex_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavetl_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavetl_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_cavetl_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_tricer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_tricer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_tricer_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_raptor_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/prehst_code", D_80164514_D1D94);

INCLUDE_RODATA("asm/nonmatchings/prehst_code", D_80164518_D1D98);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_raptor_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_raptor_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_zviolet_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_zviolet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_zviolet_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015F1F0_CCA70);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015F290_CCB10);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_gas_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_gas_OnDestroy);

void prehst_brkbone_OnCreate(void) {
}

void prehst_brkbone_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_brkbone_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bldrgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_bldrgen_OnUpdate);

void prehst_bldrgen_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_boulder_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015F9A4_CD224);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_8015FC2C_CD4AC);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_boulder_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_boulder_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_spitplt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_spitplt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_spitplt_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ptera_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80160840_CE0C0);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ptera_OnDestroy);

INCLUDE_RODATA("asm/nonmatchings/prehst_code", D_80164598_D1E18);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_ptera_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_801630A0_D0920);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163138_D09B8);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163160_D09E0);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163264_D0AE4);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_801633DC_D0C5C);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163500_D0D80);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163604_D0E84);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_801636E8_D0F68);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_801637D0_D1050);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_801639D0_D1250);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163BC8_D1448);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163C4C_D14CC);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163EE0_D1760);

INCLUDE_ASM("asm/nonmatchings/prehst_code", func_80163F94_D1814);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_lavadrp_OnCreate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_lavadrp_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/prehst_code", prehst_lavadrp_OnDestroy);
