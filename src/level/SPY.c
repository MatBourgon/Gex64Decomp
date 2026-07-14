#include "common.h"

#include "level/SPY.h"
#include "SCRIPT.h"
#include "SPLINE.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

void spy_qsofa_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void spy_qsofa_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->currentMainState == 1) {
        if (instance->currentAnimFrame == 0) {
            short* data;
            data = gameTracker->player->data;
            data[0x90/2] = 0x180;
            data[0x98/2] = -0x10;
            func_800256A8(gameTracker);
            func_80050508(instance, 0x18, 0, 0x64, 0xFA0);
        }
        func_8002DAF8(instance, -1);
        if (instance->currentAnimFrame == ((short*)instance->object->animList[instance->currentModelAnim])[1] - 1) {
            instance->currentMainState = 0;
            instance->currentAnimFrame = 0;
        }
    }
}

void spy_qsofa_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if ((instance->bspTree->_06 == 4) && (instance->bspTree->instanceSpline == PlayerInstance) && (instance->bspTree->_04 == 5)) {
        instance->currentMainState = 1;
    }
}

void spy_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* objData;
    int* intro;

    objData = instance->object->data;
    intro = instance->introData;
    
    WORK_AS(int, instance->work3) = 0;
    instance->initialPos.x = instance->position.x;
    instance->initialPos.y = instance->position.y;
    instance->initialPos.z = instance->position.z;
    instance->work8 = 0;
    instance->flags |= 0x800;
    WORK_AS(int, instance->work4) = 0x500;
    WORK_AS(int, instance->work5) = 0x80;
    instance->work9 = 0x1000;
    instance->work1 = 4;
    instance->work2 = 0x14;
    
    if (intro != NULL) {
        WORK_AS(int, instance->work4) = intro[0];
    } else if (objData != NULL) {
        WORK_AS(int, instance->work4) = objData[0];
        WORK_AS(int, instance->work5) = objData[1];
        instance->work8 = *(int*)&objData[2];
        if (instance->work8 & 2) {
            instance->work7 = 0x200;
            instance->flags &= ~0x800;
        }
        if (instance->work8 & 0x10) {
            instance->work9 = objData[8];
        }
    }
    
    instance->_D0[0] = WORK_AS_IDX(short, instance->work5, 1);
}

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_launch_OnUpdate);
/* near-match: every instruction matches except ONE scheduler window in the state-1 block.
   The target emits [slt; lw work5; nop; beqz; subu-in-delay] - KMC's reorg pulls the lw
   above the branch and delay-fills the subu (a 2-insn thread steal). Our GCC either
   leaves the lw inside the block (extra nop) or, with the load written before the if,
   hoists it above the slt as well. All arrangements are +/-1 instruction.
   Note the mask40/mask400 variables below are REQUIRED and correct: with literal
   constants the tree folds ~0x40 & ~0x400 into ~0x440 at parse time, while the target
   has two separate ands sharing the ~0x400 register with the instance->flags clear
   (KMC combine does not substitute a multi-use constant register).
extern Object* D_8007684C;
extern int D_800EB8A0;

int func_80159F3C_EB60C(Instance* instance, GameTracker* gameTracker);
void func_8015A014_EB6E4(Instance* instance, GameTracker* gameTracker);
void func_8015A098_EB768(Instance* instance, GameTracker* gameTracker);

void spy_launch_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Instance* player;
    short* pdata;
    int done;
    SVECTOR unused;

    player = gameTracker->player;
    pdata = player->data;
    if (instance->currentMainState == 0 && (instance->work8 & 0x30) == 0x30
        && ((gameTracker->_0014[2] & 0x10) || player->currentSubState == 0x20 || player->currentSubState == 0x80)) {
        if (func_80159F3C_EB60C(instance, gameTracker) == 0) {
            if (pdata[0x78/2] != 0) {
                func_8015A014_EB6E4(instance, gameTracker);
            } else {
                func_8015A098_EB768(instance, gameTracker);
            }
        }
    }
    if (instance->work0 > 0) {
        instance->work0 = instance->work0 - instance->work1;
        if (instance->work0 <= 0) {
            if (!(instance->work8 & 2)) {
                instance->flags |= 0x800;
            }
            instance->position = instance->initialPos;
            instance->work0 = 0;
        }
        instance->scale.x = instance->work0 * (*(int*)&instance->work7) / instance->work2 + 0x1000;
        instance->scale.y = instance->work0 * (*(int*)&instance->work7) / instance->work2 + 0x1000;
        instance->scale.z = instance->work0 * (*(int*)&instance->work7) / instance->work2 + 0x1000;
    }
    if (instance->currentMainState == 2) {
        short* d;
        d = gameTracker->player->data;
        player->work0 |= 0x40;
        d[0x144/2] = instance->work9;
        instance->currentSubState += 1;
        d[0x9E/2] = d[0xA0/2] - 1;
    }
    done = 0;
    if (instance->currentMainState == 1) {
        int total;
        int speed;
        int step;
        int threshold;
        int progress;
        int delta;
        short chunk;

        speed = *(short*)&instance->_112;
        total = WORK_AS(int, instance->work4);
        step = total / speed;
        chunk = 0x20;
        step = step - speed / chunk;
        progress = WORK_AS(int, instance->work3);
        threshold = speed * step;
        if (progress + speed >= total) {
            delta = total - progress;
            done = 1;
        } else {
            delta = speed;
        }
        player->position.z += delta;
        if (done != 0) {
            instance->currentMainState = 3;
            WORK_AS(int, instance->work3) = 0;
            player->flags &= ~0x400000;
        } else {
            WORK_AS(int, instance->work3) += delta;
            if (threshold < WORK_AS(int, instance->work3)) {
                if (chunk < *(short*)&instance->_112) {
                    WORK_AS(int, instance->work5) = ((WORK_AS(int, instance->work5) - chunk) << 16) >> 16;
                }
            }
        }
    }
    if (instance->currentMainState >= 2) {
        if (instance->currentSubState >= 5 || instance->currentMainState != 2) {
            if (func_800257B4(player) != 0 || (player->currentSubState & 0x8000)) {
                int mask40;
                int mask400;
                mask400 = ~0x400;
                mask40 = ~0x40;
                instance->flags &= mask400;
                player->work0 = player->work0 & mask40 & mask400;
                instance->currentMainState = 0;
                instance->currentSubState = 0;
            }
        }
    }
    if (instance->currentMainState > 0) {
        if (D_8007684C != NULL) {
            func_800176E8(&player->position, D_8007684C->modelList[0], D_800EB8A0, 0xA);
        }
    }
    instance->work8 &= ~0x20;
}
*/

