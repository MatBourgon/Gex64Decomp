#include "common.h"
#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001AE60);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B760);

int func_8001B7C0(int* arg0) {
    int temp_v0;
    int temp_a0;
    temp_v0 = *(int*)((int)arg0 + 0xD8) + *(int*)((int)arg0 + 0xE4);
    temp_a0 = -*(int*)((int)arg0 + 0xF0);
    *(int*)((int)arg0 + 0xD8) = temp_v0;

    if (temp_v0 < temp_a0) {
        *(int*)((int)arg0 + 0xD8) = temp_a0;
    }
    *(unsigned short*)((int)arg0 + 0x4C) += *(int*)((int)arg0 + 0xD8);
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B804);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001BDB8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C260);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C438);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C4F8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C650);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C738);

void func_8001C920(int* arg0, int* arg1, short* arg2) {
    short temp = arg2[110];
    
    if (temp != 0) {
        temp -= 1;
        arg2[110] = temp;
        if (arg0[62] != 0x4000000) {
            
            if (temp & 2) {
                arg0[4] |= 0x800;
            } else {

                arg0[4] &= ~0x800;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C978);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CB9C);

void func_8001CDFC(short* arg0, short arg1, short arg2) {
    short temp_v0;
    short temp_v0_2;

    temp_v0 = *arg0;
    if ((temp_v0 + arg2) < arg1) {
        *arg0 = temp_v0 + arg2;
    }
    temp_v0_2 = *arg0;
    if (arg1 < (temp_v0_2 - arg2)) {
        *arg0 = temp_v0_2 - arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CE54);

extern int D_8006CFA4;

void func_8001CF90(int *arg0, int *arg1) {
    arg0[0x3D] = 3;
    
    if (arg1[0x12FD] == 1) {
        D_8006CFA4 = 0xBE;
    } 
    else {
        D_8006CFA4 = 0x5A;
    }
    
    if ((arg1[0x1302] & 0x20000) != 0) {
        D_8006CFA4 -= 0x1E;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CFE8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D180);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D29C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D950);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DA8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DC80);

int func_8001DDD8(int* arg0, int* arg1, int* arg2) {
    if (!(*(unsigned short*)((int)arg2 + 0x8A) & 1)) {
        *(int*)((int)arg0 + 0xF8) = 0x40;
        *(unsigned char*)((int)arg0 + 0x4E) = 0x13;
        *(unsigned short*)((int)arg0 + 0x5E) = 0;
        
        *(unsigned short*)((int)arg2 + 0x148) = *(unsigned short*)((int)arg0 + 0x4C);
        
        if (*(unsigned short*)((int)arg2 + 0x8A) & 0x100) {
            *(unsigned short*)((int)arg2 + 0xEC) = 0;
        } else {
            *(unsigned short*)((int)arg2 + 0xEC) = *(unsigned short*)((int)arg2 + 0x10);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE2C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DFC0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E064);

int func_8001E0C4(int* arg0, int* arg1, int* arg2, int* arg3) {
    if ((*(int*)((int)arg3 + 4) & 0x10) && !(*(int*)((int)arg0 + 0xFC) & 0x8000)) {
        *(int*)((int)arg0 + 0xF8) = 0x20;
        *(unsigned char*)((int)arg0 + 0x4E) = 0x19;
        *(unsigned short*)((int)arg0 + 0x5E) = 0;
        *(int*)((int)arg0 + 0xFC) &= ~8;
    }
}

int func_8001E114(int* arg0, int* arg1, int* arg2, int* arg3) {
    if ((*(int*)((int)arg3 + 4) & 0x3000) && !(*(int*)((int)arg0 + 0xFC) & 0x8000)) {
        *(int*)((int)arg0 + 0xF8) = 0x1000;
        *(unsigned char*)((int)arg0 + 0x4E) = 0x1B;
        *(unsigned short*)((int)arg0 + 0x5E) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E154);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E1C0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E368);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E648);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E6E0);

void func_8001E838(Instance* instance, void* arg1, unsigned short* data, int arg3) {
    if (data[0x45] & 0x2) {
        if (!(instance->_F4[2] & 0x8000)) {
            instance->_F4[1] = 0x400;
            instance->currentModelAnim = 0x18;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E874);

// arg0 may be Instance*
void func_8001E980(int* arg0, int arg1, unsigned short* arg2) {
    if (!(arg2[0x45] & 0x10)) {
        arg0[0x3E] = 0x80000;
        ((short*)arg0)[0x2F] = 0;
        ((char*)arg0)[0x4E] = 0x21;
    }
}

int func_8001E9AC(int* arg0, int* arg1, int* arg2) {
    if ((*(unsigned short*)((int)arg2 + 0x8A) & 0x40) && !(*(int*)((int)arg0 + 0xFC) & 0x8000)) {
        *(int*)((int)arg0 + 0xF8) = 0x800;
        *(unsigned char*)((int)arg0 + 0x4E) = 0x17;
        *(unsigned short*)((int)arg0 + 0x5E) = 0;
    }
}
