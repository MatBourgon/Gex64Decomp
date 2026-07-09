#include "common.h"

#include "zlib/zlib.h"
#include "zlib/codes.h"

extern char D_801E0BC0;
int inflate(z_stream* z, char* compressedDataStart, int compressedDataSize) {
    int blockSize;
    int comnpressedBytesRemaining;
    int dataOffset;
    BOOL isDone;

    isDone = FALSE;
    comnpressedBytesRemaining = compressedDataSize;
    dataOffset = 0;
    
    while (z->avail_out != 0) {
        if ((z->avail_in == 0) && !isDone) {
            blockSize = 0x4000;
            if (comnpressedBytesRemaining < 0x4001) {
                blockSize = comnpressedBytesRemaining;
            }
            if (blockSize != 0) {
                DMATransferData(compressedDataStart + dataOffset, &D_801E0BC0, (blockSize + 7) & ~7);
                comnpressedBytesRemaining -= blockSize;
                dataOffset += blockSize;
                z->avail_in = blockSize;
            } else {
                z->avail_in = 0;
                isDone = TRUE;
            }
            z->next_in = &D_801E0BC0;
        }
        
        if (inflate_blocks((inflate_blocks_state*)z->state, z, -5) != 0)
            break;
        
        if (isDone)
            break;
    }
    
    return z->total_out;
}

extern inflate_blocks_state D_801DCCB0;
extern inflate_huft D_801DDEC0[];
extern unsigned char D_801E4BE0[];

int func_801DA910_ED200(z_stream* z, unsigned char* next_out, unsigned int avail_out) {
    inflate_blocks_state* s;

    s = &D_801DCCB0;
    s->hufts = D_801DDEC0;
    s->window = D_801E4BE0;
    s->end = s->window + 0x8000;
    s->mode = TYPE;
    s->bitk = 0;
    s->bitb = 0;
    s->write = s->window;
    s->read = s->window;
    z->next_in = (unsigned char*)&D_801E0BC0;
    z->avail_in = 0;
    z->total_out = 0;
    z->total_in = 0;
    z->avail_out = avail_out;
    z->next_out = next_out;
    z->state = (struct internal_state*)s;
    return 0;
}

int inflate_flush(inflate_blocks_state* s, z_stream* z, int r) {
    unsigned int n;
    unsigned int i;
    unsigned char* p;
    unsigned char* q;
    unsigned int unused[1];      /* dead local — reproduces the 0x10 frame */

    /* local copies of source and destination pointers */
    q = s->read;
    p = z->next_out;

    /* compute number of bytes to copy as far as end of window */
    n = q <= s->write ? s->write - q : s->end - q;
    if (z->avail_out < n) {
        n = z->avail_out;
    }
    if (n != 0 && r == -5) {
        r = 0;
    }

    /* update counters */
    z->avail_out -= n;
    z->total_out += n;

    /* copy as far as end of window */
    for (i = 0; i < n; i++) {
        *p++ = *q++;
    }

    /* see if more to copy at beginning of window */
    if (q == s->end) {
        /* wrap pointers */
        q = s->window;
        if (s->write == s->end) {
            s->write = s->window;
        }

        /* compute bytes to copy */
        n = s->write - q;
        if (z->avail_out < n) {
            n = z->avail_out;
        }
        if (n != 0 && r == -5) {
            r = 0;
        }

        /* update counters */
        z->avail_out -= n;
        z->total_out += n;

        /* copy */
        for (i = 0; i < n; i++) {
            *p++ = *q++;
        }
    }

    /* update pointers */
    z->next_out = p;
    s->read = q;
    return r;
}

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_mask);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_fixed_built);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_border);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cplens);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cplext);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cpdist);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cpdext);

extern unsigned int inflate_mask[];

/* zlib infutil.h macros, adapted: FLUSH has no WRAP (it is explicit in
   NEEDOUT), and the huft tables link by absolute pointer */
