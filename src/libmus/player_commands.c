#include "common.h"

#include <audio/player.h>

extern int max_channels;

typedef struct
{
    int _00[0x10]; // 00
    int handle; // 10
    int _14[0x1F]; // 14
    unsigned char _c1; // c1
    unsigned char _c2; // c2
    unsigned char _c3; // c3
    unsigned char reverb; // c4
    unsigned char old_reverb; // c5
    unsigned char _c6;
    unsigned char _c7;
    int _C8[0x16]; // c8
} c_t;

extern c_t *mus_channels;

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fstop);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fwave);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fport);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fportoff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fdefa);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Ftempo);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fendit);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fcutoff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fvibup);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fvibdown);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fviboff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Flength);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fignore);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Ftrans);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fignore_trans);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fdistort);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fenvelope);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fenvoff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fenvon);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Ftroff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Ftron);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Ffor);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fnext);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fwobble);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fwobbleoff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fvelon);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fveloff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fvelocity);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fpan);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fstereo);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fdrums);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fdrumsoff);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fprint);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fgoto);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Freverb);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", FrandNote);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", FrandVolume);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", FrandPan);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fvolume);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fstartfx);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fbendrange);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", Fsweep);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusInitialize);

extern short mus_master_volume_effects;
extern short mus_master_volume_songs;
void MusSetMasterVolume(unsigned long flags, int volume)
{
  if (flags&MUSFLAG_EFFECTS)
    mus_master_volume_effects = volume;
  if (flags&MUSFLAG_SONGS)
    mus_master_volume_songs = volume;
}

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusStartSong);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusStartEffect);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusStartEffect2);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusStop);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusAsk);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleStop);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleAsk);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleSetVolume);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleSetPan);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleSetFreqOffset);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", MusHandleSetTempo);

int MusHandleSetReverb(unsigned long /*mushandle*/ handle, int reverb) {
    c_t* cp; // channel_t*
    int i, count;

    if (!handle) {
        return 0;
    }
    
    if (reverb < 0) {
        reverb = 0;
    } else if (reverb > 127) {
        reverb = 127;
    }
    
    for(i = 0, cp=mus_channels, count=0; i < max_channels; ++i, ++cp)
    {
        if (cp->handle == handle)
        {
            cp->reverb = reverb;
            cp->old_reverb = 0xff;
            ++count;
        }
    }

    return count;
}

void MusPtrBankInitialize(void* pbank, void* wbank) {
    __MusIntRemapPtrBank(pbank, wbank);
}

extern void* D_800AF0E0;
extern void* D_800AF0E4;

unsigned long func_800543D4(int* arg0, void* arg1) {
    unsigned long r;
    if ((arg0 != NULL) && (arg0[4] < 0)) {
        D_800AF0E0 = arg0;
    }
    r = MusStartSong(arg1);
    D_800AF0E0 = D_800AF0E4;
    return r;
}

unsigned long func_80054418(int* arg0, int arg1) {
    unsigned long r;
    if ((arg0 != NULL) && (arg0[4] < 0)) {
        D_800AF0E0 = arg0;
    }
    r = MusStartEffect(arg1);
    D_800AF0E0 = D_800AF0E4;
    return r;
}

unsigned long func_8005445C(int* arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    unsigned long r;
    if ((arg0 != NULL) && (arg0[4] < 0)) {
        D_800AF0E0 = arg0;
    }
    r = MusStartEffect2(arg1, arg2, arg3, arg4, arg5);
    D_800AF0E0 = D_800AF0E4;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_800544B4);
