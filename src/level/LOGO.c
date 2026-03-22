#include "common.h"

#include <PR/gbi.h>
#include <PR/mbi.h>
#include <ultra64.h>

#include "level/LOGO.h"

extern Gfx D_8006D578[];
extern char D_8014F34C;
extern Gfx* D_80157050;

extern int D_8006FA54;
extern char D_80078171;
extern int D_800B83C8;
extern int D_800E5CD4;
extern short D_800E5DB0;
extern int D_800E97CC;
extern char D_8014F354;
extern OSMesgQueue gGlobalMessageBuffer;
extern int D_80156BDC;
extern int D_80157034;
extern int D_801574FC;
extern char D_8006CF20;
extern unsigned short D_800E5DB2;

void logo_select_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0xC00;
    gameTracker->player->flags |= 0x800;
}

void logo_select_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8002C1AC(0);

    switch (D_8006FA54) {
        
    case 1:
        D_8006FA54 = 2;
        osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SW2, OS_MESG_NOBLOCK);
    break;

    case 3:
        if (D_80156BDC != 0)
        {
            func_80040170(10);
            D_8006FA54 = 12;
        }
        else
        {
            D_80078171 = 1;
            D_8006FA54 = 8;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_COUNTER, OS_MESG_NOBLOCK);
        }
        break;

    case 9:
        D_8006FA54 = 4;
        osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_CART, OS_MESG_NOBLOCK);
        break;

    case 5:
        if (D_80156BDC != 0)
        {
            func_80040170(10);
            D_8006FA54 = 12;
        }
        else if (D_800E5DB0 & 0x1000)
        {
            if (D_800E97CC != 0)
            {
                D_800E5CD4 = 0;
                D_8006FA54 = 6;
            }
            else
            {
                func_80040170(12);
                D_8006FA54 = 12;
            }
        }
        else if ((D_800B83C8 < 0x100) || (D_800E97CC >= 0x10))
        {
            D_8014F354 = 0;
            func_80040170(20);
        }
        else
        {
            D_8006FA54 = 13;
        }

        break;

    case 6:
        if ((D_80156BDC != 0) && (D_80156BDC != 5))
        {
            func_80040170(10);
            D_8006FA54 = 12;
        }
        else if (D_800E5CD4 < D_80157034)
        {
            D_8006FA54 = 7;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SP, OS_MESG_NOBLOCK);
        }
        else
        {
            D_8014F354 = 0;
            func_80040170(11);
            D_8014F34C = func_80014DD4(-1);
            D_801574FC = D_8014F34C;
            D_8006FA54 = 12;
        }
        break;

    case 13:
        func_80040170(18);
        break;
    }
}

void logo_cryslogo_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    D_8006CF20 = 0;
    D_8006FA54 = 0xD;
    instance->_104 = 0;
    instance->flags |= 0x400;
    func_8002C1AC(0);
    ((short*)gameTracker->camera)[0x30/2] = 0xFA0;
    instance->rotation.x = 0x3FE;
    instance->rotation.y = 0x6E1;
    instance->rotation.z = 1;
    instance->position.x = 4332;
    instance->position.y = 4800;
    instance->position.z = -1120;
}

void logo_cryslogo_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8002C1AC(0);
    gameTracker->player->flags |= 0x800;
    
    if (instance->_104 < 0x50)
    {
        instance->_104++;
    }

    if ((D_800E5DB2 & 0x9000) || (instance->_104 == 0x50))
    {
        func_800396E0("logo", "logo1", gameTracker8);
    }
}

void logo_mwgex_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->rotation.z = 0xC8;
    instance->_104 = 0x50;
    instance->flags |= 0x400;
}

FORCE_INLINE void logo_mwgex_OnUpdate_dec(int* a)
{
    (*a)--;
}

void logo_mwgex_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    logo_mwgex_OnUpdate_dec(&instance->_104);
    
    if ((D_800E5DB2 & 0x9000) != 0 || instance->_104 == 0)
    {
        func_800396E0("logo", "logo2", gameTracker8);
    }
    
}

