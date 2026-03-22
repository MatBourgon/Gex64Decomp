#ifndef TMATRIX_H_
#define TMATRIX_H_

typedef struct
{
    short m[3][3]; // 00, 02, 04; 06, 08, 0A; 0C, 0E, 10; 
    long l[3]; // 14, 18, 1C
} MATRIX;

#endif