#ifndef TOBJECTMETADATA_H_
#define TOBJECTMETADATA_H_

typedef struct
{
    const char name[8];
    char* start;
    char* end;
} ObjectMetadata;

typedef struct
{
    const char* name;
    char* data;
} ObjectPointer;

extern ObjectPointer D_800700C0[];
extern ObjectMetadata D_800739F0[];

#endif