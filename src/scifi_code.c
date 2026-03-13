#include "common.h"

#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159720_DF540);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_801598A4_DF6C4);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159A08_DF828);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164DF0_EAC10);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E14_EAC34);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159A84_DF8A4);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159B10_DF930);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159D54_DFB74);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80159E3C_DFC5C);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_dust_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_dust_OnUpdate);

void scifi_crawler_OnCreate(Instance* instance)
{
    instance->_F4[0] = 0;
    instance->_4E = 0;
}

void scifi_crawler_OnUpdate(Instance* instance) {
    
    int a0, v0, v1;

    if (instance->_F4[0] == 0)
    {
        v1 = instance->_50[0];
        v0 = instance->_50[1];
        instance->_60[2] = func_80030538(v0 - instance->_40[5], v1 - instance->_40[4]) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->_F4[0] == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            a0 = (*(unsigned char*)&instance->_40[7] << 2) + ((int*)(instance->_18 + 4))[0];
            instance->_50[7] = ((unsigned short*)(*((int*)a0)))[1] - 1; 
            instance->_F4[0] = 2;
        }
        
    }
}

void scifi_crawler_OnCollide(Instance* instance, int* arg1) {
    int temp_a3;
    int temp_v1;
    char** temp_a2;

    temp_a2 = ((char***)instance->_70)[2];
    temp_a3 = ((short*)temp_a2)[3];
    if (temp_a3 == 1) {
        if ((temp_a2[5] == (char*)arg1[12/4]) && (temp_a2[12/4][5] >= 6U)) {
            if (instance->_F4[0] == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->_F4[0] = temp_a3;
                instance->_50[7] = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->_F4[0] == 2)
            {
                func_80047904(instance, 5, 3, 0);
            }
        } else if ((((short*)temp_a2)[3] == 1) && (temp_a2[5] == (char*)arg1[12/4]) && ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rocket_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015A36C_E018C);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015A3F4_E0214);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rocket_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rocket_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_bub_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015AC28_E0A48);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_bub_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_bub_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_eel_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_eel_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_eel_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_stmvent_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015B4BC_E12DC);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E3C_EAC5C);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E40_EAC60);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015B5F0_E1410);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_stmvent_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015B904_E1724);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015BB90_E19B0);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015BC24_E1A44);

void scifi_genbrk_OnCreate(void) {
}

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_genbrk_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_genbrk_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015BF08_E1D28);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015BFA8_E1DC8);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015BFD4_E1DF4);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_bldbota_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_bldbota_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_abubble_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_abubble_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_abubble_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_acrate_OnCreate);

void scifi_acrate_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_acrate_OnCollide);

void scifi_xa_OnCreate(Instance* instance)
{
    instance->_F4[2] = 0;
}


INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_xa_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_apod_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015C5CC_E23EC);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_apod_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_apod_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_alien_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E60_EAC80);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E6C_EAC8C);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164E78_EAC98);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_alien_OnUpdate);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164EA8_EACC8);

INCLUDE_RODATA("asm/nonmatchings/scifi_code", D_80164EAC_EACCC);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_alien_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_gas_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_gas_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_mylot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E070_E3E90);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E108_E3F28);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E130_E3F50);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E234_E4054);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E3AC_E41CC);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E4D0_E42F0);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E5D4_E43F4);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E6B8_E44D8);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E7A0_E45C0);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015E9A0_E47C0);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_8015EB98_E49B8);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_mylot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_mylot_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80161C3C_E7A5C);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80161D18_E7B38);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80161DF4_E7C14);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80161ED0_E7CF0);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80161F50_E7D70);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_80162154_E7F74);

INCLUDE_ASM("asm/nonmatchings/scifi_code", func_801621D4_E7FF4);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rt_OnCollide);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rtblast_OnCreate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rtblast_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/scifi_code", scifi_rtblast_OnCollide);
