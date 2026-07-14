#include "common.h"

#include "level/FINAL.h"
#include "types/G2String.h"

extern int D_80161510_926B0;

void final_oldpoptv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_100 = 1;
    instance->_FC = 0;
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
        if (instance->_FC != 0) {
            func_800331BC(instance->_FC);
            instance->_FC = 0;
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

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_80159E50_8AFF0);

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

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A4C8_8B668);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A590_8B730);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A78C_8B92C);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_rezbomb_OnUpdate);

void final_rezbomb_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015A9F0_8BB90);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AC70_8BE10);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015ADC4_8BF64);

extern int D_800785C8;

void func_8015AE98_8C038(void) {
    PlayerInstance->currentMainState = D_800785C8;
    func_80003234(gameTracker8->camera);
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015AED8_8C078);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015B07C_8C21C);

extern void func_8004ACB0(short* angle, short target, int step);

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

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015BFB8_8D158);

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

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CB70_8DD10);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615C8_92768); // X %s

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D0_92770); // Y %s

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801615D8_92778); // Z %s

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015CC64_8DE04);

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
    *(short*)&instance->_FC = 2;
    instance->scale.z = 0;
    instance->_104 = 0;
    instance->position.z -= 0x12C;
    instance->flags |= 0x400;
    WORK_AS(int, instance->_108) = OBTABLE_FindObject(D_80161588_92728);
    WORK_AS(int, instance->_10C) = OBTABLE_FindObject(D_8016166C_9280C);
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_8016166C_9280C);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_80161670_92810);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_popper_OnUpdate);

extern char D_80161618_927B8[];

void final_popper_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (G2String_Compare_EQ(instance->bspTree->instanceSpline->object->name, D_80161618_927B8)) {
        *(short*)&instance->_FC = 3;
    }
}

void final_finaltv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->position.x = 11520;
    instance->position.y = 9850;
    instance->position.z = 6000;
    instance->_E0[1] = -10;
    instance->_F0 = 100;
    instance->_FC = 30;
}

INCLUDE_ASM("asm/nonmatchings/level/FINAL", final_finaltv_OnUpdate);

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

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F13C_902DC);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F200_903A0);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F480_90620);

INCLUDE_ASM("asm/nonmatchings/level/FINAL", func_8015F818_909B8);

extern char D_8016166C_9280C[];
extern void func_8015F200_903A0(void); // unknown

void final_frez_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (!(instance->flags & 0x20000)) {
        instance->_D0[3] = OBTABLE_FindObject(D_80161588_92728);
        instance->_C0[2] = 0;
        instance->_C0[3] = 1;
        instance->_C0[4] = 1;
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
    short* temp_s1 = &instance->_C0[2];
    
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
    int* ptr;

    temp_s2 = gameTracker->camera;
    ptr = &instance->_FC;
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
    instance->_FC = (rand() % 120) + 120;
    GenericInit(instance, gameTracker);
}

void final_finplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    
    if (--instance->_FC <= 0) {
        if (func_80052FB8() != 0) {
            func_80052C2C(0x4C);
        }
        
        instance->_FC = (rand() % 120) + 120;
    }
    GenericProcess(instance, gameTracker);
}

void final_finplat_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    GenericCollide(instance, gameTracker);
}

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F0_92890);

INCLUDE_RODATA("asm/nonmatchings/level/FINAL", D_801616F4_92894);
