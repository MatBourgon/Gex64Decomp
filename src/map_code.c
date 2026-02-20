#include "common.h"

#include <PR/gbi.h>
#include <PR/mbi.h>

#include "types/Level.h"
#include "types/TVTextData.h"
#include "types/GameState.h"
#include "types/G2String.h"
#include "types/Vector.h"

extern char D_8014F34C;
extern int* D_8006CFA0;
extern char D_801613C0_C1DF0[];
extern void func_8015E338_BED68();
extern char D_80161394_C1DC4[];
extern char* D_80161684_C20B4;
extern void func_8015D5E4_BE014();
extern int D_800785CC[];
extern unsigned short D_800E5DB2;
extern int D_80161680_C20B0;

extern Gfx D_8006D578[];
extern Gfx* D_80157050;
extern char D_800E5D00[];

extern G2String D_801612B4_C1CE4;
extern G2String D_80161324_C1D54;
extern int D_800E5CD8;
extern unsigned char D_8006FCD2;
extern char D_80161314_C1D44[];

extern int D_8006FA54;
extern char D_80078174[];
extern int D_800B83C8;
extern char D_800E5B98;
extern int D_800E5CD4;
extern char D_800E5DDE[];
extern char D_800E8EB4;
extern int D_800E97CC;
extern char D_8014F354;
extern char D_80153A58[];
extern char D_80157030;
extern int D_80157034;
extern char D_801613F0_C1E20[];
extern char D_8016151C_C1F4C[];

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

void func_80159828_BA258(Level_t* level, int* arg1) {
    int* arg2 = arg1 + 0x18/4;
    if (level->_1C[1] != 0) {
        level->_50[3] = level->_F4[2] * 2;
        
        if (!level->_F4[0]) {
            level->_50[3] |= 1;
        }
        
        if (!(arg1[0x4C08/4] & 1)) {
            if ((arg1[0x1C/4] & 0x10) && (level->_F4[0] == 1)) {
                func_800396E0("prehst", "prehst1", arg1);
            }
            else
            {
                if ((arg2[0] & 4) || (arg1[0x4C/4] < -0x20)) {
                    if (level->_F4[2] == 0) {
                        level->_F4[0] = 1;
                    }
                    else
                    {
                        level->_F4[0] = 0;
                    }
                }
                else if ((arg2[0] & 8) || (arg1[0x4C/4] >= 0x21)) {
                    if (level->_F4[2] == 1) {
                        level->_F4[0] = level->_F4[2];
                    }
                    else
                    {
                        level->_F4[0] = 0;
                    }
                }
            }
        }
    }
}

void func_80159934_BA364(void) {
}

void func_8015993C_BA36C(Level_t* level, int* arg1) {
    int* temp_s1;
    int* temp_v0;
    int** temp_a1;
    int** temp_a2;
    short* temp_v0_2;

    if ((level->_1C)[1] != 0) {
        temp_a1 = ((int****)level->_1C)[1][1];
        temp_a2 = ((int****)level->_1C)[1][2];
        level->flags |= 0xC00;
        ((int**)arg1)[3][0x10/4] |= 0x400;
        ((int**)arg1)[3][0x10/4] |= 0x100;
        if ((temp_a1 != 0) && (temp_a2 != 0)) {
            temp_v0 = temp_a1[0x28/4];
            temp_s1 = temp_a2[0x28/4];
            temp_v0_2 = (short*)func_80051638(*temp_v0, temp_v0 + 4);
            if (temp_v0_2 != 0) {
                ((short**)arg1)[2][0] = temp_v0_2[0];
                ((short**)arg1)[2][1] = temp_v0_2[1];
                ((short**)arg1)[2][2] = temp_v0_2[2];
            }
            func_80003A68(arg1[2], func_80051638(*temp_s1, temp_s1 + 4));
            func_80001408(arg1[2], 8);
        }
        ((int*)arg1)[0x4C08/4] |= 1;
    }
}

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

