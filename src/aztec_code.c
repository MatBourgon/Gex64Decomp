#include "common.h"

#include "types/GameState.h"
#include "types/Level.h"

const int D_8015A090_808B0[4] = { 0x02000014, 0, 0, 0 };

void aztec_funplat_OnCreate(Level_t* level)
{
    short sp10[6];

    if (level->_20[1] == 0) {
        level->_20[1] = (int)D_8015A090_808B0;
    }
    sp10[0] = sp10[4] = level->_40[4];
    sp10[1] = sp10[5] = level->_40[5];
    sp10[2] = level->_E0[2] = level->_40[6];

    // Out of bounds access?
    sp10[6] = level->_40[6] + 0x80;
    func_8000F0B0(gpGameState8->_0004[0], &sp10[0], &sp10[4], level);
}

INCLUDE_ASM("asm/nonmatchings/aztec_code", aztec_funplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/aztec_code", aztec_funplat_OnDestroy);

void aztec_btimer_OnCreate(Level_t* level, int* arg1) {
    int var_s0;
    short* temp_a2;
    int* temp_v1;
    int* temp_v1_2;

    temp_a2 = (short*)level->_20[1];
    level->_104 = (temp_a2[0] * 30);
    level->_F0[6] = (unsigned short)temp_a2[1];
    *(short*)&level->_100 = 0;
    level->flags |= 0xC00;
    temp_v1 = (int*)arg1[3];
    temp_v1[0xFC/4] |= 0x4000;
    temp_v1_2 = (int*)arg1[3];
    temp_v1_2[4] |= 0x100;
    func_8002CA2C(4, temp_a2[1], temp_a2);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    level->_F4[1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/aztec_code", aztec_btimer_OnUpdate);
