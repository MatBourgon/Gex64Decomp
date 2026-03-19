#include "common.h"

#include "INSTANCE.h"
#include "types/GameTracker.h"
#include "types/obtable.h"

void INSTANCE_InitInstanceList(InstanceList *list, InstancePool *pool) {
    long i;

    pool->numFreeInstances = 90;

    for (i = 1; i < 89; i++)
    {
        pool->instance[i].next = &pool->instance[i + 1];
        pool->instance[i].prev = &pool->instance[i - 1];
    }

    pool->instance[0].next = &pool->instance[1];
    pool->instance[0].prev = NULL;

    pool->instance[89].prev = &pool->instance[88];
    pool->instance[89].next = NULL;

    pool->first_free = &pool->instance[0];

    list->pool = pool;

    list->numInstances = 0;

    list->first = NULL;

    for (i = 0; i < 32; i++)
    {
        list->group[i].next = NULL;
        list->group[i].prev = NULL;
    }
}

Instance* INSTANCE_NewInstance(InstanceList* list) {
    Instance* instance;
    Instance* temp;

    if (list->pool->numFreeInstances != 0) {
        list->pool->numFreeInstances--;
        instance = list->pool->first_free;
        list->pool->first_free = instance->next;
        temp = list->first;
        list->first = instance;
        instance->next = temp;
        if (instance->next != NULL) {
            instance->next->prev = instance;
        }
        instance->prev = NULL;
        list->numInstances++;
        return instance;
    }
    return NULL;
}

int INSTANCE_InstanceGroupNumber(Instance* instance) {
    int result = 0;
    
    if (instance->object->oflags & 0x80 && !(instance->flags & 0x8000)) {
        result |= 1;
    }
    
    if ((instance->object->oflags & 0x20) && !(instance->flags & 0x2000)) {
        result |= 2;
    }
    
    if ((instance->object->oflags & 0x40) && !(instance->flags & 0x4000)) {
        result |= 4;
    }
    
    if ((instance->object->oflags & 0x10) && !(instance->flags & 0x1000)) {
        result |= 0x10;
    }
    
    if (instance->object->oflags & 1) {
        result |= 8;
    } else {
        result &= ~2;
        result &= ~1;
    }
    
    return result;
}

void INSTANCE_InsertInstanceGroup(InstanceList* list, Instance* instance) {
    LIST_InsertFunc(&list->group[(INSTANCE_InstanceGroupNumber(instance))], &instance->node);
}

void func_8002CD1C(InstanceList* list, Instance* instance)
{
    Instance* temp = list->first;
    list->first = instance;
    instance->prev = NULL;
    instance->next = temp;
    if (temp != NULL)
    {
        temp->prev = instance;
    }
}

void func_8002CD3C(InstanceList* list, Instance* instance)
{
    instance->flags |= 0x20;
}

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
                   
    temp_v1 = (int*)PlayerInstance->data;

    if (instance == (Instance*)temp_v1[0x19C/4]) {
        temp_v1[0x19C/4] = NULL;
    }

    if (instance == (Instance*)temp_v1[0xA8/4]) {
        temp_v1[0xA8/4] = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002CF4C);