void func_80159CCC_BA6FC(Level_t* arg0, int* arg1) {
    int* temp_v0;
    short* temp_s2;
    short* temp_s3;

    temp_v0 = (int*)arg0->_1C[0x20/4];
    temp_s3 = (short*)arg1[3];
    temp_s2 = (short*)&arg0->_F4[2];

    if (arg0->_F4[0] == 1)
    {
        if ((temp_v0 != 0) && (*temp_v0 != 0)) {
            func_800257B4(arg1[3]);
        }
        goto block_10;
    
    }
    else if (arg0->_F4[0] == 0)
    {
        *(SVECTOR*)(&arg0->_40[4]) = *(SVECTOR*)&temp_s3[0x48/2];
        arg0->_40[6] = (s16) ((u16) arg0->_40[6] + 0x400);
        if ( temp_s3[0x4C/2] <= ((short*)&arg0->_100)[1]) {
            func_8004A5B4(arg0, 0x1000);
            arg0->_F4[0] = 1;
            arg1[0x4C08/4] |= 1;
            (*(short*)&arg0->_104) = 0x5A;
            arg0->_40[6] -= 0x400;
            arg0->flags &= ~0x800;
        }
        goto block_10;
    }
    else if (arg0->_F4[0] == 2)
    {
        
        if (((short*)&arg0->_104)[1] <= 0) {
            ((short*)&arg0->_104)[1] = 0x1E;
            arg0->_F4[0] = 3;
            goto block_10;
        }
        goto block_11;

    }
    else
    {
block_10:
        if (temp_s2[5] > 0) {
block_11:
            temp_s2[5]--;
        }
    }
    
    if (temp_s2[4] > 0) {
        temp_s2[4]--;
        if ((temp_s2[4] << 0x10) <= 0) {
            arg1[0x4C08/4] &= ~1;
            func_8001C978(temp_s3, arg1[1] + 0x2C, arg1);
            arg0->_F4[0] = 0;
            arg0->flags |= 0x800;
            func_8004A54C(arg0, 0x1000);
        }
    }
}

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

void func_8015A654_BB084(Level_t* arg0, int* arg1) {
    int* temp_s0;
    short* temp_t0;
    

    temp_t0 = (short*)arg0->_20[1];
    temp_s0 = &arg0->_F4[2];
    if (((*(int*)&arg0->_10C) != 0) && !(arg1[0x4C08/4] & 0x2000)) {
        func_8003F6CC(temp_t0[0], temp_t0[1], temp_t0[2], temp_t0[3], temp_t0[5], temp_t0 + 6);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (func_80030840(SVECTOR_DistanceSquared((SVECTOR*)&arg0->_40[4], (SVECTOR*)&D_8006CFA0[0x48/4]), 0) > 1000
            || !temp_s0[5])
        {
            temp_s0[2] = 2;
            temp_s0[1] = -6;
        }
        else
            temp_s0[5]--;
            
        break;
        
        case 2:
        if (temp_s0[0] < 0x41) {
            temp_s0[2] = 0;
            temp_s0[0] = 0x40;
            temp_s0[1]= 0;
            temp_s0[4] = 0;
        }
            
        break;
    }
    temp_s0[0] += temp_s0[1];
    arg0->_60[2] = (u16) ((arg0->_60[2] + temp_s0[0]) & 0xFFF);
}

void func_8015A7FC_BB22C(Level_t* level) {
    short* temp_s1;

    temp_s1 = (short*)level->_20[1];
    if (func_80027500(level->_70[2]) != 0) {
        level->_104 = 1;
        level->_F4[2] = 0x12C;
        *((int*)&level->_110) = temp_s1[4];
        *((int*)&level->_10C) = 1;
    }
}

void func_8015A854_BB284(int arg0, short arg1) {
    char buffer[40];
    int var_a0;
    char* bufferPtr;
    char* var_s1;
    int temp_a0;
    char last_char;

    func_8003EA34(buffer, arg0);
    var_s1 = buffer;
    do {
        bufferPtr = var_s1;
        while(*bufferPtr != '\0' && *bufferPtr != '\n') ++bufferPtr;
        
        last_char = *bufferPtr;
        *bufferPtr = 0;
        
        temp_a0 = (unsigned int)(0x140 - ((cstrlen(var_s1) - 1) * 0x14)) >> 1U;
        
        if (temp_a0 < 0x28) {
            temp_a0 = 0x28;
        }
        
        func_80037B00((temp_a0 << 0x10) >> 0x10, arg1);
        func_80038BA0("#2%s", var_s1);
        var_s1 = bufferPtr + 1;
        arg1 += 0x1E;
    } while (last_char != 0);
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015A94C_BB37C);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015AB2C_BB55C);

extern char D_801612C0_C1CF0[];

typedef struct
{
    char data[8];
} test_string;

