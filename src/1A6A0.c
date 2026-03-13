#include "common.h"

#include "types/GameTracker.h"
#include "types/Remotes.h"

typedef struct
{
    int a, b;
} D_80161130_t;

extern D_80161130_t D_80161130[];
extern int D_80161168[];
extern int D_80161174[];

extern int D_800D1810;
extern int D_800E5FDC;
extern int D_800EB8A0;
extern int D_8014F35C;
extern int D_801539BC;
extern int D_80153A54;
void func_80019AA0(void) {
    int temp_v0;

    D_800E5FDC = func_80030BE0(0x10C);
    D_800D1810 = func_80030BE0(0x66B0);
    temp_v0 = func_80030BE0(0x11420);
    D_800EB8A0 = temp_v0;
    D_801539BC = temp_v0;
    D_80153A54 = func_80030BE0(0x2710);
    D_8014F35C = func_80030BE0(0x10);
    func_80030C50(0x10);
}

INCLUDE_ASM("asm/nonmatchings/1A6A0", func_80019B1C);

INCLUDE_ASM("asm/nonmatchings/1A6A0", func_80019F18);

int func_8001A1D8(unsigned char* remoteData) {
    int i;
    unsigned int remoteBits;
    int var_v1;

    remoteBits = 0;
    i = -1;
    
    while (*remoteData >= D_80161130[i + 1].a) {
        ++i;
    };
    
    if (i >= 0) {
        remoteBits |= D_80161130[i].b;
    }
    
    var_v1 = ((unsigned int*)gameTracker)[0x4C98/4] >> 0x15;
    
    i = 0;
    while (var_v1 != 0) {
        if (var_v1 & 1) {
            remoteBits |= D_80161168[i];
        }
        var_v1 >>= 1;
        i += 1;
    }
    
    var_v1 = ((int*)gameTracker)[0x4C94/4];
    i = 0;
    
     while (var_v1 != 0) {
        i += (var_v1 & 1);
        var_v1 >>= 1;
    }
    
    i /= 3;
    
    if (i >= 8) {
        i = 7;
    }
    
    while (i != 0) {
        remoteBits |= D_80161174[i--];
    }
    
    return remoteBits;
}

void GetRemoteCount(RemoteCount* remotes) {
    const int c_RedRemoteEntries = 14;
    int bits, i;

    for (remotes->gold = 0, bits = gameTracker->gold_remote_bits; bits != 0; bits >>= 1)
    {
        remotes->gold += bits & 1;
    }

    for (remotes->silver = 0, bits = gameTracker->silver_remote_bits; bits != 0; bits >>= 1)
    {
        remotes->silver += bits & 1;
    }

    for(remotes->red = 0, i = 0; i < c_RedRemoteEntries; ++i)
    {
        for (bits = gameTracker->red_remote_bits[i]; bits != 0; bits >>= 1)
        {
            remotes->red += bits & 1;
        }
    }
}
