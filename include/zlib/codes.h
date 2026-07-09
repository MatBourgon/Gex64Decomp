#ifndef INFLATE_H_
#define INFLATE_H_

typedef struct
{
  /* mode */
  enum
    {
        START,    /* x: set up for LEN */
        LEN,      /* i: get length/literal/eob next */
        LENEXT,   /* i: getting length extra (have base) */
        DIST,     /* i: get distance next */
        DISTEXT,  /* i: getting distance extra */
        COPY,     /* o: copying bytes in window, waiting for space */
        LIT,      /* o: got literal, waiting for output space */
        WASH,     /* o: got eob, possibly still output waiting */
        END,      /* x: got eob and all data flushed */
        BADCODE   /* x: got error */
    } mode;       /* current inflate_codes mode */

    unsigned int len;
    union
    {
        struct
        {
            struct inflate_huft* tree; /* pointer into tree */
            unsigned int need;  /* bits needed */
        } code;                 /* if LEN or DIST, where in tree */
        unsigned int lit;       /* if LIT, literal */
        struct
        {
            unsigned int get;   /* bits to get for extra */
            unsigned int dist;  /* distance back to copy from */
        } copy;                 /* if EXT or COPY, where and how much */
    } sub;                      /* submode */
    
    unsigned char lbits;        /* ltree bits decoded per branch */
    unsigned char dbits;        /* dtree bits decoder per branch */
    struct inflate_huft* ltree;        /* literal/length/eob tree */
    struct inflate_huft* dtree;        /* distance tree */
} inflate_codes_state;

typedef struct inflate_huft {
    union {
        struct {
            unsigned char Exop;    /* number of extra bits or operation */
            unsigned char Bits;    /* number of bits in this code or subcode */
        } what;
        unsigned int pad;          /* pad structure to a power of 2 */
    } word;
    unsigned int base;             /* literal, length base, distance base, or table offset */
} inflate_huft;

typedef struct inflate_blocks_state_s {
    enum {
        TYPE,     /* get type bits (3, including end bit) */
        LENS,     /* get lengths for stored */
        STORED,   /* processing stored block */
        TABLE,    /* get table lengths */
        BTREE,    /* get bit lengths tree for a dynamic block */
        DTREE,    /* get length, distance trees for a dynamic block */
        CODES,    /* processing fixed or dynamic block */
        DRY,      /* output remaining window bytes */
        DONE,     /* finished last block, done */
        BAD       /* got a data error--stuck here */
    } mode;       /* current inflate_block mode */

    union {
        unsigned int left;         /* if STORED, bytes left to copy */
        struct {
            unsigned int table;    /* table lengths (14 bits) */
            unsigned int index;    /* index into blens (or border) */
            unsigned int* blens;   /* bit lengths of codes */
            unsigned int bb;       /* bit length tree depth */
            inflate_huft* tb;      /* bit length decoding tree */
        } trees;                   /* if DTREE, decoding info for trees */
        struct {
            inflate_codes_state* codes;
        } decode;                  /* if CODES, current state */
    } sub;                         /* submode */

    unsigned int last;             /* true if this block is the last block */
    unsigned int bitk;             /* bits in bit buffer */
    unsigned long bitb;            /* bit buffer */
    inflate_huft* hufts;           /* single malloc for tree space */
    unsigned char* window;         /* sliding window */
    unsigned char* end;            /* one byte after sliding window */
    unsigned char* read;           /* window read pointer */
    unsigned char* write;          /* window write pointer */
    void* checkfn;                 /* check function */
    unsigned long check;           /* check on output */
} inflate_blocks_state;

int inflate_flush(inflate_blocks_state* s, z_stream* z, int r);
int huft_build(unsigned int* b, unsigned int n, unsigned int s, unsigned int* d, unsigned int* e,
               inflate_huft** t, unsigned int* m, inflate_huft* hp, unsigned int* hn, unsigned int* v);
int inflate_trees_bits(unsigned int* c, unsigned int* bb, inflate_huft** tb, inflate_huft* hp, z_stream* z);
int inflate_trees_dynamic(unsigned int nl, unsigned int nd, unsigned int* c, unsigned int* bl, unsigned int* bd,
                          inflate_huft** tl, inflate_huft** td, inflate_huft* hp, z_stream* z);
int inflate_trees_fixed(unsigned int* bl, unsigned int* bd, inflate_huft** tl, inflate_huft** td, z_stream* z);
int inflate_codes(inflate_blocks_state* s, z_stream* z, int r);
int inflate_blocks(inflate_blocks_state* s, z_stream* z, int r);
inflate_codes_state* inflate_codes_new(unsigned int bl, unsigned int bd, struct inflate_huft* tl, struct inflate_huft* td, z_stream* z);

#endif