#include "common.h"

#include "level/REZOP.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

extern int D_800E5FD8;
extern int D_80154834;

void rezop_rrdoor_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrdoor_OnUpdate);

void rezop_rrdoor_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rrspark_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrspark_OnUpdate);

void rezop_rrspark_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161530_D9CA0);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161558_D9CC8);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnUpdate);

void rezop_rrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrzap_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrzap_OnUpdate);

void rezop_rrzap_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCollide);

void rezop_tbbttn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnCollide);

void rezop_tbplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbplat_OnUpdate);

void rezop_tbplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnUpdate);

void rezop_rezfan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simon_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015B750_D3EC0);

void func_8015B9AC_D411C(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
    if (((short*)arg0)[0xE/2] == 0x1D) {
        ((unsigned short*)arg0)[0x4C/2] = -((unsigned short*)arg0)[0x4C/2];
        ((unsigned short*)arg0)[0x4E/2] = -((unsigned short*)arg0)[0x4E/2];
        ((unsigned short*)arg0)[0x50/2] = -((unsigned short*)arg0)[0x50/2];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015BA40_D41B0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simon_OnUpdate);

void rezop_simon_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnUpdate);

void rezop_crnkplt_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

void rezop_rezcrnk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezcrnk_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezcrnk_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnUpdate);

void rezop_snkplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 4) && (bsp->instanceSpline == PlayerInstance)) {
        GenericCollide(instance, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_srchlit_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_srchlit_OnUpdate);

void rezop_srchlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spotlit_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spotlit_OnUpdate);

void rezop_spotlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015E950_D70C0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015EAB0_D7220);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015ECB8_D7428);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161590_D9D00);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mtntsht_OnCreate);

void rezop_mtntsht_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short dx;
    short dy;

    dx = instance->position.x - instance->initialPos.x;
    dy = instance->position.y - instance->initialPos.y;
    if (((short*)&instance->_F4[2])[1] * ((short*)&instance->_F4[2])[1] < dx * dx + dy * dy) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
    func_80047E64(instance, ((short*)&instance->_F4[2])[0]);
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mtntsht_OnCollide);

void rezop_rebggen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615AC_D9D1C);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615B0_D9D20);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebggen_OnUpdate);

void rezop_rebggen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rbmastr_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rbmastr_OnUpdate);

void rezop_rbmastr_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rebug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x400;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnUpdate);

void rezop_iris_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnUpdate);

void rezop_tvgurny_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

typedef struct {
    short _00;
    short _02;
    short _04;
    short _06;
} GasData;

void rezop_gas_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int t;
    unsigned short* introData;
    char* fc;
    void* data;
    int r;
    unsigned int m;

    t = 0;
    introData = ((unsigned short*)instance->introData);
    data = instance->data;
    fc = (char*)&instance->_F4[2];
    if (instance->flags & 0x20000) {
        if (instance->_F4[0] == 5) {
            func_800331BC(instance->_104);
        }
    } else {
        *(GasData*)&instance->_F4[2] = *(GasData*)data;
        r = rand();
        instance->flags |= 0x80;
        instance->currentTextureAnimFrame = r % 24;
        if (introData != NULL) {
            if (introData[0] != 0xFFFF) {
                *(GasData*)&instance->_F4[2] = *(GasData*)(introData + 1);
                if (((char*)&instance->_100)[2] < 0) {
                    *(int*)&instance->_108 |= 0x8000;
                    ((char*)&instance->_100)[2] = ~((unsigned char*)&instance->_100)[2];
                }
                t = func_8004A61C(instance);
                m = introData[0];
                m %= (unsigned int)(((unsigned short*)&instance->_F4[2])[1] + *(unsigned short*)&instance->_F4[2] + ((unsigned char*)&instance->_100)[1]);
                if (m < ((unsigned short*)&instance->_F4[2])[1]) {
                    *(short*)&instance->_108 = m;
                    instance->_F4[0] = 0;
                } else {
                    m -= ((unsigned short*)&instance->_F4[2])[1];
                    if (m < ((unsigned char*)&instance->_100)[1]) {
                        *(short*)&instance->_108 = m;
                        instance->_F4[0] = 1;
                    } else {
                        m -= ((unsigned char*)&instance->_100)[1];
                        if (m < t) {
                            instance->_F4[0] = 2;
                            t = m;
                        } else {
                            m -= t;
                            if (m < *(unsigned short*)&instance->_F4[2]) {
                                *(short*)&instance->_108 = m;
                                instance->_F4[0] = 3;
                            } else {
                                m -= *(unsigned short*)&instance->_F4[2];
                                if (m < t) {
                                    instance->_F4[0] = 4;
                                    t = t - m;
                                } else {
                                    t = 0;
                                }
                            }
                        }
                    }
                }
            } else {
                instance->_F4[0] = 5;
                t = func_8004A61C(instance) - 1;
                instance->flags |= 0x10000;
            }
        }
        if (fc[6] >= 3) {
            fc[6] = 2;
        }
        func_8004A7B8(instance, fc[6], t);
    }
}

