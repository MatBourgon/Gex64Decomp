#include "common.h"

char* proutSprintf(char* dst, char* src, int len);
int sprintf(char* str, char* format, ...) {
    char va_list[0];

    int length = _Printf(&proutSprintf, str, format, va_list + 16);
    if (length >= 0) {
        str[length] = '\0';
    }
    return length;
}

char* proutSprintf(char* dst, char* src, int len) {
    memcpy(dst, src, len);
    return &dst[len];
}
