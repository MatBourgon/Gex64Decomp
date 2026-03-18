#ifndef TLEVELMETADATA_H_
#define TLEVELMETADATA_H_

typedef struct
{
    char* uncompressedStart;
    char* uncompressedEnd;
    char* levelStart;
    char* levelEnd;
    char* bss;
    char level_id[8];
    int _;
} LevelMetadata;

extern LevelMetadata gLevelMetadata[31];

#endif