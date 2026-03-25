#include "common.h"

#include "types/GameTracker.h"

extern unsigned short D_800E5DB0;
extern char D_800E5DB6;
extern char D_800E5DB7;

void func_8003A350(int* arg0, unsigned int arg1) {
    int var_v1;

    var_v1 = (arg1 >> 0xB) & 0x10;
    if (arg1 & 0x4000) {
        var_v1 |= 0x20;
    }
    if (arg1 & 0x2000) {
        var_v1 |= 0x1000;
    }
    if (arg1 & 0x10) {
        var_v1 |= 0x800;
    }
    if (arg1 & 8) {
        var_v1 |= 0x40;
    }
    if (arg1 & 2) {
        var_v1 |= 0x80;
    }
    if (arg1 & 1) {
        var_v1 |= 0x100;
    }
    if (arg1 & 4) {
        var_v1 |= 0x200;
    }
    if (arg1 & 0x1000) {
        var_v1 |= 0x4000;
    }
    if (arg1 & 0x20) {
        var_v1 |= 0x8000;
    }
    if (arg1 & 0x800) {
        var_v1 |= 1;
    }
    if (arg1 & 0x400) {
        var_v1 |= 2;
    }
    if (arg1 & 0x200) {
        var_v1 |= 4;
    }
    if (arg1 & 0x100) {
        var_v1 |= 8;
    }
    *arg0 = var_v1;
}

void func_8003A400(int* arg0) {
    int var_a0;
    int var_v1;

    arg0[0] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    if (((short*)gameTracker8)[0x4C12/2] != 8) {
        func_8003A350(arg0, D_800E5DB0);
        
        var_v1 = -D_800E5DB7;
        var_a0 = D_800E5DB6;
        
        if (-10 < var_a0 && var_a0 < 10) {
            var_a0 = 0;
        }
        
        if (-10 < var_v1 && var_v1 < 10) {
            var_v1 = 0;
        }
        
        var_a0 = var_a0 * 4;
        var_v1 = var_v1 * 4;
        
        if (var_a0 > 0x7F) {
            var_a0 = 0x7F;
        }
        
        if (var_a0 < -0x7F) {
            var_a0 = -0x7F;
        }
        
        if (var_v1 > 0x7F) {
            var_v1 = 0x7F;
        }
        if (var_v1 < -0x7F) {
            var_v1 = -0x7F;
        }
        
        arg0[3] = var_a0;
        arg0[4] = var_v1;
    }
}