void func_8015B18C_BBBBC(Level_t* arg0, int** arg1) {
    int* temp_a1;
    int* temp_a2;
    short* temp_s4;
    int* temp_v1;
    int* temp_v1_2;
    int* temp_v1_3;
    char* ptr;

    temp_a1 = (int*)arg0->_20[1];
    temp_s4 = (short*)D_8006CFA0[0x20/4];
    ptr = (char*)&arg0->_F4[2];
    if (!(arg0->flags & 0x20000)) {
        temp_a2 = (int*)arg1[1][0x90/4];
        
        if (G2String_Compare_NEQ(D_801612C0_C1CF0, temp_a2))
        {
            func_8004EBAC(D_8006CFA0, temp_a1[0] + 4, 0);
        } else {
            func_8004EBAC(D_8006CFA0, temp_a1[1] + 4, 0);
        }
        
        ptr[0x24] = 1;
        ((char*)gpGameState8)[0x4C60] = ((char*)gpGameState8)[0x4C61] = 1;
        ((int*)gpGameState8)[0x4C58/4] = 0x7A;
        func_80033334(0x78);
        ((int*)gpGameState8)[0x4C5C/4] = 0x7A;
        ((char*)gpGameState8)[0x4C62] = 1;
        arg0->flags |= 0x10C00;
        temp_v1 = arg1[0xC/4];
        temp_v1[0x10/4] = (temp_v1[0x10/4] | 0x800);
        temp_v1_2 = arg1[0xC/4];
        temp_v1_2[0x10/4] = (temp_v1_2[0x10/4] | 0x400);
        temp_s4[0xDC/2] = 0;
        temp_v1_3 = arg1[0xC/4];
        temp_v1_3[0xFC/4] = (temp_v1_3[0xFC/4] | 0x1000);
        temp_s4[0x12C/2] = 0;
        ((char*)D_8006CFA0)[0x4E] = 0;
        D_8006CFA0[0xF8/4] = 1;
        D_8006CFA0[0xF4/4] = 0;
        arg1[0xC/4][0xF4/4] = 5;
        func_80052F58();
        ((int*)arg0->_D0)[0] = 0x258;
        ((int*)arg0->_D0)[2] = 0;
    }
}

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

