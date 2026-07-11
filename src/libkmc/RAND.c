#include <stdlib.h>

static int next;

int rand()
{
/*   long next; */
    next = next * 1103515245 + 12345;

    return ((unsigned int)((next + 1) >> 16) & (RAND_MAX));

    return 0;
}

void srand(seed)
unsigned seed;
{
    next = seed;
}
