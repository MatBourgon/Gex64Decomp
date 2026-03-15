#include "common.h"

#include "level/INTRO.h"

extern int D_8006CF60;
extern int D_80154840;
extern char D_8006FCD2;

void intro_rezzull_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char remoteData[4];
    int var_a1;
    short* temp_s1;
    char* temp_v0;
    short* temp_v1;
    int* ptr;

    ptr = &instance->_F4[2];
    var_a1 = 0;
    temp_s1 = PlayerInstance->data;
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
    temp_v1 = ((short**)gameTracker)[0x8/4];
    temp_v1[2] += 0xDC;
    PlayerInstance->rotation.z = 0x11F0;
    PlayerInstance->position.x -= 1100;
    PlayerInstance->position.y += 2200;
    instance->rotation.x = 1024;
    instance->rotation.y = 1750;
    instance->rotation.z = 0;
    instance->_40[5] += 2800;
    instance->_40[6] += 900;
}

void intro_rezzull_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    func_8002C1AC(0);
    instance->_104--;
    if (instance->_104 == 0xAF) {
        D_80154840 = 0x171;
        func_80052758();
    }
    if (instance->_104 == 0) {
        ((short*)gameTracker)[0x9c/2] = -1;
        func_800396E0("map", "map5", gameTracker8);
        ((char*)gameTracker8)[0x4CDC] = 0;
        D_8006CF60 = 0;
    }
}

void intro_gextext_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0xB4;
    instance->position.x = 4375;
    instance->position.y = 1900;
    instance->position.z = 648;
    instance->rotation.x = 0x47E;
    instance->rotation.y = 0x6EA;
    instance->rotation.z = 0;
}

void intro_gextext_OnUpdate(Instance* instance, GameTracker* gameTracker)
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
        PlayerInstance->_4E = 0;
    }
}

void intro_enttext_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0xD2;
    instance->position.x = 3670;
    instance->position.y = 1900;
    instance->position.z = 85;
    instance->rotation.x = 0x400;
    instance->rotation.y = 0x6D6;
    instance->rotation.z = 0;
}

void intro_enttext_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void intro_gectext_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0xD2;
    instance->position.x = 5050;
    instance->position.y = 1900;
    instance->position.z = 50;
    instance->rotation.x = 0x400;
    instance->rotation.y = 0x6D6;
    instance->rotation.z = 0;
}

void intro_gectext_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void intro_remtext_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0x12C;
    instance->position.x = 5500;
    instance->position.y = 1800;
    instance->position.z = 85;
    instance->rotation.x = 0x4B0;
    instance->rotation.y = 0x6D6;
    instance->rotation.z = 0;
}

void intro_remtext_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void intro_gexcopy_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0xFA;
    instance->position.x = 6000;
    instance->position.y = 3200;
    instance->position.z = -900;
    instance->rotation.x = 0x4B0;
    instance->rotation.y = 0x708;
    instance->rotation.z = 0;
}

void intro_gexcopy_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_104)
    {
        instance->_104--;
    }

    if (instance->_104 < 0x32)
    {
        instance->position.x = 4000;
    }
}