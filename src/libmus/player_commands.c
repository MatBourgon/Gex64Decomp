#include "common.h"

#include <audio/player.h>

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

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80053C98);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80053DEC);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80053E98);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80053FA0);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80054020);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_8005409C);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_8005410C);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80054164);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_800541C4);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80054234);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_800542A4);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80054330);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", alSeqpDelete);

extern void* D_800AF0E0;
extern void* D_800AF0E4;

void* func_800543D4(int* arg0, void* arg1) {
    void* r;
    if ((arg0 != NULL) && (arg0[4] < 0)) {
        D_800AF0E0 = arg0;
    }
    r = (void*)func_80053C98(arg1);
    D_800AF0E0 = D_800AF0E4;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_80054418);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_8005445C);

INCLUDE_ASM("asm/nonmatchings/libmus/player_commands", func_800544B4);
