#ifndef MATRIX_H_
#define MATRIX_H_

#include "types/Vector.h"
#include "types/Matrix.h"

void MATH3D_ApplyMatrix(MATRIX* mat, SVECTOR* rhs, LVECTOR* out);

void MATH3D_ApplyMatrixLV(MATRIX* mat, LVECTOR* rhs, LVECTOR* out);

void MATH3D_ApplyMatrixSV(MATRIX* mat, SVECTOR* rhs, SVECTOR* out);

void MATH3D_ApplyMatrixT(MATRIX* mat, SVECTOR* rhs, LVECTOR* out);

void MATH3D_ApplyMatrixSVT(MATRIX* mat, SVECTOR* rhs, SVECTOR* out);

#endif