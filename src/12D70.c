#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/obtable.h"
#include "types/Vector.h"
#include "types/HBox.h"
#include "types/HInfo.h"

void COLLIDE_GetNormal(short nNum, short* nrmlArray, SVECTOR* nrml) {
    short* nrmls;

    if (nNum >= 0) {
        nrmls = &nrmlArray[nNum * 3];
        nrml->x = *nrmls++;
        nrml->y = *nrmls++;
        nrml->z = *nrmls;
    } else {
        nrmls = &nrmlArray[-nNum * 3];
        nrml->x = -*nrmls++;
        nrml->y = -*nrmls++;
        nrml->z = -*nrmls;
    }
}

void COLLIDE_InsertPoint( SVector* point, SVector* normal, int* dist,
                    SVector* collidePoint0, SVector* normal0, int* collideT0,
                    SVector* collidePoint1, SVector* normal1, int* collideT1)
{
    if (*dist < *collideT0) {
        collidePoint1->x = collidePoint0->x;
        collidePoint1->y = collidePoint0->y;
        collidePoint1->z = collidePoint0->z;
        normal1->x = normal0->x;
        normal1->y = normal0->y;
        normal1->z = normal0->z;
        
        *collideT1 = *collideT0;
        collidePoint0->x = point->x;
        collidePoint0->y = point->y;
        collidePoint0->z = point->z;
        normal0->x = normal->x;
        normal0->y = normal->y;
        normal0->z = normal->z;
        *collideT0 = *dist;
    }
    else if (*dist < *collideT1) {
        collidePoint1->x = point->x;
        collidePoint1->y = point->y;
        collidePoint1->z = point->z;
        normal1->x = normal->x;
        normal1->y = normal->y;
        normal1->z = normal->z;
        *collideT1 = *dist;
    }
}

int COLLIDE_WithinYZBounds(SVector* point, HBox* hbox) {
    return point->y >= hbox->minY
        && point->y <= hbox->maxY
        && point->z >= hbox->minZ
        && point->z <= hbox->maxZ;
}

int COLLIDE_WithinXZBounds(SVector* point, HBox* hbox) {
    return point->x >= hbox->minX
        && point->x <= hbox->maxX
        && point->z >= hbox->minZ
        && point->z <= hbox->maxZ;
}

int COLLIDE_WithinXYBounds(SVector* point, HBox* hbox) {
    return point->x >= hbox->minX
        && point->x <= hbox->maxX
        && point->y >= hbox->minY
        && point->y <= hbox->maxY;
}

extern int collide_t1; // collide_t0?
extern int collide_t0; // collide_t1?
extern SVector* collide_normal1;
extern SVector* collide_point0;
extern SVector* collide_point1;
extern SVector* collide_normal0;

typedef int(*CollisionFunction)(SVector*, HBox*);
void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, SVector* start, LVECTOR* line, HBox* hbox, CollisionFunction collideBoundFunc, SVector* normal) {
    SVector point;
    int dist;

    if (lineDist == 0)
        return;
    
    dist = -((startDist - planeDist) << 12) / lineDist;
    
    if (dist < 0 || dist > 0x1000)
        return;
        
    point.x = start->x + ((line->x * dist) >> 12);
    point.y = start->y + ((line->y * dist) >> 12);
    point.z = start->z + ((line->z * dist) >> 12);
    
    if (collideBoundFunc(&point, hbox) != 0) {
        COLLIDE_InsertPoint(&point, normal, &dist, collide_point0, collide_normal0, &collide_t0, collide_point1, collide_normal1, &collide_t1);
    }
}

