#include "common.h"

#include "types/Level.h"
#include "types/TVTextData.h"

void func_80159720_BA150(void) {
}

void func_80159728_BA158(Level_t* level)
{
    level->_D0[0]++;
}

void func_8015973C_BA16C(void) {
}

void func_80159744_BA174(void) {
}

void func_8015974C_BA17C(Level_t* level) {
    if ((level->_18)[0x1C/4] != 0) {
        level->_60[2] += (0x1000 / *(level->_18)[0x1C/4]);
    } else {
        level->_60[2] += 0x3C;
    }
    
    level->_60[2] &= 0xFFF;
}

void func_801597CC_BA1FC(void) {
}

void func_801597D4_BA204(Level_t* level)
{
    if (!level->_1C[1])
        return;

    if (((Level_t***)level->_1C[1])[1][0x24/4] == level)
    {
        level->_F4[0] = 1;
    }
    else
    {
        level->_F4[2] = 1;
    }

    level->flags |= 0x480;
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161130_C1B60);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161194_C1BC4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611A4_C1BD4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611B4_C1BE4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611C0_C1BF0);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611CC_C1BFC);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611D8_C1C08);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611E4_C1C14);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801611F8_C1C28);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161208_C1C38);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80159828_BA258);

void func_80159934_BA364(void) {
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015993C_BA36C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80159A5C_BA48C);

void func_80159C88_BA6B8(void) {
}

void func_80159C90_BA6C0(Level_t* arg0) {
    ((short*)&arg0->_100)[1] = -0x1000;
    arg0->flags |= 0xC00;
    if ((arg0->_18)[0x1C/4] != 0) {
        ((short*)&arg0->_100)[1] = *(arg0->_18)[0x1C/4];
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_80159CCC_BA6FC);

void func_80159E88_BA8B8(Level_t* arg0) {
    if (arg0->_F4[0] == 1) {
        arg0->_F4[0] = 2;
        ((short*)&arg0->_104)[1] = 0x1E;
    }
}


void func_80159EAC_BA8DC(Level_t* level)
{
    *((short*)&level->_F4[2]) = 1;
    *(((short*)&level->_F4[2]) + 1) = 1;
    level->flags |= 0x400;
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161230_C1C60);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80159EC8_BA8F8);

void func_8015A398_BADC8(void) {
}

void func_8015A3A0_BADD0(Level_t* level)
{
    *(((short*)&level->_F4[2]) + 1) = 1;
    level->flags |= 0x400;
    *((short*)&level->_100) = level->_60[2];
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015A3C0_BADF0);

void func_8015A638_BB068(void) {
}

void func_8015A640_BB070(Level_t* level)
{
    level->_104 = 0;
    level->_F4[2] = 0x40;
    level->_100 = 0;
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015A654_BB084);

void func_8015A7FC_BB22C(Level_t* level) {
    short* temp_s1;

    temp_s1 = (short*)level->_20[1];
    if (func_80027500(level->_70[2]) != 0) {
        level->_104 = 1;
        level->_F4[2] = 0x12C;
        level->_110 = temp_s1[4];
        level->_10C = 1;
    }
}


INCLUDE_ASM("asm/nonmatchings/map_code", func_8015A854_BB284);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015A94C_BB37C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015AB2C_BB55C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015B18C_BBBBC);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015B330_BBD60);

void func_8015B804_BC234(Level_t* level)
{
    level->flags |= 0xC00;
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612B4_C1CE4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612B8_C1CE8);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612C0_C1CF0);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612C4_C1CF4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612CC_C1CFC);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612D4_C1D04);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612DC_C1D0C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612E4_C1D14);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612EC_C1D1C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801612F8_C1D28);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161300_C1D30);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161308_C1D38);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015B818_BC248);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015B96C_BC39C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015BED0_BC900);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015BFE0_BCA10);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C110_BCB40);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C1D8_BCC08);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C2D8_BCD08);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C63C_BD06C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C728_BD158);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C840_BD270);

void func_8015CD04_BD734(void) {
}

void func_8015CD0C_BD73C(void) {
}

extern int* D_8006CFA0;

void func_8015CD14_BD744(Level_t* level, int* arg1)
{
    int* a1;
    a1 = ((int*)level->_20[1]);
    if ((arg1[0x44/4] & 0x10) == 0)
        return;
    
    if (a1[1])
    {
        func_8004EBAC(D_8006CFA0, 4 + a1[1], 0);
    }
}

// Unknown parameters, exactly 6 bytes
typedef struct
{
    short _[3];
} func_8015CD64_BD794_t;

void func_8015CD64_BD794(Level_t* arg0) {
    int temp_a1;
    func_8015CD64_BD794_t* temp_v0;

    ((short*)&arg0->_100)[1] = 2;
    arg0->_F0[6] = 0x64;
    temp_a1 = arg0->_20[1];
    arg0->flags |= 0x800;
    if (temp_a1 != 0) {
        temp_v0 = (func_8015CD64_BD794_t*)((((short*)&arg0->_100)[1] * sizeof(func_8015CD64_BD794_t)) + temp_a1 + 4);
        *(func_8015CD64_BD794_t*)&D_8006CFA0[0x50/4]
            = *(func_8015CD64_BD794_t*)(&D_8006CFA0[0x48/4])
            = *(func_8015CD64_BD794_t*)temp_v0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161314_C1D44);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016131C_C1D4C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161324_C1D54);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015CDE0_BD810);

