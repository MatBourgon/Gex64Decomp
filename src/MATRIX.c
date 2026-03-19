#include "common.h"

#include "MATRIX.h"

void MATH3D_ApplyMatrix(MATRIX* mat, SVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void MATH3D_ApplyMatrixLV(MATRIX* mat, LVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void MATH3D_ApplyMatrixSV(MATRIX* mat, SVECTOR* rhs, SVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void MATH3D_ApplyMatrixT(MATRIX* mat, SVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC) + mat->l[0];
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC) + mat->l[1];
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC) + mat->l[2];
}

void MATH3D_ApplyMatrixSVT(MATRIX* mat, SVECTOR* rhs, SVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC) + mat->l[0];
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC) + mat->l[1];
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC) + mat->l[2];
}