int func_80159F3C_EB60C(Instance* instance, GameTracker* gameTracker);
void func_8015A098_EB768(Instance* instance, GameTracker* gameTracker);

void spy_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    Instance* player  = gameTracker->player;
    char var_a2 = (bsp->_06 == 1) ? bsp->_0C[5] : -1;
    
    if (((instance->currentMainState - 1) >= 2U) && (WORK_AS(int, instance->work3) == 0) && (bsp->instanceSpline == player) && (bsp->_04 == 5) && (var_a2 < 8) && (bsp->_08[2] == 0)) {
        if (instance->work8 & 0x10) {
            player->work0 |= 0x200;
            instance->work8 |= 0x20;
        }
        else if ((((func_80025798(player, bsp) != 0) && (instance->work8 == 0)) || (instance->work8 & 1)) && (func_80159F3C_EB60C(instance, gameTracker) == 0)) {
            func_8015A098_EB768(instance, gameTracker);
        }
    }
}

void func_80159EEC_EB5BC(Instance* instance, GameTracker* gameTracker) {
    instance->flags &= ~0x800;
    if (!(instance->work8 & 8)) {
        instance->work0 = instance->work2;
        instance->position.x = PlayerInstance->position.x;
        instance->position.y = PlayerInstance->position.y;
    }
}

extern G2String D_8015AE00_EC4D0;

