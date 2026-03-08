#include "common.h"

void guMtxCatF(float mf[4][4], float nf[4][4], float res[4][4])
{
    int	i, j, k;
    float	temp[4][4];

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
        temp[i][j] = 0.0;
        for (k=0; k<4; k++) {
            temp[i][j] += mf[i][k] * nf[k][j];
        }
        }
    }

    /* make sure we handle case where result is an input */
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
        res[i][j] = temp[i][j];
        }
    }
}

void guMtxXFMF(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz)
{
        *ox = mf[0][0]*x + mf[1][0]*y + mf[2][0]*z + mf[3][0];
        *oy = mf[0][1]*x + mf[1][1]*y + mf[2][1]*z + mf[3][1];
        *oz = mf[0][2]*x + mf[1][2]*y + mf[2][2]*z + mf[3][2];
}