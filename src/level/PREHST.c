#include "common.h"

#include "level/PREHST.h"

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ttplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ttplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ttplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bug_OnCollide);

void prehst_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    int* fc;
    
    intro = instance->introData;
    fc = &instance->_F4[2];
    
    if (intro != NULL) {
        ((short*)&instance->_100)[1] = intro[0];
        ((short*)&instance->_104)[0] = intro[1];
    } else {
        ((short*)&instance->_100)[1] = 0U;
        ((short*)&instance->_104)[0] = 0U;
    }
    fc[3] = instance->intro->position.x;
    fc[4] = instance->intro->position.y;
    ((short*)fc)[5] = 6;
    instance->intro->rotation.z = instance->intro->rotation.z & 0xFFF;
    instance->_F4[0] = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bouncer_OnUpdate);

void prehst_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 1)
        && (bsp->instanceSpline == gameTracker->player)
        && (bsp->_08[4] < 2U)
        && (bsp->_0C[5] >= 6U)
        && (
            (*(short*)&instance->_104 != 3)
            || ((instance->_F4[0] - 2) < 2U)
            || (instance->_F4[0] == 4)
        )) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
    else if ((bsp->_06 == 1)
             && (bsp->instanceSpline == gameTracker->player)
             && (
                 (bsp->_08[4] == 0) || (bsp->_08[4] == 2)
             )) {
        func_80022714(instance);
    }
}

void prehst_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->currentModelAnim = 0;
}

void prehst_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v0, v1;

    if (instance->_F4[0] == 0)
    {
        v1 = instance->oldPos.x;
        v0 = instance->oldPos.y;
        instance->rotation.z = ratan2(v0 - instance->position.y, v1 - instance->position.x) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->_F4[0] == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[(*(unsigned char*)&instance->_40[7])]))[1] - 1; 
            instance->_F4[0] = 2;
        }
        
    }
}

void prehst_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a3;
    int temp_v1;
    BSPTree* bsp;

    bsp = instance->bspTree;
    temp_a3 = bsp->_06;
    if (temp_a3 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] >= 6U)) {
            if (instance->_F4[0] == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->_F4[0] = temp_a3;
                instance->currentAnimFrame = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->_F4[0] == 2)
            {
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015AC20_C84A0);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015ADA8_C8628);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_eel_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_eel_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_eel_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_stmvent_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015B47C_C8CFC);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015B5B0_C8E30);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_stmvent_OnUpdate);

void prehst_stmvent_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_sptball_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_sptball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_sptball_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavegex_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015BAFC_C937C);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavegex_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavegex_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavetl_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavetl_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavetl_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_raptor_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164514_D1D94);

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164518_D1D98);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_raptor_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_raptor_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_zviolet_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_zviolet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_zviolet_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015F1F0_CCA70);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015F290_CCB10);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_gas_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_gas_OnCollide);

void prehst_brkbone_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void prehst_brkbone_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_brkbone_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bldrgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bldrgen_OnUpdate);

void prehst_bldrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_boulder_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015F9A4_CD224);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015FC2C_CD4AC);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_boulder_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_boulder_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_spitplt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_spitplt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_spitplt_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80160840_CE0C0);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164598_D1E18);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801630A0_D0920);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163138_D09B8);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163160_D09E0);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163264_D0AE4);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801633DC_D0C5C);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163500_D0D80);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163604_D0E84);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801636E8_D0F68);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801637D0_D1050);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801639D0_D1250);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163BC8_D1448);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163C4C_D14CC);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163EE0_D1760);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163F94_D1814);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnCollide);