extern int D_800785CC[];

void func_8015D3B0_BDDE0(Level_t* level)
{
    level->_100 = 0xC8;
    if (D_800785CC[((int*)level->_20[1])[0]] != 3)
        return;

    func_80048828(level, -1, 0, 0, 0);
    level->flags |= 0x100000;
}

int func_8015D420_BDE50(Level_t* level) {
    int v0;

    if (level->_100 != 0) {
        level->_100--;
    }

    v0 = *((int*)level->_20[1]);
    
    switch (D_800785CC[v0])
    {
        case 0:
            break;
        
        case 1:
        {
            level->flags |= 0x02000000, D_800785CC[v0] = 2;
            break;
        }

        case 2:
        {
            level->flags |= 0x02000000, D_800785CC[v0] = 3;
            break;
        }
        
    }
}

void func_8015D4B4_BDEE4(Level_t* level) {
    int temp_v1;

    temp_v1 = *(int*)level->_20[1];
    if (!D_800785CC[temp_v1] && !level->_100) {
        func_80052C2C(TVTextInformation[0x1E].levelName[temp_v1-1]); // todo: definitely wrong
        level->_100 = 0xC8;
    }
}

extern char D_80161394_C1DC4[];
extern int D_80161684_C20B4;
extern void func_8015D5E4_BE014();

void func_8015D52C_BDF5C(Level_t* level) {
    char buffer[0x10];
    int v1;
    
    level->_50[3] = -1;
    level->flags |= 0x80;
    
    csprintf(buffer, D_80161394_C1DC4, (short*)level->_20[1] + 2, ((short*)(level->_20[1]))[1]);
    
    level->_F4[2] = GetLevelIndexFromId(buffer);
    
    v1 = ((int***) level->_18)[3][0][5];
    
    if (v1 != 0)
    {
        D_80161684_C20B4 = v1;
        ((int***)level->_18)[3][0][5] = 0;
    }
    
    *((void**)level->_B0 + 1) = func_8015D5E4_BE014;
}

void func_8015D5DC_BE00C(void) {
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015D5E4_BE014);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016136C_C1D9C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161374_C1DA4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161380_C1DB0);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161388_C1DB8);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161394_C1DC4);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015D6F0_BE120);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015D9E4_BE414);

extern char D_801613C0_C1DF0[];
extern void func_8015E338_BED68();

void func_8015DAC8_BE4F8(Level_t* level) {
    level->_100 = func_8002DEA8(level, func_8003EE84(&D_801613C0_C1DF0 /*etvbutn_*/));
    level->flags |= 0x10000;
    ((int*)level->_100)[0x10/4] |= 0x100000;
    ((int*)level->_100)[0x10/4] |= 0x400;
    ((void**)level->_100)[0xB0/4] = &func_8015E338_BED68;
}


INCLUDE_ASM("asm/nonmatchings/map_code", func_8015DB54_BE584);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015DC38_BE668);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015DEC8_BE8F8);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015E274_BECA4);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015E338_BED68);

void func_8015E630_BF060(int arg0, int arg1, int arg2, int arg3) {
    int sp10[8];

    sp10[3] = arg0;
    sp10[4] = arg1;
    sp10[0] = 0x32;
    sp10[1] = arg2;
    sp10[2] = 0;
    sp10[6] = arg3;
    sp10[7] = arg3;
    func_80037B34(&sp10, 0);
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015E674_BF0A4);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015E824_BF254);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015EA98_BF4C8);

void func_8015EEA8_BF8D8(void) {
}

void func_8015EEB0_BF8E0(void) {
}

void func_8015EEB8_BF8E8(void) {
}

void func_8015EEC0_BF8F0(void) {
}

void func_8015EEC8_BF8F8(void) {
}

void func_8015EED0_BF900(void) {
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015EED8_BF908);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015F228_BFC58);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613C0_C1DF0);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613C4_C1DF4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613CC_C1DFC);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613D0_C1E00);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613D4_C1E04);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613DC_C1E0C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613E0_C1E10);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613E8_C1E18);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801613F0_C1E20);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161404_C1E34);

INCLUDE_RODATA("asm/nonmatchings/map_code", jtbl_80161420_C1E50);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015F678_C00A8);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015F770_C01A0);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015F804_C0234);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015FBBC_C05EC);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015FC88_C06B8);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015FF60_C0990);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801614D0_C1F00);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801614F0_C1F20);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160214_C0C44);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016151C_C1F4C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161520_C1F50);

INCLUDE_RODATA("asm/nonmatchings/map_code", jtbl_80161528_C1F58);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160838_C1268);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160ACC_C14FC);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160DF0_C1820);

extern char D_8014F34C;
void func_801610B8_C1AE8(short* arg0) {
    func_80037B00(0x50, 0x6E);
    func_80038BA0("#2DATA SAVED");
    if (++D_8014F34C >= 0x1F) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
    }
}