#define UPDBITS { s->bitb = b; s->bitk = k; }
#define UPDIN { z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; }
#define UPDOUT { s->write = q; }
#define UPDATE { UPDBITS UPDIN UPDOUT }
#define LEAVE { UPDATE return inflate_flush(s, z, r); }
#define LOADIN { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; }
#define NEEDBYTE { if (n) r = 0; else LEAVE }
#define NEXTBYTE (n--, *p++)
#define NEEDBITS(j) { while (k < (j)) { NEEDBYTE b |= ((unsigned int)NEXTBYTE) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WAVAIL (unsigned int)(q < s->read ? s->read - q - 1 : s->end - q)
#define LOADOUT { q = s->write; m = (unsigned int)WAVAIL; }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = (unsigned int)WAVAIL; } }
#define FLUSH { UPDOUT r = inflate_flush(s, z, r); LOADOUT }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }
#define OUTBYTE(a) { *q++ = (unsigned char)(a); m--; }
#define LOAD { LOADIN LOADOUT }

extern const unsigned int inflate_border[];
extern unsigned int D_801ECBE0[];

int inflate_blocks(inflate_blocks_state* s, z_stream* z, int r) {
    unsigned int t;               /* temporary storage */
    unsigned int b;               /* bit buffer */
    unsigned int k;               /* bits in bit buffer */
    unsigned char* p;             /* input data pointer */
    unsigned int n;               /* bytes available there */
    unsigned char* q;             /* output window write pointer */
    unsigned int m;               /* bytes to end of window or read pointer */
    unsigned int i;               /* stored block copy counter */

    /* copy input/output information to locals (UPDATE macro restores) */
    LOAD

    /* process input based on current state */
    while (1) {
        switch (s->mode) {
        case TYPE:          /* get type bits (3, including end bit) */
            NEEDBITS(3)
            t = (unsigned int)b & 7;
            s->last = t & 1;
            switch (t >> 1) {
            case 0:                     /* stored */
                DUMPBITS(3)
                t = k & 7;              /* go to byte boundary */
                DUMPBITS(t)
                s->mode = LENS;         /* get length of stored block */
                break;
            case 1:                     /* fixed */
            {
                unsigned int bl, bd;
                inflate_huft* tl;
                inflate_huft* td;

                inflate_trees_fixed(&bl, &bd, &tl, &td, z);
                s->sub.decode.codes = inflate_codes_new(bl, bd, tl, td, z);
            }
                DUMPBITS(3)
                s->mode = CODES;
                break;
            case 2:                     /* dynamic */
                DUMPBITS(3)
                s->mode = TABLE;
                break;
            }
            break;
        case LENS:          /* get lengths for stored */
            NEEDBITS(32)
            s->sub.left = (unsigned int)b & 0xffff;
            b = k = 0;                  /* dump bits */
            s->mode = s->sub.left ? STORED : (s->last ? DRY : TYPE);
            break;
        case STORED:        /* processing stored block */
            if (n == 0) {
                LEAVE
            }
            NEEDOUT
            t = s->sub.left;
            if (t > n) {
                t = n;
            }
            if (t > m) {
                t = m;
            }
            for (i = 0; i < t; i++) {
                *q++ = *p++;
            }
            n -= t;
            m -= t;
            if ((s->sub.left -= t) != 0) {
                break;
            }
            s->mode = s->last ? DRY : TYPE;
            break;
        case TABLE:         /* get table lengths */
            NEEDBITS(14)
            s->sub.trees.table = t = (unsigned int)b & 0x3fff;
            s->sub.trees.blens = D_801ECBE0;
            DUMPBITS(14)
            s->sub.trees.index = 0;
            s->mode = BTREE;
        case BTREE:         /* get bit lengths tree for a dynamic block */
            while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10)) {
                NEEDBITS(3)
                s->sub.trees.blens[inflate_border[s->sub.trees.index++]] = (unsigned int)b & 7;
                DUMPBITS(3)
            }
            while (s->sub.trees.index < 19) {
                s->sub.trees.blens[inflate_border[s->sub.trees.index++]] = 0;
            }
            s->sub.trees.bb = 7;
            inflate_trees_bits(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, s->hufts, z);
            s->sub.trees.index = 0;
            s->mode = DTREE;
        case DTREE:         /* get length, distance trees for a dynamic block */
            while (t = s->sub.trees.table,
                   s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f)) {
                inflate_huft* h;
                unsigned int i, j, c;

                t = s->sub.trees.bb;
                NEEDBITS(t)
                h = s->sub.trees.tb + ((unsigned int)b & inflate_mask[t]);
                t = h->word.what.Bits;
                c = h->base;
                if (c < 16) {
                    DUMPBITS(t)
                    s->sub.trees.blens[s->sub.trees.index++] = c;
                } else {    /* c == 16..18 */
                    i = c == 18 ? 7 : c - 14;
                    j = c == 18 ? 11 : 3;
                    NEEDBITS(t + i)
                    DUMPBITS(t)
                    j += (unsigned int)b & inflate_mask[i];
                    DUMPBITS(i)
                    i = s->sub.trees.index;
                    c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
                    do {
                        s->sub.trees.blens[i++] = c;
                    } while (--j);
                    s->sub.trees.index = i;
                }
            }
            s->sub.trees.tb = 0;
            {
                unsigned int bl, bd;
                inflate_huft* tl;
                inflate_huft* td;

                bl = 9;                 /* must be <= 9 for lookahead assumptions */
                bd = 6;                 /* must be <= 6 for lookahead assumptions */
                t = s->sub.trees.table;
                inflate_trees_dynamic(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f), s->sub.trees.blens, &bl, &bd, &tl, &td, s->hufts, z);
                s->sub.decode.codes = inflate_codes_new(bl, bd, tl, td, z);
            }
            s->mode = CODES;
        case CODES:         /* processing fixed or dynamic block */
            UPDATE
            r = inflate_codes(s, z, r);
            if (r != 1) {
                return inflate_flush(s, z, r);
            }
            r = 0;
            LOAD
            if (!s->last) {
                s->mode = TYPE;
                break;
            }
            if (k > 7) {                /* return unused byte, if any */
                k -= 8;
                n++;
                p--;
            }
            s->mode = DRY;
        case DRY:           /* output remaining window bytes */
            FLUSH
            if (s->read != s->write) {
                LEAVE
            }
            s->mode = DONE;
        case DONE:          /* finished last block, done */
            r = 1;
            LEAVE
        }
    }
}