int COLLIDE_IntersectLineAndBox(SVector* point0, SVector* normal0, SVector* point1, SVector* normal1, SVector* end, SVector* start, HBox* hbox) {
    SVector normal;
    LVECTOR line;

    collide_t0 = 0x1001;
    collide_t1 = 0x1001;
    
    collide_point0 = point0;
    collide_point1 = point1;
    
    collide_normal0 = normal0;
    collide_normal1 = normal1;
    
    line.x = end->x - start->x;
    line.y = end->y - start->y;
    line.z = end->z - start->z;
    
    normal.x = -0x1000;
    normal.y = 0;
    normal.z = 0;
    
    COLLIDE_LineWithBoxFace(-start->x, -line.x, -hbox->minX, start, &line, hbox, COLLIDE_WithinYZBounds, &normal);
    
    normal.x = 0x1000;
    normal.y = 0;
    normal.z = 0;
    
    COLLIDE_LineWithBoxFace(start->x, line.x, hbox->maxX, start, &line, hbox, COLLIDE_WithinYZBounds, &normal);
    
    normal.x = 0;
    normal.y = -0x1000;
    normal.z = 0;
    
    COLLIDE_LineWithBoxFace(-start->y, (short)-line.y, -hbox->minY, start, &line, hbox, COLLIDE_WithinXZBounds, &normal);
    
    normal.x = 0;
    normal.y = 0x1000;
    normal.z = 0;
    
    COLLIDE_LineWithBoxFace(start->y, line.y, hbox->maxY, start, &line, hbox, COLLIDE_WithinXZBounds, &normal);
    
    normal.x = 0;
    normal.y = 0;
    normal.z = -0x1000;
    
    COLLIDE_LineWithBoxFace(-start->z, (short)-line.z, -hbox->minZ, start, &line, hbox, COLLIDE_WithinXYBounds, &normal);
    
    normal.x = 0;
    normal.y = 0;
    normal.z = 0x1000;
    
    COLLIDE_LineWithBoxFace(start->z, line.z, hbox->maxZ, start, &line, hbox, COLLIDE_WithinXYBounds, &normal);
    
    if (collide_t1 != 0x1001)
    {
        return 2;
    }

    if (collide_t0 != 0x1001)
    {
        return 1;
    }
    
    return 0;
}

HBox* _COLLIDE_IntersectLineAndBoxList(SVector* end, SVector* start, HInfo* hinfo, SVector* normal) {
    SVector point0;
    SVector point1;
    SVector normal0;
    SVector normal1;
    HBox* hboxEnd;
    HBox* hboxItr;
    HBox* lastHitBox;

    hboxItr = hinfo->hboxList;
    hboxEnd = hinfo->hboxList + hinfo->numHBoxes;
    lastHitBox = 0;
    for (; hboxItr < hboxEnd; hboxItr++) {
        if ((hboxItr->flags & 0x2000))
        {
            if ((COLLIDE_IntersectLineAndBox(&point0, &normal0, &point1, &normal1, end, start, hboxItr))) {
                end->x = point0.x;
                end->y = point0.y;
                end->z = point0.z;
                normal->x = normal0.x;
                normal->y = normal0.y;
                normal->z = normal0.z;
                lastHitBox = hboxItr;
            }
        }
    }
    return lastHitBox;
}

int COLLIDE_ClosestPointInBoxToPoint(SVector* outPoint, HBox* box, SVector* point) {

    int inside = 1;
    
    if (point->x < box->minX) {
        outPoint->x =  box->minX;
        inside = 0;
    } else if ((((box->maxX < point->x) != 0))) {
        outPoint->x = box->maxX;
        inside = 0;
    } else {
        outPoint->x = point->x;
    }
    
    if (point->y < box->minY) {
        outPoint->y = box->minY;
        inside = 0;
    } else if ((((box->maxY < point->y) != 0))) {
        outPoint->y = box->maxY;
        inside = 0;
    } else {
        outPoint->y = point->y;
    }
    
    if (point->z < box->minZ) {
        outPoint->z = box->minZ;
        inside = 0;
    } else if ((((box->maxZ < point->z) != 0))) {
        outPoint->z = box->maxZ;
        inside = 0;
    } else {
        outPoint->z = point->z;
    }
    
    return inside;
}

