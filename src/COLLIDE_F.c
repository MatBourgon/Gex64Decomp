#include "common.h"

#include "COLLIDE.h"

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_8000FA40);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_8000FD74);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_800101BC);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_80010350);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_80010ED8);

INCLUDE_ASM("asm/nonmatchings/COLLIDE_F", func_80011B20);

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

void _COLLIDE_MakeNormal(SVector* pNormal, SVector* point0, SVector* point1, SVector* point2) {
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

void COLLIDE_UpdateAllTransforms(Instance* instance, SVECTOR* arg1, GameTracker* gameTracker) {
    MATRIX* matrix;
    MATRIX* lastMatrix;
    int numMatrices;

    if (instance->matrix != 0) {
        matrix = instance->matrix;
        numMatrices = instance->object->modelList[instance->currentModel]->numSegments;
        lastMatrix = &instance->matrix[numMatrices];
        while (matrix < lastMatrix) {
            matrix->l[0] += arg1->x;
            matrix->l[1] += arg1->y;
            matrix->l[2] += arg1->z;
            matrix++;
        }
    }
}

void COLLIDE_UpdateAllOldTransforms(Instance* instance, SVECTOR* arg1, GameTracker* gameTracker) {
    MATRIX* matrix;
    MATRIX* lastMatrix;
    int numMatrices;

    if (instance->oldMatrix != 0) {
        matrix = instance->oldMatrix;
        numMatrices = instance->object->modelList[instance->currentModel]->numSegments;
        lastMatrix = &instance->oldMatrix[numMatrices]+1;
        while (matrix < lastMatrix) {
            matrix->l[0] += arg1->x;
            matrix->l[1] += arg1->y;
            matrix->l[2] += arg1->z;
            matrix++;
        }
    }
}
