#include "types/Matrix.h"

void MulMatrix2(MATRIX* matrix0, MATRIX* matrix1, int resultMatrixIndex);

void MulMatrix0(MATRIX* m0, MATRIX* m1, MATRIX* m2) {
    if (m0 == m2) {
        MulMatrix2(m2, m1, 0);
        return;
    }
    
    if (m1 == m2) {
        MulMatrix2(m0, m2, 1);
        return;
    }
    
    m2->m[0][0] = (((m0->m[0][0] * m1->m[0][0]) + (m0->m[0][1] * m1->m[1][0]) + (m0->m[0][2] * m1->m[2][0])) >> 0xC);
    m2->m[0][1] = (((m0->m[0][0] * m1->m[0][1]) + (m0->m[0][1] * m1->m[1][1]) + (m0->m[0][2] * m1->m[2][1])) >> 0xC);
    m2->m[0][2] = (((m0->m[0][0] * m1->m[0][2]) + (m0->m[0][1] * m1->m[1][2]) + (m0->m[0][2] * m1->m[2][2])) >> 0xC);
    m2->m[1][0] = (((m0->m[1][0] * m1->m[0][0]) + (m0->m[1][1] * m1->m[1][0]) + (m0->m[1][2] * m1->m[2][0])) >> 0xC);
    m2->m[1][1] = (((m0->m[1][0] * m1->m[0][1]) + (m0->m[1][1] * m1->m[1][1]) + (m0->m[1][2] * m1->m[2][1])) >> 0xC);
    m2->m[1][2] = (((m0->m[1][0] * m1->m[0][2]) + (m0->m[1][1] * m1->m[1][2]) + (m0->m[1][2] * m1->m[2][2])) >> 0xC);
    m2->m[2][0] = (((m0->m[2][0] * m1->m[0][0]) + (m0->m[2][1] * m1->m[1][0]) + (m0->m[2][2] * m1->m[2][0])) >> 0xC);
    m2->m[2][1] = (((m0->m[2][0] * m1->m[0][1]) + (m0->m[2][1] * m1->m[1][1]) + (m0->m[2][2] * m1->m[2][1])) >> 0xC);
    m2->m[2][2] = (((m0->m[2][0] * m1->m[0][2]) + (m0->m[2][1] * m1->m[1][2]) + (m0->m[2][2] * m1->m[2][2])) >> 0xC);
}

void MulMatrix2(MATRIX* matrix0, MATRIX* matrix1, int resultMatrixIndex) {
    int c00, c01, c02;
    int c10, c11, c12;
    int c20, c21, c22;
    
    
    c00 = ((matrix0->m[0][0] * matrix1->m[0][0]) + (matrix0->m[0][1] * matrix1->m[1][0]) + (matrix0->m[0][2] * matrix1->m[2][0])) >> 0xC;
    c01 = ((matrix0->m[0][0] * matrix1->m[0][1]) + (matrix0->m[0][1] * matrix1->m[1][1]) + (matrix0->m[0][2] * matrix1->m[2][1])) >> 0xC;
    c02 = ((matrix0->m[0][0] * matrix1->m[0][2]) + (matrix0->m[0][1] * matrix1->m[1][2]) + (matrix0->m[0][2] * matrix1->m[2][2])) >> 0xC;
    
    c10 = ((matrix0->m[1][0] * matrix1->m[0][0]) + (matrix0->m[1][1] * matrix1->m[1][0]) + (matrix0->m[1][2] * matrix1->m[2][0])) >> 0xC;
    c11 = ((matrix0->m[1][0] * matrix1->m[0][1]) + (matrix0->m[1][1] * matrix1->m[1][1]) + (matrix0->m[1][2] * matrix1->m[2][1])) >> 0xC;
    c12 = ((matrix0->m[1][0] * matrix1->m[0][2]) + (matrix0->m[1][1] * matrix1->m[1][2]) + (matrix0->m[1][2] * matrix1->m[2][2])) >> 0xC;
    
    c20 = ((matrix0->m[2][0] * matrix1->m[0][0]) + (matrix0->m[2][1] * matrix1->m[1][0]) + (matrix0->m[2][2] * matrix1->m[2][0])) >> 0xC;
    c21 = ((matrix0->m[2][0] * matrix1->m[0][1]) + (matrix0->m[2][1] * matrix1->m[1][1]) + (matrix0->m[2][2] * matrix1->m[2][1])) >> 0xC;
    c22 = ((matrix0->m[2][0] * matrix1->m[0][2]) + (matrix0->m[2][1] * matrix1->m[1][2]) + (matrix0->m[2][2] * matrix1->m[2][2])) >> 0xC;
    
    if (resultMatrixIndex != 0) {
        matrix1->m[0][0] = c00;
        matrix1->m[0][1] = c01;
        matrix1->m[0][2] = c02;
        matrix1->m[1][0] = c10;
        matrix1->m[1][1] = c11;
        matrix1->m[1][2] = c12;
        matrix1->m[2][0] = c20;
        matrix1->m[2][1] = c21;
        matrix1->m[2][2] = c22;
    }
    else
    {
        matrix0->m[0][0] = c00;
        matrix0->m[0][1] = c01;
        matrix0->m[0][2] = c02;
        matrix0->m[1][0] = c10;
        matrix0->m[1][1] = c11;
        matrix0->m[1][2] = c12;
        matrix0->m[2][0] = c20;
        matrix0->m[2][1] = c21;
        matrix0->m[2][2] = c22;
    }
}
