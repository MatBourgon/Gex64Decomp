#include "common.h"

#include "types/Level.h"

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnDestroy);

void circuit_crawler_OnCreate(Level_t* level)
{
    level->_F4[0] = 0;
    level->_4E = 0;
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_crawler_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_crawler_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_chrganm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_chrganm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B548_82728);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B570_82750);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B780_82960);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B7E0_829C0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015BA9C_82C7C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015C18C_8336C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015C9CC_83BAC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D304_844E4);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D354_84534);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D42C_8460C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D4B0_84690);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D780_84960);

void circuit_pball_OnCreate(Level_t* level)
{
    level->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D7F0_849D0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pball_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015DB80_84D60);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015DD58_84F38);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_fxgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015E084_85264);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015E140_85320);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_fxgen_OnUpdate);

void circuit_fxgen_OnDestroy(void) {
}

void circuit_qmark_OnCreate(Level_t* level)
{
    level->_104 = 0;
    level->_F4[2] = 0x40;
    level->_100 = 0;
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_qmark_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_qmark_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015EC00_85DE0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F6B8_86898);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F708_868E8);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F720_86900);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F75C_8693C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F780_86960);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F930_86B10);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FA1C_86BFC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FAC4_86CA4);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FC70_86E50);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bomb_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635A0_8A780);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635B8_8A798);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635C0_8A7A0);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635CC_8A7AC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635D8_8A7B8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635DC_8A7BC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635E4_8A7C4);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635EC_8A7CC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635F8_8A7D8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635FC_8A7DC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163604_8A7E4);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163610_8A7F0);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163618_8A7F8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_8016361C_8A7FC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bomb_OnUpdate);

void circuit_bomb_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_80160D80_87F60);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_8016363C_8A81C);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163640_8A820);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_801618BC_88A9C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_btimer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_btimer_OnUpdate);
