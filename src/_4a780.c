#include "common.h"
#include "_4a780.h"

#include "types/GameState.h"
#include "types/TVTextData.h"

INCLUDE_ASM("asm/nonmatchings/_4a780", func_80049B80);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A2A4);

int func_8004A344(int*** arg0) {
    int** var_v0 = arg0[7];

  if (var_v0[1] == 0) return 0;

  return *var_v0[1];
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A368);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A3B4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A420);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A47C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A4E4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A54C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A5B4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A61C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A67C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A6C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A7B8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A820);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A8A8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A98C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A9C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AA38);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AA70);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AAA8);

int func_8004AADC(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AAE4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AC10);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AC78);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004ACB0);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AD5C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004ADDC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AEC8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B090);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B23C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B2DC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B32C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B380);

int GetLevelIndexFromId(const char* targetLevelId)
{
    char correctLevelId[16];
    int levelNameLen = cstrlen(targetLevelId);
    int i;
    
    for (i = 0; i < levelNameLen; ++i)
        correctLevelId[i] = ctoupper(targetLevelId[i]);

    correctLevelId[i] = '\0';

    for (i = 0; i < NUM_LEVELS; ++i)
    {
        if (cstrcmp(correctLevelId, TVTextInformation[i].levelId) == 0)
            return i;
    }
    
    return -1;
}

short GetRedRemotesForLevel(unsigned int levelIndex) {
    if (levelIndex >= NUM_LEVELS) {
        levelIndex = 0;
    }
    return TVTextInformation[levelIndex].nRedRemotes;
}


INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E740);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E748);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E750);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E758);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E760);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E768);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E770);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E77C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E784);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E790);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7A0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7A8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7B8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7C0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7D8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7E0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7F0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7FC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E808);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E810);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E81C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E828);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E830);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E840);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E84C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E854);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E860);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E868);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E87C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E884);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E88C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E894);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8A4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8AC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8B8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8D4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8DC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8F0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8F8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E904);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E910);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E918);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E924);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E934);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E940);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E950);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E958);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E968);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E974);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E980);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E990);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E998);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9A0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9A8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9B4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9C0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9D0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9D8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9E8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9F4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9FC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA04);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA14);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA20);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA34);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA3C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA44);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA48);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA5C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA64);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA6C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA78);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA80);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA84);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA8C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA98);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B604);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B968);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BAAC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BFBC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C040);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C110);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C2F4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C350);

extern int D_8007864C[];

void func_8004C43C() {
    int i;
    
    for (i = 0x20; i < 0x24; ++i)
        D_8007864C[i-0x20] = 0;
}

int func_8004C464(int** arg1, int** arg2) {
    arg2[1][7] |= 0x80;                    
    return 1;     
}

int func_8004C484(int* arg1, int** arg2) {
    arg2[1][7] &= ~0x80;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C4A4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C524);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C558);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C598);

int func_8004C634(int* arg1, int* arg2) {
    int* var1;
    int* var2;
    
    var1 = (int*)arg2[1]; 
    arg1 = (int*)var1[9];

     if (arg1 != 0) {
        (int)arg2 = arg1[4] &= 0xFDFFFFFF;
    }
    return 1;
}

int func_8004C664(void) {
    return 1;
}

int func_8004C66C(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C674);

int func_8004C6A0(int* arg1, int* arg2) {
    int* temp_v0 = (int*)arg2[1];
    short* temp_v1  = (short*)temp_v0[9];
    
    if (temp_v1 != 0) {
        temp_v1[97] = arg2[2];
    }
    return 1;
}

int func_8004C6CC(int* arg1, int* arg2) {
    int* var1;
    int* var2;


    (int)var2 = arg2[1];
    
    if (var2 != 0) 
    {
        (int)var1 = var2[2];
        var2[11] = arg2[2];
         
    }
    return 1;
}

int func_8004C6F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C6F8);

int func_8004C71C(char* arg0, int* arg1) {
    arg0[79] = arg1[1];
    
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C730);

int func_8004C760(int* arg1, int* arg2) {
    arg1 = (int*)arg2[1];
    func_80003D4C(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C784);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C7B4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C7E4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C814);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C844);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C868);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C898);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C8C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C8F8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C930);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CAAC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CAD0);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CB10);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CB44);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CB78);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CBAC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CBEC);

int func_8004CC2C(int* arg1, int* arg2) {
    if (arg2[1] > 0) {
        --arg2[1];
        return 1;
    }
   
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CC54);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CD60);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CDFC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CEB4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CF84);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004CFC8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D00C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D064);

int func_8004D0C0(int* arg1, int* arg2) {
    short unsigned* temp_v1 = (short*)arg2[1];
        
    if (temp_v1 != 0) {
        *temp_v1 |= 1;
    }
    return 1;
}

int func_8004D0E8(int* arg1, int* arg2) {
    short* temp_v0 = (short*)arg2[1];
 
    if (temp_v0 != 0) {
        *temp_v0 &= 0xFFFE;
    }
    return 1;
}

int func_8004D110(int* arg0) {
    int value = arg0[4];
    int value2 = 0x20000000;
    value = value | value2;
    arg0[4] = value;
    return 1;
}

int func_8004D128(int* arg0) {
    arg0[4] &= 0xDFFFFFFF;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D144);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D160);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D184);

// Unsets a flag?
int func_8004D1A8(int* arg1, int* arg2) {
    *(int*)arg2[1] &= ~2;
    return 1;
}

