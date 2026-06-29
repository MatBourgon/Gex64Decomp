#include "common.h"

#include "LIST.h"
#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/161C0", func_800155C0);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_ToEuler);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800157BC);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_ToMatrix_S);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_Slerp_VM);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015DA0);

void func_80015E80(short* arg0, short arg1) {
    if (arg0 != NULL) {
        arg0[6] |= arg1;
        arg0 = ((short**)arg0)[1];
        if (arg0 != NULL) {
            arg0[6] |= arg1;
        }
    }
}

void func_80015EC0(short* arg0, int* arg1) {
    arg0[6] |= 0x10;
    LIST_DeleteFunc(((NodeType*)arg0));
    LIST_InsertFunc(((NodeType*)((char*)arg1 + 0x11418)), ((NodeType*)arg0));
}

int* func_80015F14(int* arg0) {
    int* node;

    node = (int*)LIST_GetFunc(((NodeType*)((char*)arg0 + 0x2C08)));
    if (node != NULL) {
        node[2] = 0;
        LIST_InsertFunc(((NodeType*)((char*)arg0 + 0x2C00)), ((NodeType*)node));
    }
    return node;
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

void func_800170E8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, short arg8) {
    func_80016F84(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 0, (int)arg8);
}

void func_80017138(Instance* instance, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, short arg8) {
    int* animList;

    animList = (int*)instance->object->animList;
    func_800170E8(animList[instance->currentModel], arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001719C);

void func_80017598(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    func_8001719C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_800175D0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800176E8);

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

void func_80017CD8(short* arg0, short arg1, short arg2, short arg3) {
    if (arg0 != NULL) {
        arg0[0x4C/2] = arg1;
        arg0[0x4E/2] = arg2;
        arg0[0x50/2] = arg3;
        arg0[6] &= ~2;
        arg0 = ((short**)arg0)[1];
        if (arg0 != NULL) {
            arg0[0x4C/2] = arg1;
            arg0[0x4E/2] = arg2;
            arg0[0x50/2] = arg3;
            arg0[6] &= ~2;
        }
    }
}

void func_80017D28(short* arg0, short arg1, short arg2, short arg3) {
    if (arg0 != NULL) {
        arg0[0x52/2] = arg1;
        arg0[0x54/2] = arg2;
        arg0[0x56/2] = arg3;
        arg0[6] &= ~2;
        arg0 = ((short**)arg0)[1];
        if (arg0 != NULL) {
            arg0[0x52/2] = arg1;
            arg0[0x54/2] = arg2;
            arg0[0x56/2] = arg3;
            arg0[6] &= ~2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017D78);

void func_80017E48(short* arg0, short arg1) {
    if (arg0 != NULL) {
        arg0[0x44/2] = arg1;
        arg0[6] |= 0x100;
        arg0 = ((short**)arg0)[1];
        if (arg0 != NULL) {
            arg0[0x44/2] = arg1;
            arg0[6] |= 0x100;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017E88);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800180C8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018180);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018380);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018460);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800185A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001873C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800187C4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018974);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018AB4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018B60);

void func_80018DC0(int* arg0) {
    int* sub;

    sub = ((int**)arg0)[0x2C/4];
    func_80018B60(arg0, 0, 0, sub[0x4D4/4], sub[0x4D8/4], sub[0x4DC/4]);
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018DFC);
