#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

void GenericInit(Instance* instance, GameTracker* gameTracker) {
    void* spline; // Spline*

    spline = NULL;
    
    if (instance != NULL) {
        if (instance->intro != NULL) {
            if (instance->intro[0x28/4] != NULL) { // instance->intro->multiSpline
                spline = ((void***)instance->intro)[0x28/4][0]; // instance->intro->multiSpline->position
            }
        }
    }
    
    if (spline == NULL) {
        instance->_E0[1] = -10; // zAccl
        instance->_E0[2] = 100; // maxXVel
        instance->_E0[3] = 100; // maxYVel
        instance->_F4[-1] = 100; // maxZVel
    }
    
}

void GenericProcess(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_18[4] != 0)
    {
        func_8002DAF8(instance, -1);
    }
    func_8001DA8C(instance, gameTracker);
}

INCLUDE_ASM("asm/nonmatchings/GENERIC", GenericCollide);