void func_8015B818_BC248(int arg1, int*** arg3) {
    short var_a2;
    short var_s0;
    int var_a1;
    int var_s2;
    short* var_a1_2;
    int* temp_a0;

    var_s2 = 0;
    temp_a0 = (int*)arg3[0x8/4];
    
    var_a1 =     temp_a0[0x14C/4] == 5
              && temp_a0[0x480/4] != 0
              && temp_a0[0x484/4] != 0;
    
    if (var_a1 != 0) {
        temp_a0 = (int*)*arg3[0x8/4][0x480/4];
        
        
        var_s0 = var_a2 = 0;
        if (temp_a0 != 0) {
            var_a1_2 = (short*)temp_a0[0x0];
            for(;var_a2 < ((short*)temp_a0)[0x4/2];)
            {
                var_a2++;
                var_s0 += *var_a1_2;
                var_a1_2 += 0x20/2;
            }
        }
        
        if ((func_800512BC(temp_a0, arg3[0x8/4][0x480/4] + 0x10/4) & 0xFFFF) >= (var_s0 - 1))
        {
            var_s2 = 1;
        }
    } else {
        var_s2 = 1;
    }
    
    if ((int)arg3[0x44/4] & 0x4000) {
        var_s2 = 1;
    }
    
    if (var_s2 != 0) {
        arg3[0xC/4][0xF4/4] = 0;
        (int)arg3[0xC/4][0xFC/4] &= ~0x1000;
        func_800396E0("map", D_80161314_C1D44, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015B96C_BC39C);

void func_8015BED0_BC900(Level_t* level) {
    int temp_t0;
    int i;
    int*** temp_a0;
    int** var_a2;

    i = 0;
    temp_t0 = *(int*)level->_1C[1];
    var_a2 = (int**)level->_1C[1] + 1;
    
    for(i = 0; i < temp_t0; ++i)
    {
        var_a2[i][0x1C/4] &= ~0x80;
        temp_a0 = (int***)var_a2[i][0x24/4];
        if (temp_a0 != 0) {
            ((int*)temp_a0)[0x10/4] &= ~0x400;
            if (G2String_Compare_EQ(temp_a0[0x18/4][0x20/4], &D_801612B4_C1CE4)) {
                ((int*)temp_a0)[0xF4/4] = 3;
            }
            else if (G2String_Compare_EQ(temp_a0[0x18/4][0x20/4], &D_80161324_C1D54)) {
                ((int*)temp_a0)[0xF4/4] = 3;
                ((char*)temp_a0)[0x10E] = 1;
            }
        }
    }
}

void func_8015BFE0_BCA10(Level_t* level, int* arg1) {
    int count;
    int var_a2;
    int i;
    int** temp_v1;
    int* temp_v0;

    temp_v1 = (int**)level->_1C[1];
    count = (int)*temp_v1++;
    var_a2 = 1;
    
    for(i = 0; i < count; ++i)
    {
        temp_v0 = (int*)(temp_v1[i])[0x24/4];
        if ((temp_v0 != 0) && ((temp_v0[0x10/4] & 0xA00) == 0x200)) {
            var_a2 = 0;
        }
    }
    
    if (var_a2 == 0 && (arg1[0x11] & 0x4000)) {
        var_a2 = 1;
    }
    
    if (var_a2 != 0) {
        for(i = 0; i < count; ++i)
        {
            if ((temp_v1[i])[0x24/4] != 0) {
                func_8002E350((temp_v1[i])[0x24/4]);
            }
            temp_v1[i][0x1C/4] |= 0x80;
            temp_v1[i][0x1C/4] &= ~8;
        }
    }
}

void func_8015C110_BCB40(Level_t* level, short** arg1) {
    short* temp_a3;
    short* temp_t0;

    temp_a3 = (short*)level->_20[1];
    temp_t0 = (short*)D_8006CFA0[0x20/4];
    if ((temp_a3 != 0) && ((((int*)temp_a3)[0x10/4] != 0) || (temp_a3[0x14/2] != 0))) {
        
        *(SVECTOR*)(&D_8006CFA0[0x50/4])
          = *(SVECTOR*)(&D_8006CFA0[0x48/4])
              = *(SVECTOR*)&temp_a3[0x10/2];
        
        temp_t0[0x82/2]
            = ((short*)D_8006CFA0)[0x64/2]
            = temp_a3[0x18/2];
        
        if (((short*)D_8006CFA0)[0x4C/2] < temp_a3[0x14/2]) {
            arg1[3][0xC0/2]
                = ((short*)D_8006CFA0)[0x54/2]
                = ((short*)D_8006CFA0)[0x4C/2]
                = temp_a3[0x14/2];
            temp_t0[0x8A/2] |= 1;
        }
    }
}

void func_8015C1D8_BCC08(Level_t* level, char** arg1) {
    int temp_s2;
    int var_s1;
    int** var_s0;

    temp_s2 = func_8004A344();
    level->flags |= 0xC00;
    
    if (level->flags & 0x20000) {
        var_s0 = 1 + (int**)level->_1C[1];
        for(var_s1 = 0; var_s1 < temp_s2; var_s1++)
        {
            if (var_s0[var_s1][9]) {
                func_8002E350(var_s0[var_s1][9]);
            }
            var_s0[var_s1][7] |= 0x80;
            var_s0[var_s1][7] &= ~8;
        }
    } else {
        arg1[3][0x4E] = 0;
        level->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C2D8_BCD08);

int func_8015C63C_BD06C(int arg0) {
    int temp_v0;
    int i;
    int var_s1;
    G2String* temp_a0;
    int** temp_v0_2;
    int* v;
    
    temp_v0 = func_8004A344(arg0);
    var_s1 = -1;
    
    for(i = 0; i < temp_v0; i++)
    {
        if (var_s1 != -1) break;
        if (temp_v0_2 = (int**)func_8004A368(arg0, i)) {
            if (G2String_Compare_EQ(temp_v0_2[0x18/4][0x20/4], &D_801612B4_C1CE4)
                && (((char*)temp_v0_2)[0x10B]) == 1) {
                var_s1 = i;
            }
        }

    }
    return var_s1;
}

void func_8015C728_BD158(Level_t* arg0) {
    char temp_v0;
    int* temp_s1;
    char* s2;

    temp_s1 = (int*)arg0->_20[1];
    arg0->flags |= 0x80;
    s2 = (u8*)(arg0->_F0 + 6);
    func_8004A5B4(arg0, 0x4000);
    arg0->_10D = 5U;
    arg0->_10C = 5U;
    if (temp_s1 != 0) {
        arg0->_C0[1] = (temp_s1[1] * 2);
    }
    arg0->_10E = 1;

    if (temp_s1[1] == 0)
    {
        arg0->_10F = 1U;
        arg0->_110 = 4U;
        arg0->_111 = 9;
        arg0->_112 = 8;
    }
    else if (temp_s1[1] == 1)
    {
        temp_v0 = ((char*)temp_s1)[8];
        arg0->_10D = temp_v0;
        arg0->_10C = temp_v0;
        arg0->_110 = temp_v0;
        arg0->_10F = temp_v0;
    }
    else if (temp_s1[1] == 2)
    {
        arg0->_10F = 0x11U;
        arg0->_110 = 0x14U;
        arg0->_111 = 0xF;
        arg0->_112 = 0x10;
    }
    else
    {
        arg0->_10F = 0U;
        arg0->_110 = 0U;
        arg0->_111 = 0;
        arg0->_112 = 0;
    }
    arg0->_50[3] = s2[0x13];
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015C840_BD270);

void func_8015CD04_BD734(void) {
}

void func_8015CD0C_BD73C(void) {
}


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

void func_8015CD64_BD794(Level_t* arg0) {
    int temp_a1;
    SVECTOR* temp_v0;

    ((short*)&arg0->_100)[1] = 2;
    arg0->_F0[6] = 0x64;
    temp_a1 = arg0->_20[1];
    arg0->flags |= 0x800;
    if (temp_a1 != 0) {
        temp_v0 = (SVECTOR*)((((short*)&arg0->_100)[1] * sizeof(SVECTOR)) + temp_a1 + 4);
        *(SVECTOR*)&D_8006CFA0[0x50/4]
            = *(SVECTOR*)(&D_8006CFA0[0x48/4])
            = *(SVECTOR*)temp_v0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161314_C1D44);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016131C_C1D4C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161324_C1D54);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015CDE0_BD810);

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


void func_8015D52C_BDF5C(Level_t* level, GameState* gs) {
    char buffer[0x10];
    char* v1;
    
    level->_50[3] = -1;
    level->flags |= 0x80;
    
    csprintf(buffer, D_80161394_C1DC4, (short*)level->_20[1] + 2, ((short*)(level->_20[1]))[1]);
    
    level->_F4[2] = GetLevelIndexFromId(buffer);
    
    v1 = ((char****) level->_18)[3][0][5];
    
    if (v1 != 0)
    {
        D_80161684_C20B4 = v1;
        ((int***)level->_18)[3][0][5] = 0;
    }
    
    *((void**)level->_B0 + 1) = func_8015D5E4_BE014;
}

void func_8015D5DC_BE00C(void) {
}

void func_8015D5E4_BE014(int* arg0, Level_t* level) {
    int a1;
    int i;
    int* a3;
    char* a0;

    level->_50[3] = -1;
    level->flags |= 0x80;
    a3 = ((int***)level->_18[3])[0][0xF];
    for(i = 0; i < a3[0]; ++i)
    {
        a1 = D_800E5CD8 & 0x7F;
        a0 = (char*)a3[1 + i];
        a0[4] = a0[0x14] + a1;
        a0[6] = a0[0x16] + a1;
        a0[8] =  a0[0x18] + a1;
        *((int*)a0) = ((int*)(level->_F4[2] * 4 + (int)a0))[0x1C/4];
    }
    
    ((char***)level->_18[0xC/4])[0][0x14/4] = D_80161684_C20B4;
    func_8003D698(level, arg0, 0);
    ((int**)level->_18[0xC/4])[0][0x14/4] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016136C_C1D9C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161374_C1DA4);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161380_C1DB0);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161388_C1DB8);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161394_C1DC4);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015D6F0_BE120);

