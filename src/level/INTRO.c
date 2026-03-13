#include "common.h"
#include "types/GameTracker.h"

#include "types/Instance.h"

extern char* PlayerInstance;
extern int D_8006CF60;
extern int D_80154840;
extern char D_8006FCD2;

void intro_rezzull_OnCreate(Instance* instance, int* arg1) {
    char remoteData[4];
    int var_a1;
    short* temp_s1;
    char* temp_v0;
    short* temp_v1;
    int* ptr;

    ptr = &instance->_F4[2];
    var_a1 = 0;
    temp_s1 = ((short**)PlayerInstance)[0x20/4];
    instance->flags |= 0x400;
    gameTracker8->gameFlags &= ~0x10;
    D_8006FCD2 = 0;
    do {
        temp_v0 = ((char*)gameTracker8) + var_a1;
        var_a1 += 1;
        temp_v0[0x4C6E] = 0;
    } while (var_a1 <= 13);
    ((char*)gameTracker8)[0x4CC4] = 0;
    ((char*)gameTracker8)[0x4CC5] = 0;
    ((char*)gameTracker8)[0x4CC6] = 0;
    ((int*)gameTracker8)[0x4C94/4] = 0;
    ((int*)gameTracker8)[0x4C98/4] = 0;
    ((int*)gameTracker8)[0x4BF4/4] = 5;
    GetRemoteCount(remoteData);
    ((int*)gameTracker8)[0x4C9C/4] = func_8001A1D8(remoteData);
    ((short*)gameTracker8)[0x4C66/2] = 0;
    ((short*)gameTracker8)[0x4C68/2] = 0;
    ptr[2] = 300;
    func_8002C1AC(0);
    temp_s1[0xDC/2] = 0;
    temp_v1 = (short*)arg1[0x8/4];
    temp_v1[2] += 0xDC;
    ((short*)PlayerInstance)[0x64/2] = 0x11F0;
    ((short*)PlayerInstance)[0x48/2] -= 1100;
    ((short*)PlayerInstance)[0x4A/2] += 2200;
    instance->_60[0] = 1024;
    instance->_60[1] = 1750;
    instance->_60[2] = 0;
    instance->_40[5] += 2800;
    instance->_40[6] += 900;
}

void intro_rezzull_OnUpdate(Instance* instance, int* arg1) {
    func_8002C1AC(0);
    instance->_104--;
    if (instance->_104 == 0xAF) {
        D_80154840 = 0x171;
        func_80052758();
    }
    if (instance->_104 == 0) {
        ((short*)arg1)[0x9c/2] = -1;
        func_800396E0("map", "map5", gameTracker8);
        ((char*)gameTracker8)[0x4CDC] = 0;
        D_8006CF60 = 0;
    }
}

void intro_gextext_OnCreate(Instance* instance)
{
    instance->_104 = 0xB4;
    instance->_40[4] = 0x1117;
    instance->_40[5] = 0x76C;
    instance->_40[6] = 0x288;
    instance->_60[0] = 0x47E;
    instance->_60[1] = 0x6EA;
    instance->_60[2] = 0;
}

void intro_gextext_OnUpdate(Instance* instance)
{
    if (instance->_104)
    {
        instance->_104--;
        return;
    }
    else
    {
        if (instance->_40[6] >= 0x95)
        {
            instance->_40[6] -= 0x14;
        }
        PlayerInstance[0x4E] = 0;
    }
}

void intro_enttext_OnCreate(Instance* instance)
{
    instance->_104 = 0xD2;
    instance->_40[4] = 0xE56;
    instance->_40[5] = 0x76C;
    instance->_40[6] = 0x55;
    instance->_60[0] = 0x400;
    instance->_60[1] = 0x6D6;
    instance->_60[2] = 0;
}

void intro_enttext_OnUpdate(void) {
}

void intro_gectext_OnCreate(Instance* instance)
{
    instance->_104 = 0xD2;
    instance->_40[4] = 0x13BA;
    instance->_40[5] = 0x76C;
    instance->_40[6] = 0x32;
    instance->_60[0] = 0x400;
    instance->_60[1] = 0x6D6;
    instance->_60[2] = 0;
}

void intro_gectext_OnUpdate(void) {
}

void intro_remtext_OnCreate(Instance* instance)
{
    instance->_104 = 0x12C;
    instance->_40[4] = 0x157C;
    instance->_40[5] = 0x708;
    instance->_40[6] = 0x55;
    instance->_60[0] = 0x4B0;
    instance->_60[1] = 0x6D6;
    instance->_60[2] = 0;
}

void intro_remtext_OnUpdate(void) {
}

void intro_gexcopy_OnCreate(Instance* instance)
{
    instance->_104 = 0xFA;
    instance->_40[4] = 0x1770;
    instance->_40[5] = 0xC80;
    instance->_40[6] = -0x384;
    instance->_60[0] = 0x4B0;
    instance->_60[1] = 0x708;
    instance->_60[2] = 0;
}

void intro_gexcopy_OnUpdate(Instance* instance)
{
    if (instance->_104)
    {
        instance->_104--;
    }

    if (instance->_104 < 0x32)
    {
        instance->_40[4] = 0xFA0;
    }
}