#include "common.h"

#include "LIST.h"
#include "types/Matrix.h"
#include "types/NodeType.h"

INCLUDE_ASM("asm/nonmatchings/161C0", func_800155C0);

void G2Quat_ToMatrix_S(MATRIX* mat, short* quat);
void func_800157BC(MATRIX* mat, short* euler);

void G2Quat_ToEuler(short* quat, short* euler) {
    MATRIX mat;

    G2Quat_ToMatrix_S(&mat, quat);
    func_800157BC(&mat, euler);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_800157BC);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_ToMatrix_S);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_Slerp_VM);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015DA0);

int func_80015E80(int* arg0, int arg1) {
    if (arg0 != 0) {
        ((unsigned short*)arg0)[6] |= arg1;

        arg0 = (int*)arg0[1];

        if (arg0 != 0) {
            ((unsigned short*)arg0)[6] |= arg1;
        }
    }
}

int func_80015EC0(NodeType* arg0, int* arg1) {
    *(unsigned short*)((int)arg0 + 0xC) |= 0x10;
    
    LIST_DeleteFunc(arg0);
    LIST_InsertFunc((void*)((int)arg1 + 0x11418), arg0);
}

NodeType* func_80015F14(int* arg0) {
    NodeType* temp_v0;
    temp_v0 = LIST_GetFunc((void*)((int)arg0) + 0x2C08);
    
    if (temp_v0 != 0) {
        ((int*)temp_v0)[2] = 0;
        LIST_InsertFunc((void*)((int)arg0 + 0x2C00), temp_v0);
    }
    return temp_v0;
}

// At least used to create two shadows
void* func_80015F60(void* arg0) {
    void* temp_v0;

    temp_v0 = LIST_GetFunc(arg0 + 0x11418); // <-- that's a really big offset into some struct
    if (temp_v0 != 0) {
        memset(temp_v0, 0, 0x74);
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015FA8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800160A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001617C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800162C0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800163A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800166C4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016894);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016D58);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016F84);

int func_800170E8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, short arg8) {

    func_80016F84(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 0, arg8);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017138);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001719C);

int func_80017598(int arg0, int arg1, int arg2, int arg3, int* arg4, int arg5, int arg6) {   
    
    func_8001719C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_800175D0);

int func_800176E8(int arg0, int arg1, int arg2, short arg3) {
    int var_s0 = 0;
    int temp_v0 = func_80015F14(arg2);

    if (temp_v0 != 0) {
        var_s0 = func_8001788C(arg0, arg1, arg2, arg3, temp_v0);
    }
    return var_s0;
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017768);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001788C);

// arg0 and arg1 may be Instance*
void func_80017AB8(short* arg0, short arg1) {
    if (arg0 != NULL) {
        arg0[7] = arg1;
        arg0 = ((short**)arg0)[1];
        if (arg0 != NULL) {
            arg0[7] = arg1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017AE0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017C58);

int func_80017CD8(int* arg0, short arg1, short arg2, short arg3) {
    int temp_v0 = -3;
    if (arg0 != 0) {
    
        *(short*)((int)arg0 + 0x4C) = arg1;
        *(short*)((int)arg0 + 0x4E) = arg2;
        *(short*)((int)arg0 + 0x50) = arg3;
        *(unsigned short*)((int)arg0 + 0xC) &= temp_v0;
        arg0 = arg0[1];
        
        if (arg0 != 0) {
            *(short*)((int)arg0 + 0x4C) = arg1;
            *(short*)((int)arg0 + 0x4E) = arg2;
            *(short*)((int)arg0 + 0x50) = arg3;
            *(unsigned short*)((int)arg0 + 0xC) &= temp_v0;
        }
    }
}

int func_80017D28(int* arg0, short arg1, short arg2, short arg3) {
    int temp_v0 = -3;
    if (arg0 != NULL) {
        // 16-bit stores to offsets 0x52, 0x54, and 0x56
        *(short*)((int)arg0 + 0x52) = arg1;
        *(short*)((int)arg0 + 0x54) = arg2;
        *(short*)((int)arg0 + 0x56) = arg3;
        
        *(unsigned short*)((int)arg0 + 0xC) &= temp_v0;
        
        (int)arg0 = arg0[1];
        
        if (arg0 != NULL) {
            *(short*)((int)arg0 + 0x52) = arg1;
            *(short*)((int)arg0 + 0x54) = arg2;
            *(short*)((int)arg0 + 0x56) = arg3;
            *(unsigned short*)((int)arg0 + 0xC) &= temp_v0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017D78);

int func_80017E48(int* arg0, short arg1) {
    if (arg0 != 0) {
        ((short*)arg0)[34] = arg1;
        ((unsigned short*)arg0)[6] |= 0x100;
        arg0 = (int*)arg0[1];

        if (arg0 != 0) {
            ((short*)arg0)[34] = arg1;
            ((unsigned short*)arg0)[6] |= 0x100;
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/161C0", func_80017E88);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800180C8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018180);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018380);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018460);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800185A4);

int func_8001873C(int* arg0, int* arg1) {
    int* temp_s0;
    int* var_a0;

    if (arg0 != NULL) {
        var_a0 = *(int**)((int)arg1 + 0x11414);
        
        if (var_a0 != NULL) {
            do {
                temp_s0 = *(int**)((int)var_a0 + 4);
                
                if ((*(unsigned short*)((int)var_a0 + 0xC) & 0x20) && (*(int**)((int)var_a0 + 0x4C) == arg0)) {
                    func_80015EC0(var_a0, arg1);
                }
                
                var_a0 = temp_s0;
            } while (var_a0 != NULL);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_800187C4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018974);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018AB4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018B60);

int func_80018DC0(int* arg0, int* arg1, int* arg2) {
    int* temp_v0 = (int*)arg0[11];
    int temp_v1 = temp_v0[311]; 
    
    func_80018B60(arg0, arg1, temp_v0[309], temp_v0[310], temp_v1);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018DFC);
