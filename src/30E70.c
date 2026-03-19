#include "common.h"

#include "types/Vector.h"
#include "types/Matrix.h"
#include "types/Quat.h"

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030270);

INCLUDE_ASM("asm/nonmatchings/30E70", ratan2);

INCLUDE_ASM("asm/nonmatchings/30E70", func_800305FC);

INCLUDE_ASM("asm/nonmatchings/30E70", func_800306DC);

FORCE_INLINE long MATH3D_FastSqrt_Inner(long square)
{
    unsigned long result;
    long remainder;
    long mask;
    long shift;
    long mask_squared;
    long result_shift;

    shift = 31;
    mask = 0x80000000;

        while (!(mask & square))
        {
            mask >>= 1;

            shift--;
        }

    shift >>= 1;

    result = 1 << (shift + 6);

    mask = result;

    result_shift = 1 << (shift << 1);

    mask_squared = result_shift;

    shift--;

    square -= result_shift;

    while (shift != -1)
    {
        mask_squared >>= 2;

        remainder = result_shift + mask_squared;
        remainder = square - remainder;

        mask >>= 1;

        if (remainder < 0)
        {
            result_shift >>= 1;
        }
        else
        {
            square = remainder;

            remainder = result_shift >> 1;

            result_shift = remainder + mask_squared;

            result |= mask;
        }

        shift--;
    }

    mask_squared >>= 2;

    square <<= 12;

    result_shift <<= 12;

    mask_squared = 4096;

    mask >>= 1;

    while (mask != 0)
    {
        mask_squared >>= 2;

        remainder = result_shift + mask_squared;
        remainder = square - remainder;

        if (remainder < 0)
        {
            result_shift >>= 1;
        }
        else
        {
            square = remainder;

            remainder = result_shift >> 1;

            result_shift = remainder + mask_squared;

            result |= mask;
        }

        mask >>= 1;
    }

    return result;
}

long MATH3D_FastSqrt(long square)
{

    if (square != 0)
    {
        return MATH3D_FastSqrt_Inner(square);
    }

    return 0;
}

FORCE_INLINE int MATH3D_FastSqrt2_Inner(long square, int c)
{
    unsigned long result;
    long remainder;
    long mask;
    long shift;
    long mask_squared;
    long result_shift;

    shift = 31;
    mask = 0x80000000;

    while (!(mask & square))
    {
        mask >>= 1;
        shift--;
    }

    shift >>= 1;

    result = 1 << (shift + ((c + (int)((unsigned int)c >> 31)) >> 1));


    mask = result;

    result_shift = 1 << (shift << 1);

    mask_squared = result_shift;

    shift--;

    square -= result_shift;

    while (shift != -1)
    {
        mask_squared >>= 2;

        remainder = result_shift + mask_squared;
        remainder = square - remainder;

        mask >>= 1;

        if (remainder < 0)
        {
            result_shift >>= 1;
        }
        else
        {
            square = remainder;

            remainder = result_shift >> 1;

            result_shift = remainder + mask_squared;

            result |= mask;
        }

        shift--;
    }

    mask_squared >>= 2;

    square <<= c;

    result_shift <<= c;

    mask_squared = 1 << c;

    mask >>= 1;

    while (mask != 0)
    {
        mask_squared >>= 2;

        remainder = result_shift + mask_squared;
        remainder = square - remainder;

        if (remainder < 0)
        {
            result_shift >>= 1;
        }
        else
        {
            square = remainder;

            remainder = result_shift >> 1;

            result_shift = remainder + mask_squared;

            result |= mask;
        }

        mask >>= 1;
    }

    return result;
}

long MATH3D_FastSqrt2(long square, int c)
{
    if (square != 0)
    {
        return MATH3D_FastSqrt2_Inner(square, c);
    }

    return 0;
}

short MATH3D_AngleBetweenVectors(SVECTOR* v1, SVECTOR* v2) {
    int projection_length;

    if (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z) {
        return 0;
    }
    
    projection_length = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + 2048) >> 0xC;
    
    if (projection_length > 4096) {
        projection_length = 4096;
    }
    
    if (projection_length < -4096) {
        projection_length = -4096;
    }
    
    return ratan2(MATH3D_FastSqrt(4096 - ((projection_length * projection_length) >> 0xC)), projection_length);
}

FORCE_INLINE void TransposeMatrix(MATRIX* i, MATRIX* o)
{
    o->m[0][0] = i->m[0][0];
    o->m[1][0] = i->m[0][1];
    o->m[2][0] = i->m[0][2];
    o->m[0][1] = i->m[1][0];
    o->m[1][1] = i->m[1][1];
    o->m[2][1] = i->m[1][2];
    o->m[0][2] = i->m[2][0];
    o->m[1][2] = i->m[2][1];
    o->m[2][2] = i->m[2][2];
}

void MATH3D_RotMatAboutVec(SVECTOR* vec, MATRIX* mat, short angle) {
    int length;
    SVECTOR rot_angs;
    MATRIX mat1;
    MATRIX mat2;

    if (angle != 0) {
        length = MATH3D_FastSqrt((MATH3D_SquareLength(0, vec->y, vec->z) + 2048) >> 0xC);
        rot_angs.x = -ratan2(vec->y, vec->z);
        rot_angs.y = ratan2(vec->x, length);
        rot_angs.z = 0;
        RotMatrix(&rot_angs, &mat1);
        TransposeMatrix(&mat1, &mat2);
        MulMatrix2(&mat2, mat, 1);
        RotMatrixZ(angle, mat);
        MulMatrix2(&mat1, mat, 1);
    }
    
}

void MATH3D_SetUnityMatrix(MATRIX* mat) {
    mat->m[0][0] = 4096;
    mat->m[0][1] = 0;
    mat->m[0][2] = 0;
    mat->m[1][0] = 0;
    mat->m[1][1] = 4096;
    mat->m[1][2] = 0;
    mat->m[2][0] = 0;
    mat->m[2][1] = 0;
    mat->m[2][2] = 4096;
}


void MATH3D_SetIdentityQuat(G2Quat* q)
{
    q->x = q->y = q->z = 0;
    q->w = 4096;
}

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030BA0);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030BE0);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030C50);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030CB4);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030D34);
