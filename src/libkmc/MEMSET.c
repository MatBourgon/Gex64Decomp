/*
    Copyright (c) 1995,1996 by Kyoto Micro Computer Co. Ltd.
    All Rights Reserved.
*/

/*
	void *memset(void *dest, int c, size_t n);
	void setmem(void *dest, size_t n, int c);

*/

#include "_KMCLIB.h"
#include <MEMORY.h>

void *memset(dest,ch,n)
REG5 void *dest;
int ch;
REG4 size_t n;
{
    REG2 char *d;

#if FAST_SPEED /* { */
    REG1 UDWORD c;
    REG3 size_t n1;

    if (n==0) return dest;
    c = (ch&0xff);
    c |= c<<8;
    c |= c<<16;
    
    d=dest;
    if ((int)d&1) {
    	*((BYTE *)d)++ = (BYTE )c;		/* ALLIGN 16bit */
	--n;
    }
    if (n>=2) {
	if ((int)d&2) {
	    *((WORD *)d)++ = (WORD)c;		/* ALLIGN 32bit */
    	    n -= 2;
	}
    }
    n1 = n>> 2;
    while(n1--) {
        *((DWORD *)d)++ = (DWORD)c;		/* 32bit set */
    }
    if (n&2) *((WORD *)d)++ = (WORD)c;
    if (n&1) *(BYTE *)d = (BYTE)c;

#else /* }{ */
    d=dest;
    while(n--) {
        *(BYTE *)d++ = ch;
    }
#endif /* } */
    return dest;
}

void setmem(dest,n,c)
void *dest;
size_t n;
int c;
{
	memset(dest,c,n);
}


