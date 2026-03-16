#include "common.h"

#include "types/LevelMetadata.h"
#include "types/ObjectMetadata.h"
#include "types/G2String.h"
#include "zlib/zlib.h"

void* GetObjectDataFromName(const char* objectName) {
    ObjectPointer* object;
    
    for (object = D_800700C0; object->name != NULL; object++) {
        if (G2String_Compare_EQ(object->name, objectName)) {
            return object->data;
        }
    }
    
    return NULL;
}

extern int D_80070120;
extern int D_800EB7F4;

void* LoadObjectData(const char* objectName) {
    char zstream[32];
    int temp_s0;
    char* dataStart;
    int dataSize;
    int bytesInflated;
    ObjectMetadata* objectInfo;
    ObjectPointer* objectData;
   
    for (objectData = D_800700C0; objectData->name != NULL; objectData++)
    {
        if (G2String_Compare_EQ(objectData->name, objectName)) {
            
            if (objectData->data != NULL)
                return objectData->data;
            
            for (objectInfo = D_800739F0; objectInfo->name[0] != '\0'; objectInfo++) {
                if (G2String_Compare_EQ(objectInfo, objectName)) {
                    dataStart = objectInfo->start;
                    dataSize = objectInfo->end - dataStart;
                    if (D_80070120 & 0xF) {
                        D_80070120 = ((D_80070120 + 0xF) >> 4) << 4;
                    }
                    temp_s0 = D_80070120;
                    func_801DA910((z_stream*)zstream, temp_s0, 0x801DA800 - temp_s0); // init
                    bytesInflated = func_8003B270(temp_s0, inflate((z_stream*)zstream, dataStart, dataSize));
                    D_80070120 += bytesInflated;
                    osWritebackDCache(temp_s0, bytesInflated);
                    objectData->data = (void*)temp_s0;
                    return objectData->data;
                }
            }
        }
    }
   
    for (objectInfo = D_800739F0; objectInfo->name[0] != '\0'; objectInfo++) {
        if (G2String_Compare_EQ(objectInfo, objectName)) {
            dataStart = objectInfo->start;
            dataSize = objectInfo->end - dataStart;
            if (D_800EB7F4 & 0xF) {
                D_800EB7F4 = ((D_800EB7F4 + 0xF) >> 4) << 4;
            }
            temp_s0 = D_800EB7F4;
            func_801DA910((z_stream*)zstream, temp_s0, 0x80400000 - temp_s0); // init
            bytesInflated = func_8003B270(temp_s0, inflate((z_stream*)zstream, dataStart, dataSize));
            D_800EB7F4 += bytesInflated;
            osWritebackDCache(temp_s0, bytesInflated);
            return (void*)temp_s0;
        }
    }
    
    return NULL;
}

// Replaces object name array with array of pointers to object data
INCLUDE_ASM("asm/nonmatchings/3BAA0", LoadObjects);

INCLUDE_ASM("asm/nonmatchings/3BAA0", func_8003B270);

void* LoadLevelData(int levelIndex) {
    char zstream[32];
    int temp_s0;
    int blockSize;
    char* dataStart;
    int bytesInflated;

    dataStart = gLevelMetadata[levelIndex].uncompressedStart;
    blockSize = gLevelMetadata[levelIndex].uncompressedEnd - gLevelMetadata[levelIndex].uncompressedStart;

    if (blockSize == 0)
        return 0;
    
    if (D_800EB7F4 & 0x0F) {
        D_800EB7F4 = ((D_800EB7F4 + 0x0F) >> 4) << 4; // align to 16 bytes
    }
    
    temp_s0 = D_800EB7F4;
    func_801DA910((z_stream*)zstream, temp_s0, 0x80400000 - temp_s0); // inits zstream
    bytesInflated = inflate((z_stream*)zstream, dataStart, blockSize);
    osWritebackDCache(temp_s0, bytesInflated);
    D_800EB7F4 += bytesInflated;
    return (void*)temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/3BAA0", LoadGexObject);
/*void* func_8003B3D4() {
    char zstream[32];
    int size;
    int size2;
    int temp_v0;

    size = D_4B5750 - D_49D870;
    if (size == 0)
        return NULL;
    
    temp_v0 = func_80030BE0(0x3A980);
    func_801DA910(zstream, temp_v0, 0x3A980); // init
    size2 = inflate(zstream, D_49D870, size);
    size2 = func_8003B270(temp_v0, size2);
    osWritebackDCache(temp_v0, size2);
    func_80030C50(0x3A980 - size2);
    return (void*)temp_v0;
}*/

extern char gLevelCodeStart[]; // Used for accessing the start of the level code region
extern char* D_800E8184;

void LoadLevelCode(int levelIndex) {
    char* ptr;
    unsigned int blockSize;
    unsigned int segmentSize;
    int i;
    
    ptr = gLevelMetadata[levelIndex].levelStart;
    blockSize = gLevelMetadata[levelIndex].levelEnd - ptr;
    
    if (blockSize != 0)
    {
        osInvalICache(gLevelCodeStart, blockSize);
        DMATransferData(ptr, gLevelCodeStart, blockSize); // Transfer data
    }

    ptr = gLevelCodeStart + blockSize;
    D_800E8184 = gLevelMetadata[levelIndex].bss;
    segmentSize = D_800E8184 - ptr;
    for(i = 0; i < segmentSize; ++i)
    {
        *ptr++ = 0;
    }
}

extern char pZlibStart[];
extern char pZlibEnd[];

void LoadZlib(void) {
    int size;

    size = pZlibEnd - pZlibStart;
    if (size != 0) {
        DMATransferData(pZlibStart, inflate, size);
    }
}