extern inflate_codes_state inflate_codesState;
inflate_codes_state* inflate_codes_new(unsigned int bl, unsigned int bd, struct inflate_huft* tl, struct inflate_huft* td, z_stream* z)
{
    inflate_codesState.mode = START;
    inflate_codesState.lbits = bl;
    inflate_codesState.dbits = bd;
    inflate_codesState.ltree = tl;
    inflate_codesState.dtree = td;
    return &inflate_codesState;
}


int inflate_codes(inflate_blocks_state* s, z_stream* z, int r) {
    unsigned int j;               /* temporary storage */
    inflate_huft* t;              /* temporary pointer */
    unsigned int e;               /* extra bits or operation */
    unsigned int b;               /* bit buffer */
    unsigned int k;               /* bits in bit buffer */
    unsigned char* p;             /* input data pointer */
    unsigned int n;               /* bytes available there */
    unsigned char* q;             /* output window write pointer */
    unsigned int m;               /* bytes to end of window or read pointer */
    unsigned char* f;             /* pointer to copy strings from */
    inflate_codes_state* c;       /* codes state */

    c = s->sub.decode.codes;

    /* copy input/output information to locals (UPDATE macro restores) */
    LOAD

    /* process input and output based on current state */
    while (1) {
        switch (c->mode) {
        case START:         /* x: set up for LEN */
            c->sub.code.need = c->lbits;
            c->sub.code.tree = c->ltree;
            c->mode = LEN;
        case LEN:           /* i: get length/literal/eob next */
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((unsigned int)b & inflate_mask[j]);
            DUMPBITS(t->word.what.Bits)
            e = (unsigned int)(t->word.what.Exop);
            if (e == 0) {            /* literal */
                c->sub.lit = t->base;
                c->mode = LIT;
                break;
            }
            if (e & 16) {            /* length */
                c->sub.copy.get = e & 15;
                c->len = t->base;
                c->mode = LENEXT;
                break;
            }
            if ((e & 64) == 0) {     /* next table */
                c->sub.code.need = e;
                c->sub.code.tree = ((inflate_huft*)t->base);
                break;
            }
            if (e & 32) {            /* end of block */
                c->mode = WASH;
                break;
            }
            c->mode = BADCODE;       /* invalid code */
            r = -3;
            LEAVE
        case LENEXT:        /* i: getting length extra (have base) */
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->len += (unsigned int)b & inflate_mask[j];
            DUMPBITS(j)
            c->sub.code.need = c->dbits;
            c->sub.code.tree = c->dtree;
            c->mode = DIST;
        case DIST:          /* i: get distance next */
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((unsigned int)b & inflate_mask[j]);
            DUMPBITS(t->word.what.Bits)
            e = (unsigned int)(t->word.what.Exop);
            if (e & 16) {            /* distance */
                c->sub.copy.get = e & 15;
                c->sub.copy.dist = t->base;
                c->mode = DISTEXT;
                break;
            }
            if ((e & 64) == 0) {     /* next table */
                c->sub.code.need = e;
                c->sub.code.tree = ((inflate_huft*)t->base);
                break;
            }
            c->mode = BADCODE;       /* invalid code */
            r = -3;
            LEAVE
        case DISTEXT:       /* i: getting distance extra */
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->sub.copy.dist += (unsigned int)b & inflate_mask[j];
            DUMPBITS(j)
            c->mode = COPY;
        case COPY:          /* o: copying bytes in window, waiting for space */
            f = (unsigned int)(q - s->window) < c->sub.copy.dist ?
                s->end - (c->sub.copy.dist - (unsigned int)(q - s->window)) :
                q - c->sub.copy.dist;
            while (c->len) {
                NEEDOUT
                OUTBYTE(*f++)
                if (f == s->end) {
                    f = s->window;
                }
                c->len--;
            }
            c->mode = START;
            break;
        case LIT:           /* o: got literal, waiting for output space */
            NEEDOUT
            OUTBYTE(c->sub.lit)
            c->mode = START;
            break;
        case WASH:          /* o: got eob, possibly still output waiting */
            FLUSH
            if (s->read != s->write) {
                LEAVE
            }
            c->mode = END;
        case END:
            r = 1;
            LEAVE
        case BADCODE:       /* x: got error */
            r = -3;
            LEAVE
        default:
            r = -2;
            LEAVE
        }
    }
}

