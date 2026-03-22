#include "common.h"

#include "COLLIDE.h"

INCLUDE_ASM("asm/nonmatchings/COLLIDE_B", func_8000D040);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_B", func_8000DB20);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_B", func_8000DFB0);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_B", func_8000E108);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_B", COLLIDE_Instances);

void COLLIDE_InstanceList(InstanceList* instanceList, void* arg1 /*supposedly player instance*/) {
    Instance* instance;
    int i;
    
    if (((short*)gameTracker8)[0x4C64/2] != 1) {
        COLLIDE_Instances(PlayerInstance, arg1);
    }

    for(i = 1; i < 32; i += 2)
    {
        instance = (Instance*)instanceList->group[i].next;

        while(instance != NULL)
        {
            COLLIDE_Instances(instance, arg1);
            instance = (Instance*)instance->node.next;
        }
    }
}
