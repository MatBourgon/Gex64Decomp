#ifndef COMMON_H_
#define COMMON_H_

#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .globl " #NAME ".NON_MATCHING\n" \
        "    .type " #NAME ".NON_MATCHING, @object\n" \
        "    " #NAME ".NON_MATCHING:\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )

#define INCLUDE_RODATA(FOLDER, NAME) \
__asm__( \
    ".section .rodata\n" \
    "    .include \"" FOLDER "/" #NAME ".s\"\n" \
    ".section .text" \
)

__asm__(".include \"include/macro.inc\"\n");

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