void func_8015D9E4_BE414(Level_t* arg0) {
    SVECTOR v = *(SVECTOR*)&arg0->_40[4];

    func_80047E64(arg0, -0x14);
    arg0->_40[6] += 0x80;
    arg0->_F4[2] = func_8002DEA8(arg0, func_8003EE84("lvllabl_"));
    *(SVECTOR*)&arg0->_40[4] = v;
    arg0->flags |= 0x10000;
    ((int*)arg0->_F4[2])[0x10/4] |= 0x100000;
    ((int*)arg0->_F4[2])[0x10/4] |= 0x400;
    (*(char**)&arg0->_F0[6])[0x100] = arg0->_112;
    func_8015D52C_BDF5C((Level_t*)arg0->_F4[2], gpGameState8);
}

void func_8015DAC8_BE4F8(Level_t* level) {
    level->_100 = func_8002DEA8(level, func_8003EE84(&D_801613C0_C1DF0 /*etvbutn_*/));
    level->flags |= 0x10000;
    ((int*)level->_100)[0x10/4] |= 0x100000;
    ((int*)level->_100)[0x10/4] |= 0x400;
    ((void**)level->_100)[0xB0/4] = &func_8015E338_BED68;
}

void func_8015DB54_BE584(Level_t* level) {
    int var_s1;
    int** var_s0;

    var_s0 = (int**)level->_D0;
    if (level->_F4[2] != 0) {
        ((int*)level->_F4[2])[0x10/4] &= ~0x400;
        func_80047904(level->_F4[2], -1, 0, 0);
    }
    if (level->_100 != 0) {
        ((int*)level->_100)[0x10/4] &= ~0x400;
        func_8002E350(level->_100);
    }
    
    for(var_s1 = 0; var_s1 < 3; var_s1++)
     {
        if (var_s0[var_s1] != 0) {
            var_s0[var_s1][0x10/4] &= ~0x400;
            func_8002E350(var_s0[var_s1]);
        }
        
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015DC38_BE668);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015DEC8_BE8F8);