void func_80012A1C(SVector* pNormal, SVector* point0, SVector* point1, SVector* point2) {
    LVECTOR delta;
    int dLength;
    int normal;
    int a, b;
    

    delta.x = point1->x - point0->x;
    delta.y = point1->y - point0->y;
    delta.z = point1->z - point0->z;

    dLength = ((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z)) >> 0xC;
    normal = ((((delta.x * point0->x) + (delta.y * point0->y) + (delta.z * point0->z)) >> 0xC) - (((delta.x * point2->x) + (delta.y * point2->y) + (delta.z * point2->z)) >> 0xC)) << 0xC;
    
    if (dLength != 0) {
        normal = -normal / dLength;
    }
    
    if (normal < 0) {
        normal = 0;
    } else if (normal > 0x1000) {
        normal = 0x1000;
    }
    
    pNormal->x = (point0->x + ((delta.x * normal) >> 0xC));
    pNormal->y = (point0->y + ((delta.y * normal) >> 0xC));
    pNormal->z = (point0->z + ((delta.z * normal) >> 0xC));
}

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012BD0);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012C74);

INCLUDE_ASM("asm/nonmatchings/12D70", func_80012D20);

void common_remred_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
    if (temp_v0 == NULL || (arg0->currentModel == 1)) return;

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

void common_remred_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void common_tvscrho_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void common_tvscrho_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    instance->_D0[0]++;
}

void common_tvscrho_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void common_kgateop_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
    }
}

void common_kgateop_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    Instance* inst;

    intro = instance->introData;
    inst = ((Intro**)intro)[1]->instance;
    if (((gameTracker->red_remote_bits[gameTracker->levelIdToLoad] >> intro[0]) & 1) && (intro[1] == 0)) {
        inst->flags &= ~0x100000;
        inst->flags |= 0x02000000;
        func_8002E350(instance);
    }
}

void common_kgateop_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void common_tailpuf_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0xC00;
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_tailpuf_OnUpdate);
/*
extern int D_800EB8A0;

void common_tailpuf_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR sp10;
    SVECTOR sp18;
    Instance* temp_a3;
    int temp_v1;
    s8* temp_s1;
    int* temp_s0;
    Instance* temp_v0;
    int* temp_v1_2;

    temp_a3 = gameTracker->_000C;
    if (((temp_a3->_F4[1] == 0x10) || (temp_a3->_F4[1] == 0x2000)) && (instance->_100 != 0)) {
        instance->position = temp_a3->position;
        temp_v1_2 = ((int*)temp_a3->_2C) + ((instance->_F4[2] << 3) + 0x480/4);
        sp10.x = temp_v1_2[0x14/4];
        sp10.y = temp_v1_2[0x18/4];
        sp10.z = temp_v1_2[0x1C/4];
        temp_v0 = func_800176E8(&sp10, instance->_100, D_800EB8A0, -1);
        if (temp_v0 != NULL) {
            sp18.x = 0x2000;
            sp18.y = 0x2000;
            sp18.z = 0x2000;
            func_80017AE0(temp_v0, &sp18);
            if ((*(int*)&instance->_108 == 0) && (instance->_104 == 0)) {
                func_80018AB4(temp_v0, &instance->_10C, 0xF, 0xA);
                if (temp_v0->node.next != NULL) {
                    func_80018AB4(temp_v0->node.next, (int*)&instance->_10C, 0xF, 0xA);
                }
            }
        }
    } else {
        func_8002E350(instance);
    }
}*/

void common_magic_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->scale.z = instance->scale.y = instance->scale.x = 1;
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_magic_OnUpdate);

void common_magic_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    if (((int**)instance->_70[2])[0x14/4] == (void*)gameTracker->_000C)
    {
        instance->_F4[0] = 1;
    }
}

void common_proxsig_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x800;
}

int SVECTOR_Length(SVECTOR* pos) {
    return MATH3D_FastSqrt2(pos->x * pos->x + pos->y * pos->y + pos->z * pos->z, 0);
}

