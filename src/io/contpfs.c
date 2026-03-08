#include "common.h"

#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/os_version.h"
#include "PRinternal/controller.h"
#include "PR/rmon.h"

u16 __osSumcalc(u8* ptr, int length) {
    int i;
    u32 sum = 0;
    u8* tmp = ptr;

    for (i = 0; i < length; i++) {
        sum += *tmp++;
#if BUILD_VERSION < VERSION_J
        sum = sum & 0xFFFF;
#endif
    }

#if BUILD_VERSION >= VERSION_J
    return sum & 0xFFFF;
#else
    return sum;
#endif
}

s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum) {
    u16 data = 0;
    u32 j;

    *csum = *icsum = 0;

    for (j = 0; j < ((sizeof(__OSPackId) - sizeof(u32)) / sizeof(u8)); j += 2) {
        data = *(u16*)((u32)ptr + j);
        *csum += data;
        *icsum += ~data;
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/io/contpfs", __osRepairPackId);

INCLUDE_ASM("asm/nonmatchings/io/contpfs", __osCheckPackId);

INCLUDE_ASM("asm/nonmatchings/io/contpfs", __osGetId);

s32 __osCheckId(OSPfs* pfs) {
#if BUILD_VERSION < VERSION_J
    int k;
#endif
    u8 temp[BLOCKSIZE];
    s32 ret;

#if BUILD_VERSION >= VERSION_J
    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);

        if (ret == PFS_ERR_NEW_PACK) {
            ret = __osPfsSelectBank(pfs, 0);
        }

        if (ret != 0) {
            return ret;
        }
    }
#else
    SET_ACTIVEBANK_TO_ZERO();
#endif

    ret = __osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp);

    if (ret != 0) {
        if (ret != PFS_ERR_NEW_PACK) {
            return ret;
        }
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp));
    }

#if BUILD_VERSION >= VERSION_J
    if (bcmp(pfs->id, temp, BLOCKSIZE) != 0) {
        return PFS_ERR_NEW_PACK;
    }
#else
    for (k = 0; k < ARRLEN(temp); k++) {
        if (pfs->id[k] != temp[k])
            return PFS_ERR_NEW_PACK;
    }
#endif

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/io/contpfs", __osPfsRWInode);

// This was moved into it's own file in 2.0J
#if BUILD_VERSION < VERSION_J
s32 __osPfsSelectBank(OSPfs* pfs) {
    u8 temp[BLOCKSIZE];
    int i;
    s32 ret = 0;

    for (i = 0; i < BLOCKSIZE; i++) {
        temp[i] = pfs->activebank;
    }

    ret = __osContRamWrite(pfs->queue, pfs->channel, CONT_BLOCK_DETECT, temp, FALSE);
    return ret;
}
#endif
