#include "common.h"

#include "types/Level.h"

INCLUDE_ASM("asm/nonmatchings/nypd_code", func_80159720_C6800);

INCLUDE_ASM("asm/nonmatchings/nypd_code", nypd_slider_OnCreate);

INCLUDE_ASM("asm/nonmatchings/nypd_code", nypd_slider_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/nypd_code", nypd_slider_OnDestroy);

void nypd_btimer_OnCreate(Level_t* level, int* arg1) {
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

INCLUDE_ASM("asm/nonmatchings/nypd_code", nypd_btimer_OnUpdate);
