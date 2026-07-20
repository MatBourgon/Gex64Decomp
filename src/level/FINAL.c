#include "common.h"

#include "level/FINAL.h"
#include "types/G2String.h"

extern int D_80161510_926B0;

void final_oldpoptv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work1 = 1;
    instance->work0 = 0;
    instance->flags |= 0x400;
    if (instance->introData == NULL) {
        instance->introData = (void*)&D_80161510_926B0;
    }
}


INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161510_926B0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161518_926B8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161520_926C0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161538_926D8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016153C_926DC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161540_926E0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161544_926E4);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161548_926E8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016154C_926EC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161558_926F8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_oldpoptv_OnUpdate);

void final_oldpoptv_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_lectro_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x80;
    instance->currentTextureAnimFrame = 0;
    instance->flags |= 0x10000;
    if (instance->flags & 0x20000) {
        if (instance->work0 != 0) {
            func_800331BC(instance->work0);
            instance->work0 = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_lectro_OnUpdate);

void final_lectro_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_probe_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}

void final_probe_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->_2C != 0) {
        instance->currentMainState = 1;
    }
    if (instance->currentMainState == 1) {
        instance->position.z += 0x20;
        if (instance->position.z > 0x2000) {
            func_8002E350(instance);
        }
    }
}

void final_probe_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_reztvex_OnCreate(Instance* arg0, GameTracker* gameTracker) {
    arg0->rotation.z = 0;
    arg0->rotation.y = 0;
    arg0->rotation.x = 0;
    arg0->scale.z = 0x100;
    arg0->scale.y = 0x100;
    arg0->scale.x = 0x100;
    arg0->currentTextureAnimFrame = 0;
    arg0->flags |= 0x80;
}

void final_reztvex_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame += 1;
    instance->scale.x += 0xEC;
    instance->scale.y += 0xEC;
    instance->scale.z += 0x9D;
    if (instance->scale.x >= 0x1000) {
        func_8002E350(instance);
    }
}

void final_reztvex_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_rezxpl_OnCreate(Instance* arg0, GameTracker* gameTracker) {
    arg0->rotation.z = 0;
    arg0->rotation.y = 0;
    arg0->rotation.x = 0;
    arg0->scale.z = 0x100;
    arg0->scale.y = 0x100;
    arg0->scale.x = 0x100;
    arg0->currentTextureAnimFrame = 0;
    arg0->flags |= 0x80;
}

void func_80159CBC_8AE5C(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezxpl_OnUpdate);

void final_rezxpl_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161588_92728); // rezfx___

extern char D_80161588_92728[];

void final_rezbomb_OnCreate(Instance* instance, GameTracker* gameTracker) {
    *(short*)&instance->_E0[0] = 0;
    instance->currentMainState = OBTABLE_FindObject(D_80161588_92728);
    instance->currentSubState = OBTABLE_FindObject("rezxpl__");
}

typedef struct {
    char _00[8];
    int* next;
    unsigned short flags;
    short _0E;
    void* callback;
    void* _14;
    int _18;
    short posX;
    short posY;
    short posZ;
    short _22;
    unsigned short unk24;
    short _26;
    unsigned short unk28;
    short _2A;
    unsigned short unk2C;
    short _2E;
    unsigned short unk30;
    short _32;
    unsigned short unk34;
    short _36;
    unsigned short unk38;
    short _3A;
    unsigned short unk3C;
    short _3E;
    unsigned short unk40;
    short _42;
    short _44;
    unsigned short _46;
    unsigned short _48;
    short _4A;
    unsigned short _4C;
    unsigned short _4E;
    unsigned short _50;
    unsigned short _52;
    unsigned short _54;
    unsigned short _56;
    int _58[5];
    unsigned short frame;
} ParticleData;

