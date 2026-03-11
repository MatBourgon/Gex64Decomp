#include "common.h"

char* memset(char* dst, int data, unsigned int count) {
    short* shortDst;
    int byteCount;

    if (count != 0) {
        
        data &= 0xff;
        data |= data << 8;
        data |= data << 16;
        
        shortDst = (short*)dst;
        if ((unsigned int)dst & 1) {
            *dst = data;
            shortDst = (short*)(dst + 1);
            count -= 1;
        }
        
        if (count >= 2) {
            if (((int)shortDst) & 2) {
                *shortDst++ = data;
                count -= 2;
            }
        }
        
        byteCount = (count >> 2);
        byteCount--;
        
        if (byteCount != -1) {
            do {
                *((int*)shortDst) = data;
                byteCount -= 1;
                shortDst += 2;
            } while (byteCount != -1);
        }
        
        if (count & 2) {
            *shortDst = data;
            shortDst += 1;
        }
        
        if (count & 1) {
            *((char*)shortDst) = data;
        }
        
    }
    return dst;
}

char* setmem(char* dst, int data, unsigned int count) {
    return memset(dst, count, data);
}
