#ifndef THBOX_H_
#define THBOX_H_

typedef struct
{
    short flags;
    char id;
    char rank;
    short minX, minY, minZ;
    short maxX, maxY, maxZ;
    short refMinX, refMinY, refMinZ;
    short refMaxX, refMaxY, refMaxZ;
} HBox;

#endif