int func_80159F3C_EB60C(Instance* instance, GameTracker* gameTracker) {
    int* sub;
    Intro** list;
    Intro* entry;
    Instance* other;
    int count;
    int i;

    if (instance->intro != NULL) {
        sub = instance->intro->_04;
        if (sub != NULL) {
            list = (Intro**)(sub + 1);
            count = sub[0];
            for (i = 0; i < count; i++, list++) {
                entry = *list;
                if (G2String_Compare_EQ(entry->object->parentName, &D_8015AE00_EC4D0)) {
                    other = entry->instance;
                    if (other != NULL) {
                        if ((other->currentMainState - 1) < 2U) {
                            return 1;
                        }
                        if (*(int*)&other->work3 != 0) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void func_8015A014_EB6E4(Instance* instance, GameTracker* gameTracker) {
    short* pData;

    pData = (short*)gameTracker->player->data;
    instance->flags |= 0x400;
    func_80159EEC_EB5BC(instance, gameTracker);
    instance->currentMainState = 2;
    PlayerInstance->_E0[1] = pData[4];
    gameTracker->player->work0 |= 0x400;
    func_8004AAA8(instance, 0x18, 0);
}

void func_8015A098_EB768(Instance* instance, GameTracker* gameTracker) {
    short* data;
    Instance* player;

    data = gameTracker->player->data;
    instance->flags |= 0x400;
    func_80159EEC_EB5BC(instance, gameTracker);
    player = PlayerInstance;
    data[0x9C/2] = data[0xA0/2] - 1;
    data[0x9E/2] = data[0xA0/2] - 1;
    instance->currentMainState = 1;
    WORK_AS(int, instance->work5) = ((short*)&instance->_D0[0])[1];
    player->_D0[2] = 0;
    player->_E0[1] = 0;
    player->flags |= 0x400000;
    func_800256A8(gameTracker);
    data[0x8C/2] = 0;
    data[0x8E/2] = 0;
    data[0x90/2] = 0;
    data[0x94/2] = 0;
    data[0x96/2] = 0;
    data[0x98/2] = 0;
    func_8004AAA8(instance, 0x18, 0);
}

void spy_onoff_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
        return;
    }

    instance->currentMainState = 0;
    instance->flags |= 0x80;

    if (instance->introData != NULL && *((int*)instance->introData) & 0x12) {
        instance->currentMainState = 1;
    }

    if (instance->intro->flags & 0x800) {
        instance->currentMainState = instance->currentMainState != 1;
    }

    if (instance->object->data != NULL && *((int*)instance->object->data) != 0) {
        instance->work1 = 1;
    }

    if (instance->currentMainState == 0 || instance->work1 != 0) {
        instance->currentAnimFrame = 0;
    } else if (instance->object->_0A != 0) {
        instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
    }
}

void spy_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = instance->currentMainState ^ 1;

    if (instance->currentSubState == 1) {
        if (instance->currentMainState == 1 || instance->work1 != 0) {
            func_8002DAF8(instance, -1);
        } else {
            func_8002DAF8(instance, -0x3E9);
        }

        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->currentSubState = 0;
            if (instance->currentMainState == 0 || instance->work1 != 0) {
                instance->currentAnimFrame = 0;
            } else if (instance->object->_0A != 0) {
                instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
            }
        }
    }
}

extern char D_8015AE0C_EC4DC[];

void spy_onoff_OnCollide(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    BSPTree* bsp;
    int** list;
    Instance* other;
    int match;
    int toggled;
    int checkState;
    int fire;
    short i;

    match = 0;
    toggled = 0;
    checkState = 0;
    fire = 0;
    intro = instance->introData;
    bsp = instance->bspTree;
    if (intro != NULL && bsp->_06 == 1 && bsp->_0C[5] >= 8U && instance->currentSubState != 1) {
        list = (int**)(intro + 2);
        if (intro[1] == 0) {
            match = 1;
        } else if (intro[1] == 1) {
            if (instance->currentMainState == 0) {
                match = 1;
                checkState = 1;
            }
        } else if (intro[1] == 2) {
            if (instance->currentMainState == 1) {
                match = 1;
                checkState = 1;
            }
        }
        for (i = 0; i < intro[0]; i++, list++) {
            other = ((Intro*)list[0])->instance;
            if (other == NULL) continue;
            if (other->flags & 0x2000000) continue;
            if (match == 0) continue;
            if (checkState != 0) {
                if (!((((unsigned short*)intro)[1] & 1) && !(other->flags & 0x1000000))) {
                    if (!(((unsigned short*)intro)[1] & 2)) continue;
                    if (!(other->flags & 0x1000000)) continue;
                }
            }
            other->flags &= ~0x100000;
            if (!(other->flags2 & 0x10000)) {
                other->flags2 |= 0x1000;
            }
            other->flags |= 0x2000000;
            toggled = 1;
        }
        if ((match != 0 && toggled != 0) || intro[0] == 0) {
            instance->intro->flags ^= 0x800;
            instance->currentMainState ^= 1;
            fire = 1;
        } else if (G2String_Compare_EQ(instance->object->name, D_8015AE0C_EC4DC)) {
            fire = 1;
        }
        if (fire != 0) {
            if (instance->object->_0A != 0) {
                instance->currentSubState = 1;
            }
            if (*(int*)list == 0x29A) {
                SIGNAL_HandleSignal(instance, (int*)((int*)list)[1] + 1, 0);
            }
        }
    }
}

extern short D_8015AD70_EC440[];

void spy_gnrobot_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->introData == NULL) {
        instance->introData = D_8015AD70_EC440;
    }
    instance->work1 = ((short*)instance->introData)[1];
}