void func_80159E50_8AFF0(ParticleData* p, void* callback, char* data, int arg3, unsigned short* def, char* table, int arg6, int arg7, int arg8, int arg9, unsigned short arg10) {
    SVECTOR c;
    short* va;
    short* vb;
    short* vc;
    int* nxt;
    unsigned short t;

    va = (short*)(table + def[0] * 12);
    vb = (short*)(table + def[1] * 12);
    vc = (short*)(table + def[2] * 12);
    c.x = (va[0] + vb[0] + vc[0]) / 3;
    c.y = (va[1] + vb[1] + vc[1]) / 3;
    c.z = (va[2] + vb[2] + vc[2]) / 3;
    p->posX = c.x + ((int*)data)[0x20 / 4];
    p->posY = c.y + ((int*)data)[0x24 / 4];
    p->posZ = c.z + ((int*)data)[0x28 / 4];
    p->unk24 = va[0] - c.x;
    p->_26 = va[1] - c.y;
    p->unk28 = va[2] - c.z;
    p->unk2C = vb[0] - c.x;
    p->_2E = vb[1] - c.y;
    p->unk30 = vb[2] - c.z;
    p->unk34 = vc[0] - c.x;
    p->_36 = vc[1] - c.y;
    p->unk38 = vc[2] - c.z;
    if (((unsigned char*)def)[7] & 2) {
        p->flags |= 1;
        nxt = ((int**)def)[2];
        p->next = nxt;
        p->_18 = (nxt[3] & 0x3FFFFFF) | 0x24000000;
    } else {
        p->flags &= ~1;
        p->_18 = (((int*)def)[2] & 0x3FFFFFF) | 0x20000000;
    }
    p->callback = callback;
    p->_14 = data;
    p->_4C = -c.x >> 1;
    p->_4E = -c.y >> 1;
    t = c.z;
    p->_52 = 0;
    p->_54 = 0;
    p->_56 = 0;
    p->_0E = arg10;
    p->_50 = -((t << 16) >> 17);
}

void func_8015A0DC_8B27C(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
    if (((short*)arg0)[0xE/2] == 0x1D) {
        ((unsigned short*)arg0)[0x4C/2] = -((unsigned short*)arg0)[0x4C/2];
        ((unsigned short*)arg0)[0x4E/2] = -((unsigned short*)arg0)[0x4E/2];
        ((unsigned short*)arg0)[0x50/2] = -((unsigned short*)arg0)[0x50/2];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A170_8B310);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A3DC_8B57C);

extern int D_800EB8A0;
extern void func_80017E88();
extern int func_8015A3DC_8B57C();

void func_8015A434_8B5D4(Instance* instance, Object* obj, int pos, int rot) {
    SVECTOR vel;
    short* spray;
    Model* model;

    if (obj != 0) {
        model = obj->modelList[2];
        vel.z = -4;
        vel.y = 0;
        vel.x = 0;
        spray = (short*)func_800170E8(model, model->_14, pos, rot, &vel, D_800EB8A0, func_80017E88, func_8015A3DC_8B57C, 0x3C);
        if (spray != 0) {
            spray[0x44 / 2] = instance->position.z;
        }
    }
}

extern void func_80016894();

void func_8015A4C8_8B668(int arg0, Object* obj, int arg2) {
    Model* model;
    ParticleData* spray;

    if (obj != 0) {
        model = obj->modelList[1];
        spray = ((ParticleData*)func_800170E8(model, model->_14, arg2, 0, 0, D_800EB8A0, func_80017E88, func_80016894, -1));
        if (model->_20 != 0 && spray != 0) {
            spray->flags |= 4;
            memcpy(spray->_58, spray->next, 0x10);
            spray->_58[4] = model->_20 + 4;
            spray->frame = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A590_8B730);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A78C_8B92C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezbomb_OnUpdate);

void final_rezbomb_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A9F0_8BB90);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AC70_8BE10);

void func_8015ADC4_8BF64(Instance* instance) {
    Camera* cam;
    unsigned short* c;
    SVECTOR mid;
    SVECTOR rot;
    int px;
    int py;

    cam = gameTracker8->camera;
    c = (unsigned short*)cam;
    mid.x = (instance->position.x + 0x2D00) / 2;
    mid.y = (instance->position.y + 0x267A) / 2;
    mid.z = instance->position.z + 0x200;
    py = instance->position.y;
    rot.x = (py - 0x267A) << 2;
    px = instance->position.x;
    rot.y = (-px + 0x2D00) << 2;
    rot.z = 0;
    func_80005438(&cam->cameraCore._08[4], &mid, cam);
    c[0x18] = c[0xC];
    c[0x19] = c[0xD];
    c[0x1A] = c[0xE];
    c[4] = c[0xC];
    c[5] = c[0xD];
    c[0x17] = c[6] = c[0xE];
}

extern int D_800785C8;

void func_8015AE98_8C038(void) {
    PlayerInstance->currentMainState = D_800785C8;
    func_80003234(gameTracker8->camera);
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AED8_8C078);

extern void func_8004ACB0(short* angle, short target, int step);