void rezop_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* fc;
    unsigned short x;
    unsigned short y;
    int w;

    fc = (unsigned short*)&instance->_F4[2];
    x = *(unsigned short*)&instance->_108;
    y = instance->currentTextureAnimFrame;
    *(unsigned short*)&instance->_108 = x + 1;
    w = *(int*)&instance->_108;
    instance->currentTextureAnimFrame = y + 1;
    if (w & 0x8000) {
        instance->rotation.z = ((unsigned short)instance->rotation.z + 0x2200) & 0xFFF;
    }
    switch (instance->_F4[0]) {
    case 0:
        if (fc[6] >= fc[1]) {
            fc[6] = 0;
            instance->_F4[0] = 1;
            instance->_F4[1] = 2;
            instance->flags2 &= ~0x10;
        }
        break;
    case 1:
        if (fc[6] >= ((unsigned char*)fc)[5]) {
            fc[6] = 0;
            instance->_F4[0] = 2;
            instance->flags2 &= ~0x10;
            instance->flags |= 0x400;
        } else if (instance->_F4[1] == 2) {
            func_8004A820(instance, 0);
            if (instance->currentAnimFrame >= ((unsigned char*)fc)[4]) {
                instance->_F4[1] = 4;
                instance->currentAnimFrame = ((unsigned char*)fc)[4];
            } else if (instance->flags2 & 0x10) {
                instance->_F4[1] = 4;
            }
        } else if (instance->_F4[1] == 4) {
            func_8004A8A8(instance, 0);
            if (instance->flags2 & 0x10) {
                instance->_F4[1] = 0;
            }
            instance->flags2 &= ~0x10;
        }
        break;
    case 2:
        func_8004A820(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = func_8004A61C(instance);
            instance->_F4[0] = 3;
        }
        break;
    case 3:
        if (fc[6] >= fc[0]) {
            fc[6] = 0;
            instance->_F4[0] = 4;
            instance->flags2 &= ~0x10;
        }
        break;
    case 4:
        func_8004A8A8(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = func_8004A61C(instance);
            instance->_F4[0] = 0;
            func_800331BC(((int*)fc)[2]);
            instance->flags &= ~0x400;
        }
        break;
    case 5:
        break;
    }
}

void rezop_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* bspPlayer;
    int playerState;

    bspPlayer = instance->bspTree->instanceSpline;
    playerState = (int)gameTracker->player;
    if (bspPlayer->object != NULL && bspPlayer == (Instance*)playerState
        && instance->_F4[0] >= 2 && func_80027578(instance, gameTracker, bspPlayer) == 0) {
        playerState = PlayerInstance->_F4[1];
        if (playerState != 0x200000 && playerState != 0x10 && playerState != 0x2000) {
            func_800223F8(gameTracker8, 0x78, 0);
        }
    }
}

void rezop_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int var_s0;
    BTimerIntro* intro;

    intro = (BTimerIntro*)instance->introData;
    instance->_104 = (intro->exitTime * 30);
    instance->_F0[6] = intro->missionTime;
    *(short*)&instance->_100 = 0;
    instance->flags |= 0xC00;
    gameTracker->player->_F4[2] |= 0x4000;
    gameTracker->player->flags |= 0x100;
    func_8002CA2C(4, intro->missionTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->_F4[1] = 0;
}