int huft_build(unsigned int* b, unsigned int n, unsigned int s, unsigned int* d, unsigned int* e, register inflate_huft** t, unsigned int* m, inflate_huft* hp, unsigned int* hn, unsigned int* v) {
    unsigned int a;              /* counter for codes of length k */
    unsigned int c[16];          /* bit length count table */
    unsigned int f;              /* i repeats in table every f entries */
    int g;                       /* maximum code length */
    int h;                       /* table level */
    register unsigned int i;     /* counter, current code */
    register unsigned int j;     /* counter */
    register int k;              /* number of bits in current code */
    int l;                       /* bits per table (returned in m) */
    unsigned int mask;           /* (1 << w) - 1, to avoid cc -O bug on HP */
    register unsigned int* p;    /* pointer into c[], b[], or v[] */
    inflate_huft* q;             /* points to current table */
    struct inflate_huft r;       /* table entry for structure assignment */
    inflate_huft* u[15];         /* table stack */
    unsigned int x[16];          /* bit offsets, then code stack */
    register int w;              /* bits before this table == (l * h) */
    unsigned int* xp;            /* pointer into x */
    int y;                       /* number of dummy codes added */
    unsigned int z;              /* number of entries in current table */

    /* Generate counts for each bit length */
    p = c;
    *p++ = 0; *p++ = 0; *p++ = 0; *p++ = 0;
    *p++ = 0; *p++ = 0; *p++ = 0; *p++ = 0;
    *p++ = 0; *p++ = 0; *p++ = 0; *p++ = 0;
    *p++ = 0; *p++ = 0; *p++ = 0; *p++ = 0;
    p = b;
    i = n;
    do {
        c[*p++]++;               /* assume all entries <= BMAX */
    } while (--i);
    if (c[0] == n) {             /* null input--all zero length codes */
        *t = 0;
        *m = 0;
        return 0;
    }

    /* Find minimum and maximum length, bound *m by those */
    l = *m;
    for (j = 1; j <= 15; j++) {
        if (c[j]) {
            break;
        }
    }
    k = j;                       /* minimum code length */
    if ((unsigned int)l < j) {
        l = j;
    }
    for (i = 15; i; i--) {
        if (c[i]) {
            break;
        }
    }
    g = i;                       /* maximum code length */
    if ((unsigned int)l > i) {
        l = i;
    }
    *m = l;

    /* Adjust last length count to fill out codes, if needed */
    for (y = 1 << j; j < i; j++, y <<= 1) {
        if ((y -= c[j]) < 0) {
            return -3;
        }
    }
    if ((y -= c[i]) < 0) {
        return -3;
    }
    c[i] += y;

    /* Generate starting offsets into the value table for each length */
    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {                /* note that i == g from above */
        *xp++ = (j += *p++);
    }

    /* Make a table of values in order of bit lengths */
    p = b;
    i = 0;
    do {
        if ((j = *p++) != 0) {
            v[x[j]++] = i;
        }
    } while (++i < n);
    n = x[g];                    /* set n to length of v */

    /* Generate the Huffman codes and for each, make the table entries */
    x[0] = i = 0;                /* first Huffman code is zero */
    p = v;                       /* grab values in bit order */
    h = -1;                      /* no tables yet--level -1 */
    w = -l;                      /* bits decoded == (l * h) */
    u[0] = 0;                    /* just to keep compilers happy */
    q = 0;                       /* ditto */
    z = 0;                       /* ditto */

    /* go through the bit lengths (k already is bits in shortest code) */
    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            /* here i is the Huffman code of length k bits for value *p */
            /* make tables up to required level */
            while (k > w + l) {
                h++;
                w += l;          /* previous table always l bits */

                /* compute minimum size table less than or equal to l bits */
                z = (z = g - w) > (unsigned int)l ? l : z;   /* table size upper limit */
                if ((f = 1 << (j = k - w)) > a + 1) {   /* try a k-w bit table */
                    /* too few codes for k-w bit table */
                    f -= a + 1;  /* deduct codes from patterns left */
                    xp = c + k;
                    if (j < z) {
                        while (++j < z) {   /* try smaller tables up to z bits */
                            if ((f <<= 1) <= *++xp) {
                                break;      /* enough codes to use up j bits */
                            }
                            f -= *xp;       /* else deduct codes from patterns */
                        }
                    }
                }
                z = 1 << j;      /* table entries for j-bit table */

                /* allocate new table */
                if (*hn + z > 1440) {   /* (note: doesn't matter for fixed) */
                    return -4;          /* not enough memory */
                }
                u[h] = q = hp + *hn;
                *hn += z;

                /* connect to last table, if there is one */
                if (t) {
                    *t = q;      /* first table is returned result */
                    t = 0;
                }
                if (h) {
                    x[h] = i;    /* save pattern for backing up */
                    r.word.what.Bits = (unsigned char)l;   /* bits to dump before this table */
                    r.word.what.Exop = (unsigned char)j;   /* bits in this table */
                    j = i >> (w - l);
                    r.base = (unsigned int)q;   /* pointer to this table */
                    u[h-1][j] = r;   /* connect to last table */
                }
            }

            /* set up table entry in r */
            r.word.what.Bits = (unsigned char)(k - w);
            if (p >= v + n) {
                r.word.what.Exop = 128 + 64;   /* out of values--invalid code */
            } else if (*p < s) {
                r.word.what.Exop = (unsigned char)(*p < 256 ? 0 : 32 + 64);   /* 256 is end-of-block */
                r.base = *p++;   /* simple code is just the value */
            } else {
                r.word.what.Exop = (unsigned char)(e[*p - s] + 16 + 64);   /* non-simple--look up in lists */
                r.base = d[*p++ - s];
            }

            /* fill code-like entries with r */
            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f) {
                q[j] = r;
            }

            /* backwards increment the k-bit code i */
            for (j = 1 << (k - 1); i & j; j >>= 1) {
                i ^= j;
            }
            i ^= j;

            /* backup over finished tables */
            mask = (1 << w) - 1;   /* needed on HP, cc -O bug */
            while ((i & mask) != x[h]) {
                h--;             /* don't need to update q */
                w -= l;
                mask = (1 << w) - 1;
            }
        }
    }

    /* Return -3 if we were given an incomplete table */
    return y != 0 && g != 1 ? -5 : 0;
}

