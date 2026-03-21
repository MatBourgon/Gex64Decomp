#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/PCollideInfo.h"

INCLUDE_ASM("asm/nonmatchings/LIGHT3D", LIGHT_DrawShadow);

void LIGHT_CalcShadowPositions(GameTracker* gameTracker) {
    PCollideInfo collideInfo;
    SVECTOR newPos;
    SVECTOR oldPos;
    Instance* instance;

    
    for (instance = gameTracker->instanceList->first; instance != NULL; instance = instance->next) {
        if (
            (instance->flags2 & 0x40) != 0
            && (instance->flags & 0x200) != 0
            && ((instance->flags & 0x18000000) != 0x08000000)
            || (instance == PlayerInstance && instance->_F4[0] != 5 && !(instance->_F4[2] & 0x1000))
        )
        {
            if (instance->flags & 0x10000000) {
                oldPos.x = newPos.x = ((short*)instance->_2C)[0x36/2]; // matrix[1].l[n] ?
                oldPos.y = newPos.y = ((short*)instance->_2C)[0x3A/2];
                oldPos.z = newPos.z = ((short*)instance->_2C)[0x3E/2];
            } else {
                newPos = instance->position;
                oldPos = instance->position;
            }
            
            if (instance->object->oflags & 0x02000000) {
                newPos.z -= *(short*)&instance->_120;
            } else {
                newPos.z -= 1280;
            }
            oldPos.z += 256;
            
            if (instance == PlayerInstance) {
                collideInfo.collideType = 31;
            } else {
                collideInfo.collideType = 23;
            }
            
            collideInfo.newPoint = &newPos;
            collideInfo.instance = instance;
            collideInfo.oldPoint = &oldPos;
            
            instance->flags |= 0x40;
            COLLIDE_PointAndWorld(&collideInfo, gameTracker8);
            instance->flags &= ~0x40;

            if (collideInfo.type)
            {
                if (collideInfo.type != 1)
                {
                    if (collideInfo.type == 3 && ((short*)collideInfo.prim)[3] & 0x800) {
                        instance->flags |= 0x200000;
                    } else {
                        instance->flags &= 0xFFDFFFFF;
                    }
                    
                    instance->wNormal.x = collideInfo.wNormal.x;
                    instance->wNormal.y = collideInfo.wNormal.y;
                    instance->wNormal.z = collideInfo.wNormal.z;
                }
                else
                {
                    instance->wNormal.x = 0;
                    instance->wNormal.y = 0;
                    instance->wNormal.z = 0x1000;
                }
            }
            
            if (instance == PlayerInstance) {
                func_8001B760(&collideInfo);
            }
            
            instance->shadowPosition = newPos;
            
            instance->shadowPosition.z += 10;
        }
        
        instance->flags &= ~0x8000000;
    }
}
