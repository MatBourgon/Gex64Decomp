#include "common.h"

#include "COLLIDE.h"

void COLLIDE_PointAndWorld(PCollideInfo* pcollideInfo, GameTracker* gameTracker) {
    InstanceList* instanceList;
    int* segmentAddress;
    TFace* tface;
    Instance* instance;
    int i;

    instanceList = gameTracker->instanceList;
    segmentAddress = gameTracker->level->segmentAddress;
    if (pcollideInfo->collideType & 1) {
        tface = (TFace*)COLLIDE_PointAndTerrain(segmentAddress, pcollideInfo->newPoint, pcollideInfo->oldPoint, pcollideInfo->instance); // COLLIDE_PointAndTerrain
        if (tface != NULL) {
            pcollideInfo->type = 3;
            pcollideInfo->prim = tface;
            pcollideInfo->inst = 0;
            COLLIDE_GetNormal(tface->normal, ((int*)segmentAddress)[0x2C/4] /*terrain->normalList ?*/, &pcollideInfo->wNormal); //  COLLIDE_GetNormal
        } else {
            pcollideInfo->type = 0;
            pcollideInfo->prim = NULL;
            pcollideInfo->inst = 0;
            pcollideInfo->wNormal.x = 0;
            pcollideInfo->wNormal.y = 0;
            pcollideInfo->wNormal.z = 0;
        }
    }
    if (pcollideInfo->collideType & 8) {
        for (i = 16; i < 32; ++i, instance = (Instance*)instance->node.next)
        {
            for(instance = (Instance*)instanceList->group[i].next;
                instance != NULL;
                instance = (Instance*)instance->node.next)
            {
                COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
            }
        }
    }
    else if (pcollideInfo->collideType & 0x10) {

        if (pcollideInfo->collideType & 2)
        {
            for (i = 0; i < 8; ++i)
            {
                for(instance = (Instance*)(&instanceList->group[dyna_clddyna[i]])->next;
                    instance != NULL;
                    instance = (Instance*)instance->node.next)
                {
                    COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
                }
            }
        }

        if (pcollideInfo->collideType & 4)
        {
            for (i = 0; i < 8; ++i)
            {                
                for(instance = (Instance*)(&instanceList->group[stat_clddyna[i]])->next;
                    instance != NULL;
                    instance = (Instance*)instance->node.next)
                {
                    COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
                }
            }
            
        }
        
    } else if (pcollideInfo->collideType & 4) {
        for (i = 0; i < 8; ++i)
            {
                for(instance = (Instance*)(&instanceList->group[dyna_cldstat[i]])->next;
                    instance != NULL;
                    instance = (Instance*)instance->node.next)
                {
                    COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
                }
            }
    }
}
