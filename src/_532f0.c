#include "common.h"
#include <audio/player.h>

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800526F0);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052758);

INCLUDE_RODATA("asm/nonmatchings/_532f0", D_8007EB00);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052814);

void func_80052944(void) {
}

void func_8005294C(void) {
}

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052954);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800529A8);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052A7C);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052AA8);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052ADC);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052C2C);
/*void func_80052C2C(s32 arg0) {
    short var_a0;
    int temp_a0;

    if (D_80154834 != 0) return;
        temp_a0 = arg0 - 0x45;
        
    switch (arg0) {
        case 0x49:
            var_a0 = 0x1D9;
            break;
        case 0x47:
            var_a0 = 0x1DB;
            break;
        case 0x4D:
            rand(temp_a0);
            var_a0 = 0x1DA;
            break;
        case 0x45:
            var_a0 = 0x1DA;
            break;
        case 0x4B:
            var_a0 = 0x1DC;
            break;
        case 0x4A:
            var_a0 = 0x1DD;
            break;
        case 0x46:
            var_a0 = 0x1DE;
            break;
        case 0x48:
            var_a0 = (D_80079460[((short)(rand(temp_a0) % 3))]);
            break;
        default:
            return;
    }
    D_80154834 = 3;
    D_80154833 = 0;
    D_800E5CE0 = func_80050B64(var_a0);
}*/

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052D18);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052F58);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80052F7C);

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

INCLUDE_ASM("asm/nonmatchings/_532f0", Fstop);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fwave);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fport);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fportoff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fdefa);

INCLUDE_ASM("asm/nonmatchings/_532f0", Ftempo);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fendit);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fcutoff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fvibup);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fvibdown);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fviboff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Flength);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fignore);

INCLUDE_ASM("asm/nonmatchings/_532f0", Ftrans);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fignore_trans);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fdistort);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fenvelope);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fenvoff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fenvon);

INCLUDE_ASM("asm/nonmatchings/_532f0", Ftroff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Ftron);

INCLUDE_ASM("asm/nonmatchings/_532f0", Ffor);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fnext);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fwobble);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fwobbleoff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fvelon);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fveloff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fvelocity);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fpan);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fstereo);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fdrums);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fdrumsoff);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fprint);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fgoto);

INCLUDE_ASM("asm/nonmatchings/_532f0", Freverb);

INCLUDE_ASM("asm/nonmatchings/_532f0", FrandNote);

INCLUDE_ASM("asm/nonmatchings/_532f0", FrandVolume);

INCLUDE_ASM("asm/nonmatchings/_532f0", FrandPan);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fvolume);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fstartfx);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fbendrange);

INCLUDE_ASM("asm/nonmatchings/_532f0", Fsweep);

INCLUDE_ASM("asm/nonmatchings/_532f0", MusInitialize);

extern short mus_master_volume_effects;
extern short mus_master_volume_songs;
void MusSetMasterVolume(unsigned long flags, int volume)
{
  if (flags&MUSFLAG_EFFECTS)
    mus_master_volume_effects = volume;
  if (flags&MUSFLAG_SONGS)
    mus_master_volume_songs = volume;
}	

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80053C98);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80053DEC);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80053E98);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80053FA0);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80054020);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_8005409C);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_8005410C);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80054164);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800541C4);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80054234);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800542A4);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80054330);

INCLUDE_ASM("asm/nonmatchings/_532f0", alSeqpDelete);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800543D4);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_80054418);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_8005445C);

INCLUDE_ASM("asm/nonmatchings/_532f0", func_800544B4);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntMain);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntGetNewNote);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntFlushPending);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntSetVolumeAndPan);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntSetPitch);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntInitEnvelope);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessEnvelope);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntInitSweep);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessSweep);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessWobble);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessVibrato);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessContinuousVolume);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntProcessContinuousPitchBend);

INCLUDE_ASM("asm/nonmatchings/_532f0", __MusIntPowerOf2);

INCLUDE_ASM("asm/nonmatchings/_532f0", alSynRemovePlayer);