int func_8015B07C_8C21C(Instance* instance, int arg1, short arg2) {
    SVECTOR d;
    int angle;

    d.x = PlayerInstance->position.x - instance->position.x;
    d.y = PlayerInstance->position.y - instance->position.y;
    d.z = PlayerInstance->position.z - instance->position.z;
    angle = (short)ratan2(d.y, d.x) + 0x400;
    func_8004ACB0(&instance->rotation.z, angle, arg2);
    return instance->rotation.z == angle;
}

int func_8015B130_8C2D0(Instance* instance, int arg1, short arg2) {
    SVECTOR d;
    int angle;

    d.x = 0x2D00 - instance->position.x;
    d.y = 0x267A - instance->position.y;
    d.z = -instance->position.z;
    angle = (short)ratan2(d.y, d.x) + 0x400;
    func_8004ACB0(&instance->rotation.z, angle, arg2);
    return instance->rotation.z == angle;
}

/* swing the camera focus toward the player at 0x40 per tick */
void func_8015B1D8_8C378(Instance* instance, GameTracker* gameTracker) {
    SVECTOR d;

    d.x = PlayerInstance->position.x - instance->position.x;
    d.y = PlayerInstance->position.y - instance->position.y;
    d.z = PlayerInstance->position.z - instance->position.z;
    func_8004ACB0(&gameTracker->camera->focusRotationX, ((ratan2(d.y, d.x) << 16) + 0x4000000) >> 16, 0x40);
}

void func_8015B268_8C408(Instance* instance, GameTracker* gameTracker) {
    SVECTOR d;
    SVECTOR a;
    Camera* camera = gameTracker->camera;

    a.x = instance->position.x;
    a.y = instance->position.y;
    a.z = instance->position.z + 0x200;
    func_80005438(&camera->_data7[4], &a, camera);
    d.x = a.x - camera->cameraCore.position.x;
    d.y = a.y - camera->cameraCore.position.y;
    d.z = a.z - camera->cameraCore.position.z;
    camera->cameraCore._08[0x13] = CAMERA_LengthSVector(&d) >> 3;
    *(short*)&camera->_data7[7] = 0;
    *(short*)&camera->_data7[9] = 0;
    camera->_data8[3] = 0;
    camera->_data8[2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B30C_8C4AC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B658_8C7F8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BB78_8CD18);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BD84_8CF24);

typedef struct {
    char _00[0x3C];
    SVECTOR position;  // 0x3C
    char _42[0x12];
    Model* model;      // 0x54
} RezSprayerData;

void func_8015BFB8_8D158(Instance* instance) {
    RezSprayerData* d = ((RezSprayerData*)instance->work0);
    ParticleData* spray;

    if (d->model != 0) {
        d->position.z += 10;
        spray = ((ParticleData*)func_800170E8(d->model, d->model->_14, &d->position, 0, 0, D_800EB8A0, func_80017E88, 0, -1));
        if (d->model->_20 != 0 && spray != 0) {
            spray->flags |= 4;
            memcpy(spray->_58, spray->next, 0x10);
            spray->_58[4] = d->model->_20 + 4;
            spray->frame = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C0A0_8D240);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C220_8D3C0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C39C_8D53C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C850_8D9F0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015C9D0_8DB70);

/* format val as 8 uppercase hex digits into buf */
void func_8015CAF8_8DC98(char* buf, int val) {
    int i;
    char* p;
    unsigned int d;

    i = 7;
    p = buf + 7;
    for (; i >= 0; i--) {
        d = val & 0xF;
        val >>= 4;
        if (d < 10) {
            *p = d + '0';
        } else {
            *p = d + 'A' - 10;
        }
        p--;
    }
    buf[8] = 0;
}

/* format val as 4 uppercase hex digits into buf */
void func_8015CB34_8DCD4(char* buf, short val) {
    int i;
    char* p;
    unsigned int d;

    i = 3;
    p = buf + 3;
    for (; i >= 0; i--) {
        d = val & 0xF;
        val >>= 4;
        *p = d < 10 ? d + '0' : d + 'A' - 10;
        p--;
    }
    buf[4] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615B8_92758);

extern int D_800BDEE0[];
extern int D_800BDEE4;

void func_8015CB70_8DD10(Instance* instance, GameTracker* gameTracker, int count) {
    extern char D_801615C8_92768[];
    extern char D_801615D0_92770[];
    extern char D_801615D8_92778[];
    char buf[16];
    short* p;
    int c;

    p = WORK_AS(short*, instance->work0);
    if (count >= 0x29) {
        c = 0x64;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        osSyncPrintf("Target");
        c = 0x6C;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)p + 0x3C));
        osSyncPrintf(D_801615C8_92768, buf);
        c = 0x74;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)p + 0x3E));
        osSyncPrintf(D_801615D0_92770, buf);
        c = 0x7C;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)p + 0x40));
        osSyncPrintf(D_801615D8_92778, buf);
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615C8_92768); // X %s

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D0_92770); // Y %s

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D8_92778); // Z %s