typedef struct {
    short frame;
    unsigned short anim;
} GnRobotKeyframe;

void spy_gnrobot_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    MultiSpline* ms;
    unsigned short frame;
    GnRobotKeyframe* p;
    int i;
    SVECTOR unused; /* dead local needed for the original's 0x28 stack frame */

    intro = instance->introData;
    ms = SCRIPT_GetMultiSpline(instance, NULL, NULL);
    frame = SplineGetFrameNumber(ms->positional, &ms->curPositional);
    instance->work0 += 1;
    p = (GnRobotKeyframe*)intro;
    if (((int*)intro)[1] > 0) {
        i = 0;
        do {
            if (p[i + 2].frame == frame) {
                instance->currentModelAnim = p[i + 2].anim;
                instance->currentAnimFrame = 0;
            }
            i++;
        } while (i < ((int*)intro)[1]);
    }
    func_8002DAF8(instance, -1);
    if (instance->currentAnimFrame == ((short*)instance->object->animList[instance->currentModelAnim])[1] - 1) {
        instance->currentModelAnim = ((unsigned short*)intro)[0];
    }
}

void spy_gnrobot_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    long* fc = &instance->work0;

    if ((bsp->instanceSpline == PlayerInstance) && (bsp->_0C[5] == 8)) {
        fc[1]--;
    }

    if (fc[1] == 0) {
        INSTANCE_KillInstance(instance);
    } else {
        func_80022D54(instance, gameTracker);
    }
}

void spy_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int var_s0;
    BTimerIntro* intro;

    intro = (BTimerIntro*)instance->introData;
    instance->work2 = (intro->exitTime * 30);
    WORK_AS_IDX(short, instance->work0, 0) = intro->missionTime;
    WORK_AS_IDX(short, instance->work1, 0) = 0;
    instance->flags |= 0xC00;
    gameTracker->player->work0 |= 0x4000;
    gameTracker->player->flags |= 0x100;
    func_8002CA2C(4, intro->missionTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->currentSubState = 0;
}

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AD70_EC440);

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE00_EC4D0); // launch__

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE0C_EC4DC); // gong____

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE10_EC4E0);

extern int D_800E5FD8;
extern int D_80154834;

void spy_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char buffer[0x50];
    int timeLeft;
    int minutesLeft;
    int secondsLeft;
    int var_v1;
    short* temp_s2;
    BTimerIntro* intro;

    var_v1 = 1;
    intro = instance->introData;
    temp_s2 = WORK_AS_PTR(short, instance->work0);
    if (WORK_AS_IDX(short, instance->work1, 0) == 0) {
        if (temp_s2[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < gameTracker->level->collectibleCountA) {
                if (D_80154834 != 0) {
                    WORK_AS_IDX(short, instance->work3, 0) = 1;
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
        if (((gameTracker->player->work0 & 0x600000) == 0x600000) && (instance->currentSubState == 0)) {
            temp_s2[0] = (intro->missionTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->currentSubState = 1;
            PlayerInstance->work0 &= ~0x400000;
        }
        if ((gameTracker->player->work0 & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
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
                    sprintf(buffer, "%d", minutesLeft);
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
        if (WORK_AS_IDX(short, instance->work1, 0) == 2) {
            // Delay map load
            if (--instance->work2 < 0) {
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