extern char D_80161590_D9D00[];

void rezop_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char buffer[0x50];
    int timeLeft;
    int minutesLeft;
    int secondsLeft;
    int var_v1;
    short* temp_s2;
    BTimerIntro* intro;

    var_v1 = 1;
    intro = instance->introData;
    temp_s2 = &instance->_F0[6];
    if (*(short*)&instance->_100 == 0) {
        if (temp_s2[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < gameTracker->level->collectibleCountA) {
                if (D_80154834 != 0) {
                    *(short*)&instance->_108 = 1;
                }
                Set3DTextPosition(0x64, 0x69);
                Print3DTextf(ANIMATED_3DTEXT("COLLECT"));
                sprintf(buffer, "%2d", gameTracker->level->collectibleCountA);
                Set3DTextPosition(0x8C, 0x91);
                Print3DTextf(buffer);
                gameTracker->player->flags |= 0x100;
            } else {
                func_8002C18C(4);
                Set3DTextPosition(0x64, 0x64);
                Print3DTextf(ANIMATED_3DTEXT("GET THE"));
                func_8002CA2C(5, temp_s2[0]);
            }
            var_v1 = 0;
            temp_s2[0]--;
        }
        if (temp_s2[6] != 0) {
            if (D_80154834 != 0) {
                var_v1 = 0;
            } else {
                temp_s2[6] = 0;
            }
        }
        if ((((short*)((int**)gameTracker))[0x4C12/2] == 0) && (var_v1 != 0) && (instance->intro->_2C == 0)) {
            ((int*)temp_s2)[0x8/4] -= D_800E5FD8;
        }
        if (((gameTracker->player->_F4[2] & 0x600000) == 0x600000) && (instance->_F4[1] == 0)) {
            temp_s2[0] = (intro->missionTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance->_F4[2] &= ~0x400000;
        }
        if ((gameTracker->player->_F4[2] & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 1;
            gameTracker->player->flags |= 0x100;
        }
        if ((((int*)temp_s2)[0x8/4] < 0) && (((int**)gameTracker)[0x4C00/4] == 0) && (((int**)gameTracker)[0x4C04/4] == 0)) {
            ((int**)gameTracker)[0x4BFC/4] = 0;
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 2;
            gameTracker->player->flags |= 0x100;
        }
        if (temp_s2[2] == 0) {
            timeLeft = ((int*)temp_s2)[0x8/4];
            minutesLeft = timeLeft / 1800;
            secondsLeft = (timeLeft % 1800) / 30;
            // Show text unless < 10s and blinking
            if ((timeLeft > 300) || ((timeLeft % 15) >= 5)) {
                Set3DTextPosition(0x2D, 0xC8);
                if ((timeLeft % 30) >= 15) {
                    sprintf(buffer, D_80161590_D9D00, minutesLeft);  // "%d" — emitted earlier in this TU by a still-undecompiled function (INCLUDE_RODATA blob); a literal here would duplicate it and shift .rodata
                } else {
                    sprintf(buffer, "%d.", minutesLeft);
                }
                Print3DTextf(buffer);
                Set3DTextPosition(0x53, 0xC8);
                sprintf(buffer, "%2d", secondsLeft + 100);
                Print3DTextf(&buffer[1]);
            }
            if ((temp_s2[0] == 0) && ((int)((int**)gameTracker)[0x4BFC/4] < gameTracker->level->collectibleCountA)) {
                Set3DTextPosition(0xF0, 0xC8);
                sprintf(buffer, "%2d", gameTracker->level->collectibleCountA - (int)((int**)gameTracker)[0x4BFC/4]);
                Print3DTextf(buffer);
            }
        }
    } else {
        gameTracker->player->flags |= 0x100;
        if (*(short*)&instance->_100 == 2) {
            // Delay map load
            if (--instance->_104 < 0) {
                func_800396E0("map", "map5", ((int**)gameTracker));
            }
            else
            {
                Set3DTextPosition(0x64, 0x64);
                Print3DTextf("TIME UP!");
            }
        }
    }
}

void rezop_markey_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_markey_OnUpdate);