typedef struct
{
    short distMin;
    short distMax;
    void* signal;
} Proxy;

typedef struct
{
    int numSignals;
    Proxy proxies[0];
} ProxSigIntro;

void common_proxsig_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR dpos;
    Proxy* proxy;
    int distance;
    ProxSigIntro* intro;
    Proxy* pEnd;

    intro = (ProxSigIntro*)instance->introData;
    if ((instance->intro->_2C != NULL) && (intro != NULL)) {
        SVECTOR_Subtract(&instance->position, &PlayerInstance->position, &dpos);
        distance = SVECTOR_Length(&dpos);
        
        pEnd = &intro->proxies[intro->numSignals];
        
        for (proxy = intro->proxies; proxy < pEnd; ++proxy) {
            if (proxy->distMin <= distance && distance < proxy->distMax) {
                SIGNAL_HandleSignal(PlayerInstance, proxy->signal + 4, 0);
            }
        }
    }
}

void common_proxsig_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/12D70", common_animseq_OnCreate);

INCLUDE_ASM("asm/nonmatchings/12D70", common_animseq_OnUpdate);

void common_animseq_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

typedef struct
{
    int _00;
    short _04;
    short _06;
    char _08[8];
    short _10;
    short _12;
    int _14;
    int _18;
    int _1C;
} GengenIntro;

void common_gengen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short temp_v1;
    GengenIntro* intro;

    intro = instance->introData;
    instance->_F4[0] = 0;
    instance->_100 = 0;
    instance->flags |= 0x100800;
    if (intro != NULL) {
        if ((*(int*)&intro->_04 == 0) || (intro->_10 & 4)) {
            instance->_F4[2] = intro->_00;
        } else {
            instance->_F4[0] = 1;
        }
        temp_v1 = intro->_10;
        if ((temp_v1 & 1) && (temp_v1 & 2)) {
            instance->_100 = func_80015F14(D_800EB8A0);
        }
    }
}

void common_gengen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Instance* inst;
    Object* obj;
    int temp_a1;
    int temp_v0;
    int temp_v0_2;
    GengenIntro* intro;

    intro = instance->introData;
    obj = (Object*)OBTABLE_FindObject(intro->_08);
    
    if (instance->intro->_2C != NULL) {
        instance->intro->_2C = NULL;
        func_8002E350(instance);
        return;
    }
    
    if ((intro == NULL) || (obj == NULL)) {
        INSTANCE_KillInstance(instance);
        return;
    }
    
    if (instance->_F4[0] == 1) {
        temp_v0 = instance->_F4[2] + 1;
        instance->_F4[2] = temp_v0;
        if (temp_v0 == *(int*)&intro->_04) {
            instance->_F4[2] = intro->_00;
            instance->_F4[0] = 0;
        }
    } else {
        temp_v0_2 = instance->_F4[2] + 1;
        instance->_F4[2] = temp_v0_2;
        if (temp_v0_2 >= intro->_00) {
            instance->_F4[2] = 0;
            if (((char*)intro)[0x12] != 0) {
                temp_a1 = intro->_14;
                if (temp_a1 != 0) {
                    SIGNAL_HandleSignal(instance, temp_a1 + 4, 0);
                }
            }
            if (intro->_10 & 1) {
                func_80017768(instance->intro->multiSpline, *obj->modelList, instance->_100, D_800EB8A0);
                return;
            }
            inst = (Instance*)INSTANCE_BirthObject(instance, obj);
            if (inst != NULL) {
                obj->oflags |= 0x2000;
                inst->introData = NULL;
                if (instance->object->oflags & 0x400) {
                    inst->processFunc = (void*)GenericProcess;
                    inst->collideFunc = (void*)GenericCollide;
                    if ((intro->_10 & 4) && (*(int*)&instance->_108 == 0)) {
                        *(int*)&instance->_108 = 1;
                        SCRIPT_InstanceSplineSet(inst, intro->_06, 0, 0, 0);
                    }
                }
            }
        }
    }
}

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