extern unsigned int D_801DC830[];

int inflate_trees_bits(unsigned int* c, unsigned int* bb, inflate_huft** tb, inflate_huft* hp, z_stream* z) {
    unsigned int hn;

    hn = 0;
    return huft_build(c, 19, 19, 0, 0, tb, bb, hp, &hn, D_801DC830);
}

extern unsigned int inflate_cplens[];
extern unsigned int inflate_cplext[];
extern unsigned int inflate_cpdist[];
extern unsigned int inflate_cpdext[];

int inflate_trees_dynamic(unsigned int nl, unsigned int nd, unsigned int* c, unsigned int* bl, unsigned int* bd, inflate_huft** tl, inflate_huft** td, inflate_huft* hp, z_stream* z) {
    int r;
    unsigned int hn;

    hn = 0;

    /* build literal/length tree */
    r = huft_build(c, nl, 257, inflate_cplens, inflate_cplext, tl, bl, hp, &hn, D_801DC830);
    if (r != 0 || *bl == 0) {
        return r;
    }

    /* build distance tree */
    return huft_build(c + nl, nd, 0, inflate_cpdist, inflate_cpdext, td, bd, hp, &hn, D_801DC830);
}

extern int inflate_fixed_built;
extern unsigned int inflate_fixed_bl;
extern unsigned int inflate_fixed_bd;
extern inflate_huft* inflate_fixed_tl;
extern inflate_huft* inflate_fixed_td;
extern unsigned int inflate_huff_build_length_list[];
extern inflate_huft D_801DCCF0[];

