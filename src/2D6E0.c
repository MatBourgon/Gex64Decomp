#include "common.h"

#include "types/InstanceList.h"

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CAE0);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CB70);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CBE0);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CCD4);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CD1C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CD3C);

void INSTANCE_ReallyRemoveInstance(InstanceList* list, Instance* instance, int reset) {
    int* temp_v1;
    Instance* temp;

    if (!(instance->flags & 2)) {
        instance->intro->flags &= ~reset;
        instance->intro->instance = NULL;
    }
    
    if (instance->prev != NULL) {
        instance->prev->next = instance->next;
    } else {
        list->first = instance->next;
    }
                   
    if (instance->next != NULL) {
        instance->next->prev = instance->prev;
    }       
                   
    list->numInstances--;
                   
    list->pool->numFreeInstances++;
                   
    temp = list->pool->first_free;
                   
    list->pool->first_free = instance;
                   
    instance->prev = NULL;
    instance->next = temp;
                   
    if (temp != NULL) {
        temp->prev = instance;
    }
                   
    func_800300BC(instance);
                   
    if (instance->flags & 0x10000) {
        instance->flags |= 0x20000;
        OBTABLE_InstanceInit(instance);
    }

    if (instance->shadow0 != NULL) {
        instance->shadow0->radius = 0;
    }

    if (instance->shadow1 != NULL) {
        instance->shadow1->radius = 0;
    }

    // EndInstanceSounds?
    if (instance->object->oflags2 & 4) {
        if (instance->flags2 & 0x2000) {
            instance->flags2 &= ~0x2000;
            func_800331BC(((int*)instance->_30)[3]);
            ((int*)instance->_30)[3] = 0;
        }
        if (instance->flags2 & 0x10000) {
            func_800331BC(((int*)instance->_D0)[0]);
            instance->flags2 &= 0xFFFEFFFF;
            instance->flags2 &= 0xFFFDFFFF;
        }
    }
                   
    temp_v1 = (int*)PlayerInstance->_20[0];

    if (instance == (Instance*)temp_v1[0x19C/4]) {
        temp_v1[0x19C/4] = NULL;
    }

    if (instance == (Instance*)temp_v1[0xA8/4]) {
        temp_v1[0xA8/4] = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CF4C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002D068);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002D134);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002D2C0);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002D58C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002DAF8);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002DEA8);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E088);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E0D8);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E180);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E21C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E294);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E350);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E3C4);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E3FC);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E50C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E704);
