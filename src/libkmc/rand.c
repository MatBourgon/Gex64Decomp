#include "common.h"
#include <stdlib.h>

static int sRandNext;

int rand() {
    sRandNext = sRandNext * 1103515245 + 12345;

    return ((unsigned int)((sRandNext + 1) >> 16) % (RAND_MAX + 1));
}

void srand(unsigned seed) {
    sRandNext = seed;
}
