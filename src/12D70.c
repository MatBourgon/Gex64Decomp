#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012170);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800121F8);

INCLUDE_ASM("asm/nonmatchings/12D70", func_8001233C);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012398);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800123F4);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012450);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012594);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012834);

INCLUDE_ASM("asm/nonmatchings/12D70", func_8001293C);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012A1C);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012BD0);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012C74);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012D20);

void common_remred_OnCreate(void) {
}

extern char D_8007B97C[];
extern int D_800EB8A0;

void common_remred_OnUpdate(Instance* arg0, GameTracker* gameTracker) {
    SVECTOR pos;
    SVECTOR vel;
    int temp_ret;
    int temp_ret_2;
    Instance* temp_v0_2;
    Object* temp_v0;
    Model* model;


    temp_v0 = (Object*)OBTABLE_FindObject(&D_8007B97C);
    if (temp_v0 == NULL || (arg0->_C0[1] == 1)) return;

    model = temp_v0->modelList[0];
    pos.x = arg0->position.x;
    pos.y = arg0->position.y;
    pos.z = arg0->position.z + 0x60;
    temp_v0_2 = (Instance*)func_800176E8(&pos, model, D_800EB8A0, 0x1E);
    if (temp_v0_2 != NULL) {
        temp_ret = rand();
        vel.x = 0xF - (temp_ret % 30);
        temp_ret_2 = rand(temp_ret / 30);
        vel.y = 0xF - (temp_ret_2 % 30);
        vel.z = (rand(temp_ret_2 / 30) % 40) + 0xA;
        func_80017CD8(temp_v0_2, vel.x, vel.y, vel.z);
        func_80017D28(temp_v0_2, 0, 0, -2);
    }
}

void common_remred_OnCollide(void) {
}

void common_tvscrho_OnCreate(void) {
}

void common_tvscrho_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    instance->_D0[0]++;
}

void common_tvscrho_OnCollide(void) {
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_kgateop_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_kgateop_OnUpdate);

void common_kgateop_OnCollide(void) {
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_tailpuf_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_tailpuf_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_magic_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_magic_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_magic_OnCollide);

INCLUDE_ASM("asm/nonmatchings/12D70", common_proxsig_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800135C4);

INCLUDE_ASM("asm/nonmatchings/12D70", common_proxsig_OnUpdate);

void common_proxsig_OnCollide(void) {
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_animseq_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_animseq_OnUpdate);

void common_animseq_OnCollide(void) {
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_gengen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_gengen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_tstrplt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_tstrplt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_tstrplt_OnCollide);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80013E20);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80013EC0);

INCLUDE_ASM("asm/nonmatchings/12D70", func_8001409C);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014294);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014374);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800145C8);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800146FC);

INCLUDE_ASM("asm/nonmatchings/12D70", func_800148D4);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014C80);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014D00);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014D94);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014DD4);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80014E28);
