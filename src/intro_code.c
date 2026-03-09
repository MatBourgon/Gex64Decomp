#include "common.h"
#include "types/GameState.h"

#include "types/Level.h"

extern char* D_8006CFA0;
extern int D_8006CF60;
extern int D_80154840;
extern char D_8006FCD2;

void intro_rezzull_OnCreate(Level_t* level, int* arg1) {
    char remoteData[4];
    int var_a1;
    short* temp_s1;
    char* temp_v0;
    short* temp_v1;
    int* ptr;

    ptr = &level->_F4[2];
    var_a1 = 0;
    temp_s1 = ((short**)D_8006CFA0)[0x20/4];
    level->flags |= 0x400;
    ((int*)gpGameState8)[0x4C08/4] &= ~0x10;
    D_8006FCD2 = 0;
    do {
        temp_v0 = ((char*)gpGameState8) + var_a1;
        var_a1 += 1;
        temp_v0[0x4C6E] = 0;
    } while (var_a1 <= 13);
    ((char*)gpGameState8)[0x4CC4] = 0;
    ((char*)gpGameState8)[0x4CC5] = 0;
    ((char*)gpGameState8)[0x4CC6] = 0;
    ((int*)gpGameState8)[0x4C94/4] = 0;
    ((int*)gpGameState8)[0x4C98/4] = 0;
    ((int*)gpGameState8)[0x4BF4/4] = 5;
    GetRemoteCount(remoteData);
    ((int*)gpGameState8)[0x4C9C/4] = func_8001A1D8(remoteData);
    ((short*)gpGameState8)[0x4C66/2] = 0;
    ((short*)gpGameState8)[0x4C68/2] = 0;
    ptr[2] = 300;
    func_8002C1AC(0);
    temp_s1[0xDC/2] = 0;
    temp_v1 = (short*)arg1[0x8/4];
    temp_v1[2] += 0xDC;
    ((short*)D_8006CFA0)[0x64/2] = 0x11F0;
    ((short*)D_8006CFA0)[0x48/2] -= 1100;
    ((short*)D_8006CFA0)[0x4A/2] += 2200;
    level->_60[0] = 1024;
    level->_60[1] = 1750;
    level->_60[2] = 0;
    level->_40[5] += 2800;
    level->_40[6] += 900;
}

void intro_rezzull_OnUpdate(Level_t* level, int* arg1) {
    func_8002C1AC(0);
    level->_104--;
    if (level->_104 == 0xAF) {
        D_80154840 = 0x171;
        func_80052758();
    }
    if (level->_104 == 0) {
        ((short*)arg1)[0x9c/2] = -1;
        func_800396E0("map", "map5", gpGameState8);
        ((char*)gpGameState8)[0x4CDC] = 0;
        D_8006CF60 = 0;
    }
}

void intro_gextext_OnCreate(Level_t* level)
{
    level->_104 = 0xB4;
    level->_40[4] = 0x1117;
    level->_40[5] = 0x76C;
    level->_40[6] = 0x288;
    level->_60[0] = 0x47E;
    level->_60[1] = 0x6EA;
    level->_60[2] = 0;
}

void intro_gextext_OnUpdate(Level_t* level)
{
    if (level->_104)
    {
        level->_104--;
        return;
    }
    else
    {
        if (level->_40[6] >= 0x95)
        {
            level->_40[6] -= 0x14;
        }
        D_8006CFA0[0x4E] = 0;
    }
}

void intro_enttext_OnCreate(Level_t* level)
{
    level->_104 = 0xD2;
    level->_40[4] = 0xE56;
    level->_40[5] = 0x76C;
    level->_40[6] = 0x55;
    level->_60[0] = 0x400;
    level->_60[1] = 0x6D6;
    level->_60[2] = 0;
}

void intro_enttext_OnUpdate(void) {
}

void intro_gectext_OnCreate(Level_t* level)
{
    level->_104 = 0xD2;
    level->_40[4] = 0x13BA;
    level->_40[5] = 0x76C;
    level->_40[6] = 0x32;
    level->_60[0] = 0x400;
    level->_60[1] = 0x6D6;
    level->_60[2] = 0;
}

void intro_gectext_OnUpdate(void) {
}

void intro_remtext_OnCreate(Level_t* level)
{
    level->_104 = 0x12C;
    level->_40[4] = 0x157C;
    level->_40[5] = 0x708;
    level->_40[6] = 0x55;
    level->_60[0] = 0x4B0;
    level->_60[1] = 0x6D6;
    level->_60[2] = 0;
}

void intro_remtext_OnUpdate(void) {
}

void intro_gexcopy_OnCreate(Level_t* level)
{
    level->_104 = 0xFA;
    level->_40[4] = 0x1770;
    level->_40[5] = 0xC80;
    level->_40[6] = -0x384;
    level->_60[0] = 0x4B0;
    level->_60[1] = 0x708;
    level->_60[2] = 0;
}

void intro_gexcopy_OnUpdate(Level_t* level)
{
    if (level->_104)
    {
        level->_104--;
    }

    if (level->_104 < 0x32)
    {
        level->_40[4] = 0xFA0;
    }
}