void func_8015CC64_8DE04(Instance* instance, GameTracker* gameTracker, int count) {
    extern char D_801615C8_92768[];
    extern char D_801615D0_92770[];
    extern char D_801615D8_92778[];
    char buf[16];
    int c;

    c = 0x96;
    if (count >= 0x29) {
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        osSyncPrintf("Position");
        c = 0x9E;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)instance + 0x48));
        osSyncPrintf(D_801615C8_92768, buf);
        c = 0xA6;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)instance + 0x4A));
        osSyncPrintf(D_801615D0_92770, buf);
        c = 0xAE;
        D_800BDEE0[0] = 0xDC;
        D_800BDEE4 = c;
        func_8015CB34_8DCD4(buf, *(short*)((char*)instance + 0x4C));
        osSyncPrintf(D_801615D8_92778, buf);
    }
}

extern int D_800BDEE0[5];

void func_8015CD54_8DEF4(int arg0, int arg1, int count) {
    char buf[16];
    int i;

    if (count >= 0x29) {
        for (i = 0; i < 8; i++) {
            D_800BDEE0[0] = 0x14;
            D_800BDEE0[1] = i * 8 + 0x14;
            func_8015CAF8_8DC98(buf, (rand() << 16) | rand());
            osSyncPrintf("%s", buf);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CDF0_8DF90);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CF08_8E0A8);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015D018_8E1B8);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161610_927B0);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161618_927B8); // frez____

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016161C_927BC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezzull_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015E788_8F928);

extern char D_8016166C_9280C[];

void final_popper_OnCreate(Instance* instance, GameTracker* gameTracker) {
    *(short*)&instance->work0 = 2;
    instance->scale.z = 0;
    instance->work2 = 0;
    instance->position.z -= 0x12C;
    instance->flags |= 0x400;
    WORK_AS(int, instance->work3) = OBTABLE_FindObject(D_80161588_92728);
    WORK_AS(int, instance->work4) = OBTABLE_FindObject(D_8016166C_9280C);
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016166C_9280C);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161670_92810);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_popper_OnUpdate);

extern char D_80161618_927B8[];

void final_popper_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (G2String_Compare_EQ(instance->bspTree->instanceSpline->object->name, D_80161618_927B8)) {
        *(short*)&instance->work0 = 3;
    }
}

void final_finaltv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->position.x = 11520;
    instance->position.y = 9850;
    instance->position.z = 6000;
    instance->_E0[1] = -10;
    instance->_F0 = 100;
    instance->work0 = 30;
}

void final_finaltv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->work0 > 0) {
        instance->work0--;
        return;
    }

    instance->work0--;

    if (instance->work0 == -0x21) {
        func_80050508(instance, 0x154, 0, 0x7F, 0x4E20);
    }
    instance->_D0[2] += instance->_E0[1];
    if (instance->_F0 < abs(instance->_D0[2])) {
        instance->_D0[2] = instance->_D0[2] < 0 ? -instance->_F0 : instance->_F0;
    }
    instance->position.z += instance->_D0[2];
}