void INSTANCE_CleanUpInstanceList(InstanceList* list, int reset) {
    Instance* next;
    Instance* instance;

    instance = list->first;
    
    while (instance != NULL) {
        next = instance->next;
        if (!(instance->flags & 0x400)) {
            if (instance->flags & 0x20) {
                func_8002CF4C(list, instance, reset);
            }
        } else {
            if (instance->flags & 0x20) {
                instance->flags &= ~0x20;
            }
        }
        instance = next;
    }
    
    instance = list->first;
    
    while (instance != NULL) {
        next = instance->next;
        if (instance->flags & 0x20) {
            INSTANCE_ReallyRemoveInstance(list, instance, reset);
        }
        instance = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002D134);

void INSTANCE_DefaultInit(Instance*, Object*);

void* INSTANCE_BirthObjectFromIntro(Intro* intro) {
    Object* object;
    Instance* instance;

    object = (Object*)intro->_00;
    if (!(intro->flags & 8)) {
        if (intro->instance == NULL) {
            intro->flags |= 8;
            instance = INSTANCE_NewInstance((InstanceList*)gameTracker8->instanceList);
            if (instance != NULL) {
                INSTANCE_DefaultInit(instance, object);
                intro->instance = instance;
                instance->intro = intro;
                
                instance->introData = intro->data;
                
                instance->position = intro->position;
                
                instance->initialPos = instance->position;
                
                instance->oldPos = intro->position;
                
                if (instance->object->oflags & 0x100) {
                    func_8002E0D8(instance); // build static shadow?
                }
                instance->oldRotation.x = 0x1000;
                instance->oldRotation.y = 0x1000;
                instance->oldRotation.z = 0x1000;
                
                if (intro->flags & 0x200) {
                    instance->flags |= 0x20000000;
                }
                if (intro->flags & 0x2000) {
                    instance->flags |= 0x400;
                }
                if (intro->_00[0] & 8) {
                    instance->flags2 |= 8;
                }
                if (intro->_00[0x30/4] & 0x80) {
                    instance->flags |= 0x800;
                }
                if (intro->flags & 0x800) {
                    if (((short*)intro->_00)[2] == -1) {
                        func_80048828(instance, (short)func_80048304(instance), 0, 0, 0);
                        instance->flags ^= 0x01000000;
                        instance->flags |= 0x100000;
                    }
                }
                if (SCRIPT_GetMultiSpline(instance, NULL, NULL) == NULL) {
                    instance->flags &= 0xFDFFFFFF;
                    instance->flags |= 0x100000;
                }
                instance->lightGroup = intro->lightGroup;
                INSTANCE_InsertInstanceGroup((InstanceList*)gameTracker8->instanceList, instance);
                OBTABLE_GetInstanceCollideFunc(instance);
                OBTABLE_GetInstanceProcessFunc(instance);
                if (!(intro->flags & 0x10)) {
                    OBTABLE_InstanceInit(instance);
                }
                
                if (object->_06 != -1) {
                    func_80052944(object->_06);
                }
                return instance;
            }
            return NULL;
        }
    }
    
    return intro->instance;
}

void INSTANCE_ProcessFunctions(InstanceList* list) {
    short direction;
    int scriptIntroData;
    int isValid;
    int var_s6;
    MultiSpline* multi;
    Instance* instance;
    
    var_s6 = 0;
     for (instance = list->first; instance != NULL; instance = instance->next) {
        isValid = 1;
         
        if (instance == (Instance*)gameTracker8->_000C)
        {
            isValid = 0;
        }
        if ((instance->intro != NULL) && (instance->intro->flags & 0x100)) {
            isValid = 0;
        }
        if (instance->flags2 & 4) {
            isValid = 0;
        }
        if ((instance->intro != NULL) && (instance->intro->flags & 0x80) && !(instance->flags & 0x402)) {
            isValid = 0;
        }
         
        if (isValid) {
            
            instance->oldPos.x = instance->position.x;
            instance->oldPos.y = instance->position.y;
            instance->oldPos.z = instance->position.z;
            
            if (!(instance->flags & 0x100000)) {
                multi = (MultiSpline*)SCRIPT_GetMultiSpline(instance, NULL, NULL);
                if (multi != NULL) {
                    if (instance->flags & 0x02000000) {
                        direction = (instance->flags & 0x01000000) ? -1 : 1;
                        if (instance->object->oflags & 0x10000000) {
                            instance->flags |= 0x400;
    
                            if ((SplineMultiIsWhere(multi) << 0x10) != 0) {
                                if (direction > 0) {
                                    instance->intro->flags |= 0x800;
                                } else {
                                    instance->intro->flags &= ~0x800;
                                }
                            }
                        }
                        
                        // InstanceSplineProcess
                        if (func_80048CC8(instance, &multi->curPositional, &multi->curRotational, &multi->curScaling, direction) > 0) {
                            if (instance->flags2 & 0x10000) {
                                func_800331BC(instance->_D0[0]);
                                instance->flags2 &= 0xFFFEFFFF;
                                instance->flags2 &= 0xFFFDFFFF;
                            }
                            if (instance->object->oflags & 0x10000000) {
                                instance->flags &= ~0x400;
                                instance->flags &= 0xFDFFFFFF;
                                instance->flags |= 0x100000;
                            }
                            
                            if (instance->object->oflags & 0x2000) {
                                instance->flags |= 0x10;
                                instance->flags |= 0x100000;
                                INSTANCE_KillInstance(instance);
                                continue;
                            } else {
                                if (instance->object->oflags & 0x1000) {
                                    instance->flags &= 0xFDFFFFFF;
                                    if (instance->object->oflags & 0x800000) {
                                        SCRIPT_InstanceSplineInit(instance, gameTracker8);
                                    }
                                } else if (instance->object->oflags & 0x01000000) {
                                    instance->flags &= 0xFDFFFFFF;
                                }
                                
                                if (multi->positional != NULL)
                                {
                                    if (!(multi->positional->flags & 4) && !(instance->object->oflags & 0x800000))
                                    {
                                        instance->flags ^= 0x01000000;
                                    }
                                }
                                else if (multi->rotational != NULL)
                                {
                                    if (!(multi->rotational->flags & 4) && !(instance->object->oflags & 0x800000))
                                    {
                                        instance->flags ^= 0x01000000;
                                    }
                                }
                                
                                if (instance->object->oflags & 0x200000) {
                                    if (instance->introData != NULL) {
                                        scriptIntroData = *(int*)instance->introData;
                                        if (scriptIntroData != 0) {
                                            SIGNAL_HandleSignal(instance, scriptIntroData + 4, 0);
                                        }
                                    }
                                }
                            }
                        } 
                    } else {
                        if ((instance->flags & 0x84000000) == 0x80000000) {
                            if (instance->object->oflags & 0x800) {
                                if (!(instance->flags & 0x100000)) {
                                    if (!(instance->flags2 & 0x10000)) {
                                        instance->flags2 |= 0x1000;
                                    }
                                }
                                instance->flags |= 0x02000000;
                            }
                            var_s6 = 1;
                        }
                    }
                }
                
            }
            if ((instance->flags2 & 1) && (instance->object->oflags & 0x04000000)) {
                if (instance->introData != NULL) {
                    scriptIntroData = *(int*)instance->introData;
                    if (scriptIntroData != 0) {
                        SIGNAL_HandleSignal(instance, scriptIntroData + 4, 0);
                    }
                }
            }
            
            if ((instance->flags2 & 2) && (instance->object->oflags & 0x08000000)) {
                if (instance->introData != NULL) {
                    scriptIntroData = *(int*)instance->introData;
                    if (scriptIntroData != 0) {
                        SIGNAL_HandleSignal(instance, scriptIntroData + 4, 0);
                    }
                }
            }
            
            if ((instance->flags < 0) || (var_s6 != 0)) {
                instance->flags |= 0x04000000;
            } else {
                instance->flags &= 0xFBFFFFFF;
            }
            
            if ( instance->processFunc != NULL) {
                 instance->processFunc(instance, gameTracker8);
            }
            
            if (instance->object->oflags2 & 4) {
                func_8004F020(instance);
            }
            
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002DAF8);

Instance* INSTANCE_BirthObject(Instance* parent, Object* object) {
    Instance* instance;

    if (object == NULL)
        return NULL;
    
    instance = INSTANCE_NewInstance((InstanceList*)gameTracker8->instanceList);
    
    if (instance != NULL) {
        INSTANCE_DefaultInit(instance, object);
        
        instance->position = parent->position;
        
        instance->initialPos = instance->position;
        instance->oldPos = parent->position;
        
        instance->rotation = parent->rotation;
        instance->oldRotation = parent->oldRotation;
        
        instance->lightGroup = parent->lightGroup;
        instance->parent = parent;
        instance->intro = parent->intro;
        instance->introData = parent->introData;
        
        if (instance->object->oflags & 0x100) {
            func_8002E0D8(instance);
        }
        
        if (SCRIPT_GetMultiSpline(instance, NULL, NULL) == NULL) {
            instance->flags |= 0x100000;
        }
        
        INSTANCE_InsertInstanceGroup((InstanceList*)gameTracker8->instanceList, instance);
        OBTABLE_GetInstanceCollideFunc(instance);
        OBTABLE_GetInstanceProcessFunc(instance);
        instance->flags |= 2;
        OBTABLE_InstanceInit(instance);
        if (object->_06 != -1) {
            func_80052944(object->_06);
        }
        if (parent->flags & 0x20000000) {
            instance->flags |= 0x20000000;
        }
        return instance;
    }
    
    return NULL;
}

Instance* INSTANCE_BirthCachedObject(Instance* parent, int objectTypeId) {
    // Yeah guys, let's do the boundary check after indexing the array
    Object* object = objectAccess[objectTypeId].object;
    if ((objectTypeId < EOBJECT_COUNT) && (object != NULL)) {
        return INSTANCE_BirthObject(parent, object);
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E0D8);

void INSTANCE_DefaultInit(Instance* instance, Object* object) {
    memset(&instance->flags, 0, sizeof(Instance) - offsetof(instance, flags));
    instance->object = object;
    instance->data = object->data; // data?
    if (instance->object->oflags & 0x200) {
        instance->flags2 |= 0x40;
    }
    if (!(instance->object->oflags & 0x01000800)) {
        instance->flags |= 0x02000000;
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E21C);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E294);

void func_8002E350(Instance* instance) {
    instance->flags |= 0x10;
    instance->flags &= ~0x400;
    if ((instance->intro != NULL) && (instance->intro->flags & 4)) {
        func_8004BAAC(instance);
    }
    func_8002CD3C((InstanceList*)gameTracker8->instanceList, instance);
}

void INSTANCE_KillInstance(Instance* instance)
{
    if (!(instance->flags & 0x20))
    {
        INSTANCE_PlainDeath(instance, 1, -1, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E3FC);

INCLUDE_ASM("asm/nonmatchings/2D6E0", func_8002E50C);

void func_8002E704()
{

}
