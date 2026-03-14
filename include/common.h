#ifndef COMMON_H_
#define COMMON_H_

#include "include_asm.h"

#define offsetof(object, member) (((int)&object->member) - (int)object)

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef BOOL
#define BOOL int
#endif

// Forces inlining of function, without generating elsewhere
#ifndef FORCE_INLINE
#define FORCE_INLINE extern inline
#endif

#define gDPPipeSync2(pkt)                           \
{                                                   \
	pkt->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);  \
    do {} while(0); /*required to align properly*/  \
	pkt->words.w1 = 0;                              \
}                                                   \
pkt++;

#endif