void func_8015E274_BECA4(Level_t* level) {
    SVECTOR temp = *(SVECTOR*)(&level->_40[4]);

    func_80047E64(level, 0x3E8);
    *(SVECTOR*)&(((short*)gpGameState8)[0x4C66/2]) = *(SVECTOR*)&level->_40[4];
    ((short*)gpGameState8)[0x4C6A/2] -= 0x20;
    ((short*)gpGameState8)[0x4C6C/2] = level->_60[2] & 0xFFF;
    ((short*)gpGameState8)[0x4C6C/2] = (((short*)gpGameState8)[0x4C6C/2] + *(short*)&level->_1C[3]) & 0xfff;
    *(SVECTOR*)(&level->_40[4]) = temp;
}

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

extern s32 D_80078600;
extern s32 D_80078640;

void func_8015E674_BF0A4(char* arg0, int* arg1, int* arg2) {
    int temp_a0;
    int temp_s0;
    int var_a1;
    int var_s0;
    int var_s1;

    if (D_80078640 == 0) {
        GetRemoteCount(arg0 + 8);
        var_s0 = func_8001A1D8(arg0 + 8) & ~arg2[0x4C9C/4];
        if (D_8006FCD2 != 0) {
            var_s0 &= ~0x2000;
        }
        if (var_s0 != 0) {
            if (*arg0 != 6) {
                func_8004EBAC(arg2[3], arg1[2] + 4, 0);
            }
            *arg0 = 6;
            var_s1 = 0;
            
countbits:
            if (!(var_s0 & 1)) {
                var_s1 += 1;
                var_s0 >>= 1;
                goto countbits;
            }
            
            D_800785CC[var_s1] = 1;
            
            if (var_s1 == 2) {
                if (var_s0 & 0x800) {
                    D_8006FCD2 = 1;
                    D_80078600 = 1;
                    func_800509E0(0x136, 0x64, 0, 0);
                }
            }
            temp_a0 = (1 << var_s1);
            arg2[0x4C9C/4] |= (1 << var_s1);

            if (temp_a0 & 0xF800) {
                func_8004EBAC(arg2[3], arg1[4] + 4, 0);
            }
            else if (temp_a0 & 0x780) {
                func_8004EBAC(arg2[3], arg1[5] + 4, 0);
            }
            else if (temp_a0 & 0x7F) {
                func_8004EBAC(arg2[3], arg1[7] + 4, 0);
            }
        }
        else if (*arg0 == 6)
        {
            func_8004EBAC(arg2[3], arg1[3] + 4, 0);
            *arg0 = 0;
        }
    }
}

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

