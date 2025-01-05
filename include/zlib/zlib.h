#ifndef ZLIB_H_
#define ZLIB_H_

typedef struct
{
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    struct internal_state *state;
    void* zalloc;
    void* zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

int inflate(z_stream* z, int compressedDataStart, int compressedDataSize);

#endif