void logo_mwlogo_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->rotation.x = 0x802;
    instance->rotation.y = -0x400;
    instance->rotation.z = 0;
    instance->position.x = ((short*)gameTracker->camera)[0] + 50;
    instance->position.y = 100;
    instance->position.z = 100;
}

void logo_mwlogo_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void logo_rtlogor_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0;
    instance->flags |= 0x400;
    func_8002C1AC(0);
    instance->rotation.x = 0x400;
    instance->rotation.y = 0x6D6;
    instance->rotation.z = 0;
    instance->position.x = 4870;
    instance->position.y = 4500;
    instance->position.z = -150;
    ((short*)gameTracker->camera)[0x4/2] += 230;
    ((short*)gameTracker->camera)[0x2/2] -= 200;
    ((short*)gameTracker->camera)[0] = PlayerInstance->position.x;
    instance->_4E = 0;
    instance->_5E = 0;
}

void logo_rtlogor_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_104 < 0x50) {
        instance->_104++;
    }
    
    if ((D_800E5DB2 & 0x9000) || (instance->_104 == 0x50)) {
        func_8001A790();
    }
}

void func_80159CC8_ECAD8()
{

    gSPDisplayList(D_80157050++, D_8006D578);

    DrawTextToScreen("THERE IS NO CONTROLLER", 0x44, 0x46, 1);
    DrawTextToScreen("CONNECTED IN CONTROLLER", 0x3E, 0x64, 1);
    DrawTextToScreen("SOCKET ONE. SHUT OFF", 0x48, 0x82, 1);
    DrawTextToScreen("POWER, INSERT A", 0x55, 0xA0, 1);
    DrawTextToScreen("CONTROLLER AND RESTART", 0x3D, 0xBE, 1);

    gDPPipeSync(D_80157050++);
}

void func_80159DA0_ECBB0()
{

    gSPDisplayList(D_80157050++, D_8006D578);

    DrawTextToScreen("GEX]: ENTER THE GECKO", 0x46, 0x32, 1);
    DrawTextToScreen("[1998 CRYSTAL DYNAMICS.", 0x3C, 0x46, 1);
    DrawTextToScreen("CRYSTAL DYNAMICS, THE CRYSTAL", 0x26, 0x64, 1);
    DrawTextToScreen("DYNAMICS LOGO, GEX AND THE", 0x32, 0x78, 1);
    DrawTextToScreen("GEX CHARACTER ARE TRADEMARKS", 0x21, 0x8C, 1);
    DrawTextToScreen("OF CRYSTAL DYNAMICS.", 0x46, 0xA0, 1);
    DrawTextToScreen("ALL RIGHTS RESERVED.", 0x4B, 0xB4, 1);
    DrawTextToScreen("LICENSED BY NINTENDO", 0x50, 0xD2, 1);

    gDPPipeSync(D_80157050++);
    
    if (D_8014F34C > 60) {
        func_80040170(0x1C);
        return;
    }

    D_8014F34C++;
}

void func_80159EF0_ECD00(int arg0)
{

    gSPDisplayList(D_80157050++, D_8006D578);

    DrawTextToScreen("PUBLISHED BY", 0x6E, 0x28, 1);
    DrawTextToScreen("MIDWAY HOME ENTERTAINMENT INC.", 0x21, 0x3C, 1);
    DrawTextToScreen("MIDWAY IS A TRADEMARK", 0x46, 0x5A, 1);
    DrawTextToScreen("OF MIDWAY GAMES INC.", 0x4B, 0x6E, 1);
    DrawTextToScreen("DISTRIBUTED BY MIDWAY HOME", 0x37, 0x82, 1);
    DrawTextToScreen("ENTERTAINMENT INC.", 0x55, 0x96, 1);
    DrawTextToScreen("UNDER LICENSE", 0x66, 0xAA, 1);
    DrawTextToScreen("N64 DEVELOPMENT BY", 0x50, 0xC8, 1);
    DrawTextToScreen("REALTIME ASSOCIATES INC.", 0x41, 0xDC, 1);

    gDPPipeSync(D_80157050++);

    if (D_8014F34C > 60)
    {
        func_800396E0(0, "logo4", arg0);
        return;
    }

    D_8014F34C += 1;
}

