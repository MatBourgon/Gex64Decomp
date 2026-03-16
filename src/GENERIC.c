#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

void GenericInit(Instance* instance, GameTracker* gameTracker) {
    void* spline; // Spline*

    spline = NULL;
    
    if (instance != NULL) {
        if (instance->intro != NULL) {
            if (instance->intro->multiSpline != NULL) {
                spline = instance->intro->multiSpline->positional;
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
    if (instance->object->animList != 0)
    {
        func_8002DAF8(instance, -1);
    }
    func_8001DA8C(instance, gameTracker);
}

void GenericCollide(Instance* instance, GameTracker* gameTracker) {
    int a0, a2, a3;
    int v0, v1;
    int t0;

    a2 = instance->_70[2];

    t0 = 0;
    if (((Instance**)a2)[0x14/4] != PlayerInstance) {
        v1 = ((short*)a2)[6/2];
        a3 = 5;
        if (v1 == a3 || v1 == 1) {
                    
            if (((short*)a2)[4/2] != a3)
            {
                if (((short*)a2)[4/2] == 1) goto _78; // 4c, 50
                goto _e4; // 54, 58
            }
            else
            {
                v0 = ((int*)a2)[8/4];
                v1 = ((short*)v0)[0];
                a3 = ((unsigned char*)v0)[3];
                v1 &= 0x8000;
                goto _8c; // 70, 74
            }
        
            _78:
            v0 = ((int*)a2)[8/4];
            v1 = ((int*)v0)[0];
            a3 = ((unsigned char*)v0)[5];
            v1 &= 0x8000;
        
            _8c:
            if (v1 != 0)
            {
                t0 = 0;
            }
            else
            {
                if (((short*)a2)[6/2] == 5)
                {
                    v0 = ((int*)a2)[12/4];
                    v0 = ((unsigned char*)v0)[3];
                
                    v0 = a3 < v0;
                }
                else
                {
                    v0 = ((int*)a2)[12/4];
                    v0 = ((unsigned char*)v0)[5];
                    v0 = a3 < v0;
                }
            
                if (v0 != 0)
                {
                    t0 = 1;
                }
            }
        }
    }

    _e4:
    if (t0 != 0)
    {
        INSTANCE_KillInstance(instance);
    }
    else
    {
        func_80022D54(instance, gameTracker);
    }
}
