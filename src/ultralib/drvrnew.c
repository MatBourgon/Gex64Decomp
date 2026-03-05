#include "common.h"

#include "PR/abi.h"
#include "PR/libaudio.h"
#include "audio/synthInternals.h"

/*
 * WARNING: THE FOLLOWING CONSTANT MUST BE KEPT IN SYNC
 * WITH SCALING IN MICROCODE!!!
 */
#define	SCALE 16384

/*
 * the following arrays contain default parameters for
 * a few hopefully useful effects.
 */
#define ms *(((s32)((f32)44.1))&~0x7)

INCLUDE_RODATA("asm/nonmatchings/ultralib/drvrnew", D_8007EE10);

void init_lpfilter(ALLowPass *lp)
{
    int		i, temp;
    short		fc;
    double		ffc, fcoef;

    temp = lp->fc * SCALE;
    fc = temp >> 15;
    lp->fgain = SCALE - fc;

    lp->first = 1;
    for (i=0; i<8; i++)
	lp->fcvec.fccoef[i] = 0;
    
    lp->fcvec.fccoef[i++] = fc;
    fcoef = ffc = (double)fc/SCALE;

    for (; i<16; i++){
	fcoef *= ffc;
	lp->fcvec.fccoef[i] = (short)(fcoef * SCALE);
    }
}

INCLUDE_ASM("asm/nonmatchings/ultralib/drvrnew", alFxNew);

void alEnvmixerNew(ALEnvMixer *e, ALHeap *hp)
{
    alFilterNew((ALFilter *) e, alEnvmixerPull, alEnvmixerParam, AL_ENVMIX);

    e->state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
    
    e->first = 1;
    e->motion = AL_STOPPED;
    e->volume = 1;
    e->ltgt = 1;
    e->rtgt = 1;
    e->cvolL = 1;
    e->cvolR = 1;
    e->dryamt = 0;
    e->wetamt = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->delta = 0;
    e->segEnd = 0;
    e->pan = 0;
    e->ctrlList = 0;
    e->ctrlTail = 0;
    e->sources = 0;
}

void alLoadNew(ALLoadFilter *f, ALDMANew dmaNew, ALHeap *hp) 
{
    s32
        i;
    
    /*
     * init filter superclass
     */

    alFilterNew((ALFilter *) f, alAdpcmPull, alLoadParam, AL_ADPCM);

    f->state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    
    f->dma = dmaNew(&f->dmaState);
    
    /*
     * init the adpcm state
     */
    f->lastsam = 0;
    f->first = 1;
    f->memin = 0;
}

void alResampleNew(ALResampler *r, ALHeap *hp)
{
    alFilterNew((ALFilter *) r, alResamplePull, alResampleParam, AL_RESAMPLE);

    /*
     * Init resampler state
     */
    r->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
    r->delta  = 0.0;
    r->first  = 1;
    r->motion = AL_STOPPED;
    r->ratio = 1.0;
    r->upitch = 0;
    r->ctrlList = 0;
    r->ctrlTail = 0;
    
    /* state in the ucode is initialized by the A_INIT flag */
}

void alAuxBusNew(ALAuxBus *m, void *sources, s32 maxSources)
{
    alFilterNew((ALFilter *) m, alAuxBusPull, alAuxBusParam, AL_AUXBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter **)sources;
}

void alMainBusNew(ALMainBus *m, void *sources, s32 maxSources)
{
    alFilterNew((ALFilter *) m, alMainBusPull, alMainBusParam, AL_MAINBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter **)sources;
}

void alSaveNew(ALSave *f) 
{
    /*
     * init filter superclass
     */

    alFilterNew((ALFilter *) f, alSavePull, alSaveParam, AL_SAVE);
    
    /*
     * init the save state, which is a virtual dram address
     */
    
    f->dramout = 0;
    f->first = 1;
    
}