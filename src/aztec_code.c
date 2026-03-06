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

INCLUDE_ASM("asm/nonmatchings/aztec_code", aztec_btimer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/aztec_code", aztec_btimer_OnUpdate);
