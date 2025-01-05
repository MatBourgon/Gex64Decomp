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

#endif