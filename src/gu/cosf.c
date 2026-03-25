#include "common.h"

#include <gu/guint.h>
extern const du D_8007EC60[];

INCLUDE_RODATA("asm/nonmatchings/gu/cosf", __libm_qnan_f);

INCLUDE_ASM("asm/nonmatchings/gu/cosf", cosf);

INCLUDE_RODATA("asm/nonmatchings/gu/cosf", D_8007EDA0);
