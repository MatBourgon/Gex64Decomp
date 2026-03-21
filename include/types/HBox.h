#ifndef THBOX_H_
#define THBOX_H_

typedef struct
{
    short flags;
    char id;
    char rank;
    short minX, minY, minZ;
    short maxX, maxY, maxZ;
    // maybe refMin/Max also
} HBox;

#endif