// Sets a flag?
int func_8004D1C8(int* arg1, int* arg2) {
    *(int*)arg2[1] |= 2;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D1E8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D208);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D240);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D298);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D2F8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D33C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D3AC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D41C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D444);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D46C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D4B0);

int func_8004D4F4(int *arg1, int** arg2) {
    func_8004EBAC(arg1, arg2[1], 0);
    return 0;
}

int func_8004D51C(void) {
    return 1;
}

int func_8004D524(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D52C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D554);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D578);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D5A4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D70C);

extern void func_80027468();                                  /* extern */

int func_8004D740(void) {
    func_80027468();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D760);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D794);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D83C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D8A8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D8DC);

extern int func_80033334(int* arg);                               /* extern */

int func_8004D944(int* arg0, int* arg1) {
    (int)arg0 = arg1[1];
    func_80033334(arg0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D968);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D9A8);

int func_8004DA48(void) {
    return 1;
}

int func_8004DA50(void) {
    return 1;
}
int func_8004DA58(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DA60);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DAB0);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DB04);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DD08);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DE08);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E21C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E2D8);
extern int func_80052944(int arg0);                               /* extern */

int func_8004E318(int* arg1, int* arg2) {
    (int)arg1 = arg2[1];
    func_80052944((int)arg1);
    return 1;
}

extern int func_8005294C(int arg0);                               /* extern */

int func_8004E33C(int* arg1, int* arg2) {
    (int)arg1 = arg2[1];
    func_8005294C((int)arg1);
    return 1;
}

int func_8004E360(int arg1, int* arg2) {
    arg1 = arg2[1];
    func_80052A7C(arg1);
    return 1;
}

extern int func_80052AA8(int* arg0);                               /* extern */

int func_8004E384(int* arg1, int* arg2) {
    (int)arg1 = arg2[1];
    func_80052AA8((int*)arg1);
    return 1;
}

extern void func_80052954();                                  /* extern */

int func_8004E3A8(void) {
    func_80052954();
    return 1;
}

int func_8004E3C8(void) {
    func_80052F58();
    return 1;
}

extern void func_80052F7C();                                  /* extern */

int func_8004E3E8(void) {
    func_80052F7C();
    return 1;
}

int func_8004E408(void* arg0, int** arg1) {
    if ((arg1[1] != 0) && (arg1[1][7] & 8)) {
        if (arg1[2] != NULL) {
            func_8004EBAC(arg0, arg1[2], 0);
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E468);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E4C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E51C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E540);

int func_8004E568(int* arg1, int* arg2) {
    int* temp1 = (int*)arg2[1];
    int temp2 = arg2[2];
    temp1[1] = temp2; 
    return 1;
}             

int func_8004E580(int arg0, char* arg1) {
    func_80039688(arg1[4], arg1[5], arg1[6], gpGameState8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E5B8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E768);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E7C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E828);

extern short D_8007865C;

int func_8004E8BC(void) {
    D_8007865C = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004E8D0);

int func_8004E920(int* arg1, int **arg2) {
    
    int* a2ptr = arg2[1];
    if (a2ptr) {
        
        int* ptr = (int*)a2ptr[9];
        a2ptr[7] &= ~0x2000;
        
        if (ptr) {
            ptr[4] &= ~0x400;
        }
        
    }
    return 1;
}

extern void func_8002AE40();                                  /* extern */
extern void func_8015E228();                                  /* extern */

int func_8004E95C(int* arg1, int* arg2) {
    int temp_v1 = arg2[1];
    
    if ((temp_v1 != 0) && (temp_v1 == 1)) {
        func_8015E228();
    } else {
        func_8002AE40();
    }
    return 1;
}

extern int D_8015EE24;

int func_8004E9A8(int* arg1, int* arg2) {
    int* var0 = (int*)arg2[1];
    D_8015EE24 = (int)var0;
    return 1;
}

extern int D_8015EE28; /* extern */

int func_8004E9BC(int* arg1, int* arg2) {
    int var1 = arg2[1];
    D_8015EE28 = var1;
    return 1;
}

extern int D_8015EE2C;

int func_8004E9D0(int* arg1, int* arg2) {
    D_8015EE2C = arg2[1];
    return 1;
}

extern int D_8015EE30;

int func_8004E9E4(int arg1, int* arg2) {
    int temp_v0 = arg2[1];
    D_8015EE30 = temp_v0;
    return 1;
}

int func_8004E9F8(int* arg1, int* arg2) {
    int* temp_v0;
    int* temp_v1;

    temp_v1 = (int*)arg2[2];
    if (temp_v1 != 0) {
        temp_v0 = (int*)temp_v1[9];
        
        if (temp_v0 != 0) {
        temp_v1 =  (int*)arg2[1];
        (int*)temp_v0[72] = temp_v1;
        }
    } 
    
    
    return 1;
}
INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004EA2C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004EA58);

void func_8004EBAC(void* arg0, void* arg1, void* arg2) {
    func_8004EA58(arg0, arg1, 1, arg2);
}

typedef struct
{
    int* ptr;
    int value;
} func_8004EBD0_t;

int func_8004EBD0(func_8004EBD0_t* arg0) {
    if (arg0 == NULL)
        return;
    
    while (arg0->ptr != NULL)
    {
        *arg0->ptr = arg0->value;
        arg0++;
    }
}