void func_8015F678_C00A8(short* arg0) {
    int var_a0;
    char* var_v1;

    func_80037B00(0x46, 0x6E);
    func_80038BA0("#2GAME OVER");
    gSPDisplayList(D_80157050++, D_8006D578);
    func_80030DD8("PRESS A TO START NEW GAME", 0x2D, 0xB4, 1);
    gDPPipeSync2(D_80157050);
    if (D_800E5DB2 & 0x8000) {
        ((int*)arg0)[0x4BF4/4] = 5;
        ((int*)arg0)[0x4C9C/4] = 0;
        arg0[0x4C8E/2] = 0;
        arg0[0x4C90/2] = 0;
        ((int*)arg0)[0x4C94/4] = 0;
        ((int*)arg0)[0x4C98/4] = 0;
        
        var_a0 = 0x1E;
        var_v1 = (char*)arg0 + 0x1E;
        
        for(var_a0; var_a0 >= 0; var_a0--)
        {
            (var_v1--)[0x4C6E] = 0;
        }
        
        D_8006FCD2 = 0;
        func_800396E0(0, D_80161314_C1D44, arg0);
    }
}

void func_8015F770_C01A0(void) {
    if (D_80161680_C20B0 < 0x3C) {
        D_80161680_C20B0 += 1;
        func_80037B00(0x5A, 0x50);
        func_80038BA0("GAME LOAD");
        func_80037B00(0x6E, 0x6E);
        func_80038BA0("FAILED");
    } else {
        func_80040170(4);
    }
    if (D_800E5DB2 & 0x8000) {
        D_80161680_C20B0 = 0x3C;
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015F804_C0234);

void func_8015FBBC_C05EC(short* arg0) {

    func_80037B00(0x3C, 0x5F);
    func_80038BA0("PASSWORD IS");
    gSPDisplayList(D_80157050++, D_8006D578);
    func_80030DD8(D_800E5D00, 0x50, 0x82, 1);
    func_80030DD8("PRESS A TO CONTINUE", 0x50, 0xC8, 1);
    gDPPipeSync2(D_80157050);
    if (D_800E5DB2 & 0x8000) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015FC88_C06B8);

INCLUDE_ASM("asm/nonmatchings/map_code", func_8015FF60_C0990);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801614D0_C1F00);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_801614F0_C1F20);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160214_C0C44);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_8016151C_C1F4C);

INCLUDE_RODATA("asm/nonmatchings/map_code", D_80161520_C1F50);

INCLUDE_RODATA("asm/nonmatchings/map_code", jtbl_80161528_C1F58);

void func_80160838_C1268(void) {
    gSPDisplayList(D_80157050++, D_8006D578);
    if (D_800E8EB4 == 0) {
        func_80030DD8("USE ONE PAGE OF MEMORY", 0x41, 0x32, 1);
        func_80030DD8("TO CREATE FILE:", 0x5A, 0x46, 1);
        func_80030DD8(D_80078174, 0x50, 0x73, 0);
    } else {
        func_80030DD8("SAVE TO FILE:", 0x5A, 0x46, 1);
        func_80030DD8((D_800E5CD4 << 5) + D_800E5DDE, 0x50, 0x73, 0);
    }
    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C = 0;
    } else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C = 1;
    }
    func_80030DD8("YES, SAVE FILE", 0x3C, 0x96, 1);
    func_80030DD8("NO, DON'T SAVE", 0x3C, 0xAA, 1);
    func_80030DD8(D_8016151C_C1F4C, 0x2D, (D_8014F34C * 0x14) + 0x96, 1);
    func_80030DD8(D_801613F0_C1E20, 0x55, 0xC8, 1);
    if (D_800E5DB2 & 0x8000) {
        if (D_8014F34C == 0) {
            func_80040170(7);
            if (D_800E8EB4 == 0) {
                D_8006FA54 = 0x10;
                func_800576F0(D_80153A58, 5, 0);
            } else {
                D_8006FA54 = 0xA;
                func_800576F0(D_80153A58, 6, 0);
            }
            return;
        }
        if ((D_800B83C8 < 0x100) || (D_800E97CC >= D_80157034)) {
            D_8014F354 = 1;
            func_80040170(0x14);
            return;
        }
        func_80040170(0xE);
        D_8006FA54 = 0xE;
    }
}

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160ACC_C14FC);

INCLUDE_ASM("asm/nonmatchings/map_code", func_80160DF0_C1820);

void func_801610B8_C1AE8(short* arg0) {
    func_80037B00(0x50, 0x6E);
    func_80038BA0("#2DATA SAVED");
    if (++D_8014F34C >= 0x1F) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
    }
}