void final_finaltv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (G2String_Compare_EQ(instance->bspTree->instanceSpline->object->name, D_80161618_927B8)) {
        func_80046978(instance);
        func_800509E0(0x10, 0x78, 0x80, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015EEF4_90094);

void func_8015F05C_901FC(int arg0, Object* obj, SVECTOR* pos) {
    Model* model;

    if (obj != 0) {
        model = obj->modelList[7];
        if (model != 0) {
            func_800170E8(model, model->_14, pos, 0, 0, D_800EB8A0, func_80017E88, 0, 0x2D);
        }
    }
}

/* returns nonzero when the triangle (p1,p2,t) normal is within t[3] of t */
int func_8015F0C8_90268(int arg0, SVector* p1, SVector* p2, unsigned short* t) {
    SVECTOR n;
    short x;    /* x/y pair serializes the component math (register scheduling) */
    short y;

    _COLLIDE_MakeNormal(&n, p1, p2, (SVector*)t);
    x = n.x;
    y = t[0];
    x -= y;
    n.x = x;
    x = n.y;
    y = t[1];
    x -= y;
    n.y = x;
    x = n.z;
    y = t[2];
    x -= y;
    n.z = x;
    return CAMERA_LengthSVector(&n) < t[3];
}

extern int D_80161544_926E4;
extern SVECTOR D_80161830_929D0;
extern SVECTOR D_80161838_929D8;
extern SVECTOR D_80161840_929E0;
extern SVECTOR D_80161848_929E8;

void func_8015F13C_902DC(SVECTOR* a, SVECTOR* b) {
    if (D_80161544_926E4 == 0) {
        D_80161848_929E8.x = a->x;
        D_80161848_929E8.y = a->y;
        D_80161848_929E8.z = a->z;
        D_80161840_929E0.x = b->x;
        D_80161840_929E0.y = b->y;
        D_80161840_929E0.z = b->z;
    } else {
        D_80161830_929D0.x = a->x;
        D_80161830_929D0.y = a->y;
        D_80161830_929D0.z = a->z;
        D_80161838_929D8.x = b->x;
        D_80161838_929D8.y = b->y;
        D_80161838_929D8.z = b->z;
    }
    D_80161544_926E4 += 1;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F200_903A0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F480_90620);

int func_8015F818_909B8(Instance* instance, SVECTOR* target, int arg2, short arg3) {
    SVECTOR d;
    int angle;

    d.x = target->x - instance->position.x;
    d.y = target->y - instance->position.y;
    d.z = target->z - instance->position.z;
    angle = (short)ratan2(d.y, d.x) + 0x400;
    func_8004ACB0(&instance->rotation.z, angle, arg3);
    return instance->rotation.z == angle;
}

extern char D_8016166C_9280C[];
extern void func_8015F200_903A0(void); // unknown

void final_frez_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (!(instance->flags & 0x20000)) {
        instance->_D0[3] = OBTABLE_FindObject(D_80161588_92728);
        instance->_C4[2] = 0;
        instance->_C4[3] = 1;
        instance->_C4[4] = 1;
        instance->_40[6] -= 0x12C;
        instance->_E0[2] = OBTABLE_FindObject(D_8016166C_9280C);
        instance->additionalDrawFunc = (void*)&func_8015F200_903A0;
        instance->flags |= 0x10400;
        instance->flags2 |= 8;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F964_90B04);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015FAF8_90C98);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015FC3C_90DDC);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161684_92824);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016168C_9282C);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161694_92834);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016169C_9283C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_frez_OnUpdate);

extern char D_8016166C_9280C[];
extern char D_801616F0_92890[];

void final_frez_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    short* temp_s1 = &instance->_C4[2];
    
    if (G2String_Compare_EQ(bsp->instanceSpline->object->name, D_8016166C_9280C)) {
        if (instance->currentMainState != 0) {
            func_800331BC(instance->currentMainState);
            instance->currentMainState = 0;
        }
        if (*temp_s1 != 0xB) {
            ((short*)instance->_D0)[3]++;
            if (((short*)instance->_D0)[3] >= 3) {
                *temp_s1 = 0xC;
            }
            else
            {
                *temp_s1 = 0xB;
            }
        }
        temp_s1[0x2/2] = 1;
    }
    else if ((*temp_s1 != 8) && (bsp->_06 == 1)) {
        if (G2String_Compare_EQ(bsp->instanceSpline->object->name, D_801616F0_92890) && (func_8002275C(PlayerInstance, gameTracker) == 0)) {
            temp_s1[0x34/2] = 0;
        }
    }
}

extern int D_80161558_926F8[];
void final_rezcam_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Camera* temp_s2;
    long* ptr;

    temp_s2 = gameTracker->camera;
    ptr = &instance->work0;
    instance->flags |= 0x800;
    CAMERA_SetMode(gameTracker->camera, 8);
    if (instance->introData == NULL) {
        instance->introData = (void*)&D_80161558_926F8;
    }
    func_80005438(ptr, &instance->position, temp_s2);
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezcam_OnUpdate);

void final_rezcam_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void final_finplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_ret;

    func_80000F24(gameTracker->camera, 213);
    instance->work0 = (rand() % 120) + 120;
    GenericInit(instance, gameTracker);
}

void final_finplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    
    if (--instance->work0 <= 0) {
        if (func_80052FB8() != 0) {
            func_80052C2C(0x4C);
        }
        
        instance->work0 = (rand() % 120) + 120;
    }
    GenericProcess(instance, gameTracker);
}

void final_finplat_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    GenericCollide(instance, gameTracker);
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F0_92890);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F4_92894);
