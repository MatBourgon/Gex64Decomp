#include "common.h"

#include "level/FINAL.h"
#include "types/G2String.h"

extern int D_80161510_926B0;

void final_oldpoptv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_100 = 1;
    instance->_F4[2] = 0;
    instance->flags |= 0x400;
    if (instance->introData == NULL) {
        instance->introData = (int)&D_80161510_926B0;
    }
}


INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161510_926B0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161518_926B8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161520_926C0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161538_926D8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016153C_926DC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161540_926E0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161544_926E4);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161548_926E8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016154C_926EC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161558_926F8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_oldpoptv_OnUpdate);

void final_oldpoptv_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_lectro_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_lectro_OnUpdate);

void final_lectro_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_probe_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_probe_OnUpdate);

void final_probe_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_reztvex_OnCreate(Instance* arg0, GameTracker* gameTracker) {
    arg0->rotation.z = 0;
    arg0->rotation.y = 0;
    arg0->rotation.x = 0;
    arg0->scale.z = 0x100;
    arg0->scale.y = 0x100;
    arg0->scale.x = 0x100;
    arg0->_56 = 0;
    arg0->flags |= 0x80;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_reztvex_OnUpdate);

void final_reztvex_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_rezxpl_OnCreate(Instance* arg0, GameTracker* gameTracker) {
    arg0->rotation.z = 0;
    arg0->rotation.y = 0;
    arg0->rotation.x = 0;
    arg0->scale.z = 0x100;
    arg0->scale.y = 0x100;
    arg0->scale.x = 0x100;
    arg0->_56 = 0;
    arg0->flags |= 0x80;
}

void func_80159CBC_8AE5C(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezxpl_OnUpdate);

void final_rezxpl_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161588_92728);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezbomb_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_80159E50_8AFF0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A0DC_8B27C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A170_8B310);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A3DC_8B57C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A434_8B5D4);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A4C8_8B668);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A590_8B730);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A78C_8B92C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezbomb_OnUpdate);

void final_rezbomb_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A9F0_8BB90);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AC70_8BE10);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015ADC4_8BF64);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AE98_8C038);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AED8_8C078);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B07C_8C21C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B130_8C2D0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B1D8_8C378);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B268_8C408);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B30C_8C4AC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B658_8C7F8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BB78_8CD18);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BD84_8CF24);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BFB8_8D158);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C0A0_8D240);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C220_8D3C0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C39C_8D53C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C850_8D9F0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C9D0_8DB70);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CAF8_8DC98);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CB34_8DCD4);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615B8_92758);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CB70_8DD10);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615C8_92768);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D0_92770);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D8_92778);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CC64_8DE04);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CD54_8DEF4);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CDF0_8DF90);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CF08_8E0A8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015D018_8E1B8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161610_927B0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161618_927B8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016161C_927BC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015E788_8F928);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_popper_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016166C_9280C);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161670_92810);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_popper_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_popper_OnCollide);

void final_finaltv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->position.x = 11520;
    instance->position.y = 9850;
    instance->position.z = 6000;
    instance->_E0[1] = -10;
    instance->_F4[-1] = 100;
    instance->_F4[2] = 30;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_finaltv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_finaltv_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015EEF4_90094);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F05C_901FC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F0C8_90268);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F13C_902DC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F200_903A0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F480_90620);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F818_909B8);

extern char D_80161588_92728[];
extern char D_8016166C_9280C[];
extern void func_8015F200_903A0(void); // unknown

void final_frez_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (!(instance->flags & 0x20000)) {
        instance->_D0[3] = OBTABLE_FindObject(D_80161588_92728);
        instance->_C0[3] = 0;
        instance->_C0[4] = 1;
        instance->_C0[5] = 1;
        instance->_40[6] -= 0x12C;
        instance->_E0[2] = OBTABLE_FindObject(D_8016166C_9280C);
        instance->_B4 = (void*)&func_8015F200_903A0;
        instance->flags |= 0x10400;
        instance->flags2 |= 8;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F964_90B04);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015FAF8_90C98);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015FC3C_90DDC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161684_92824);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016168C_9282C);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161694_92834);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016169C_9283C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_frez_OnUpdate);

extern char D_8016166C_9280C[];
extern char D_801616F0_92890[];

void final_frez_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int*** temp_a2;
    short* temp_s1;

    temp_a2 = (int***)instance->_70[2];
    temp_s1 = &instance->_C0[3];
    if (G2String_Compare_EQ(temp_a2[0x14/4][0x18/4][0x24/4], D_8016166C_9280C)) {
        if (instance->_F4[0] != 0) {
            func_800331BC(instance->_F4[0], gameTracker);
            instance->_F4[0] = 0;
        }
        if (*temp_s1 != 0xB) {
            ((short*)instance->_D0)[3]++;
            if (((short*)instance->_D0)[3] >= 3) {
                *temp_s1 = 0xC;
            }
            else
            {
                *temp_s1 = 0xB;
            }
        }
        temp_s1[0x2/2] = 1;
    }
    else if ((*temp_s1 != 8) && (((short*)temp_a2)[0x6/2] == 1)) {
        if (G2String_Compare_EQ(temp_a2[0x14/4][0x18/4][0x24/4], D_801616F0_92890) && (func_8002275C(PlayerInstance, gameTracker) == 0)) {
            temp_s1[0x34/2] = 0;
        }
    }
}

extern int D_80161558_926F8[];
void final_rezcam_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_s2;
    int* ptr;

    temp_s2 = ((int*)gameTracker)[2];
    ptr = &instance->_F4[2];
    instance->flags |= 0x800;
    func_80001408(((int*)gameTracker)[2], 8);
    if (instance->introData == NULL) {
        instance->introData = (void*)&D_80161558_926F8;
    }
    func_80005438(ptr, &instance->position, temp_s2);
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezcam_OnUpdate);

void final_rezcam_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_finplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_ret;

    func_80000F24(((int*)gameTracker)[2], 213);
    instance->_F4[2] = (rand() % 120) + 120;
    GenericInit(instance, gameTracker);
}

void final_finplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    
    if (--instance->_F4[2] <= 0) {
        if (func_80052FB8() != 0) {
            func_80052C2C(0x4C);
        }
        
        instance->_F4[2] = (rand() % 120) + 120;
    }
    GenericProcess(instance, gameTracker);
}

void final_finplat_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    GenericCollide(instance, gameTracker);
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F0_92890);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F4_92894);
