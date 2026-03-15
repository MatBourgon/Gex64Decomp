#include "common.h"
#include <audio/player.h>

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800522E0);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052308);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800526F0);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052758);

INCLUDE_RODATA("asm/nonmatchings/_52ee0", D_8007EB00);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052814);

void func_80052944(void) {
}

void func_8005294C(void) {
}

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052954);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800529A8);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052A7C);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052AA8);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052ADC);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052C2C);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052D18);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052F58);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80052F7C);

extern char D_80154830;
void func_80052FAC()
{
    D_80154830 = 0;
}

int func_80052FB8()
{
    return 1;
}

void func_80052FC0(void) {
}

void func_80052FC8(void) {
}

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fstop);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fwave);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fport);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fportoff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fdefa);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Ftempo);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fendit);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fcutoff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fvibup);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fvibdown);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fviboff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Flength);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fignore);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Ftrans);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fignore_trans);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fdistort);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fenvelope);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fenvoff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fenvon);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Ftroff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Ftron);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Ffor);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fnext);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fwobble);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fwobbleoff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fvelon);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fveloff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fvelocity);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fpan);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fstereo);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fdrums);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fdrumsoff);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fprint);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fgoto);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Freverb);

INCLUDE_ASM("asm/nonmatchings/_52ee0", FrandNote);

INCLUDE_ASM("asm/nonmatchings/_52ee0", FrandVolume);

INCLUDE_ASM("asm/nonmatchings/_52ee0", FrandPan);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fvolume);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fstartfx);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fbendrange);

INCLUDE_ASM("asm/nonmatchings/_52ee0", Fsweep);

INCLUDE_ASM("asm/nonmatchings/_52ee0", MusInitialize);

extern short mus_master_volume_effects;
extern short mus_master_volume_songs;
void MusSetMasterVolume(unsigned long flags, int volume)
{
  if (flags&MUSFLAG_EFFECTS)
    mus_master_volume_effects = volume;
  if (flags&MUSFLAG_SONGS)
    mus_master_volume_songs = volume;
}	

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80053C98);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80053DEC);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80053E98);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80053FA0);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80054020);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_8005409C);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_8005410C);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80054164);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800541C4);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80054234);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800542A4);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80054330);

INCLUDE_ASM("asm/nonmatchings/_52ee0", alSeqpDelete);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800543D4);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_80054418);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_8005445C);

INCLUDE_ASM("asm/nonmatchings/_52ee0", func_800544B4);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntMain);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntGetNewNote);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntFlushPending);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntSetVolumeAndPan);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntSetPitch);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntInitEnvelope);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessEnvelope);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntInitSweep);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessSweep);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessWobble);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessVibrato);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessContinuousVolume);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntProcessContinuousPitchBend);

INCLUDE_ASM("asm/nonmatchings/_52ee0", __MusIntPowerOf2);

INCLUDE_ASM("asm/nonmatchings/_52ee0", alSynRemovePlayer);