int inflate_trees_fixed(unsigned int* bl, unsigned int* bd, inflate_huft** tl, inflate_huft** td, z_stream* z) {
    /* build fixed tables if not already (multiple overlapped executions ok) */
    if (!inflate_fixed_built) {
        int k;               /* temporary variable */
        unsigned int f;      /* number of hufts used in fixed_mem */

        f = 0;

        /* literal table */
        for (k = 0; k < 144; k++) {
            inflate_huff_build_length_list[k] = 8;
        }
        for (k = 144; k < 256; k++) {
            inflate_huff_build_length_list[k] = 9;
        }
        for (; k < 280; k++) {
            inflate_huff_build_length_list[k] = 7;
        }
        for (; k < 288; k++) {
            inflate_huff_build_length_list[k] = 8;
        }
        inflate_fixed_bl = 7;
        huft_build(inflate_huff_build_length_list, 288, 257, inflate_cplens, inflate_cplext, &inflate_fixed_tl, &inflate_fixed_bl, D_801DCCF0, &f, D_801DC830);

        /* distance table */
        for (k = 0; k < 30; k++) {
            inflate_huff_build_length_list[k] = 5;
        }
        inflate_fixed_bd = 5;
        huft_build(inflate_huff_build_length_list, 30, 0, inflate_cpdist, inflate_cpdext, &inflate_fixed_td, &inflate_fixed_bd, D_801DCCF0, &f, D_801DC830);

        /* done */
        inflate_fixed_built = 1;
    }
    *bl = inflate_fixed_bl;
    *bd = inflate_fixed_bd;
    *tl = inflate_fixed_tl;
    *td = inflate_fixed_td;
    return 0;
}
