#include "common.h"

char* strncpy_ret_end(char* dst, char* src, int len);
int csprintf(char* str, char* format, ...) {
    char va_list[0];

    int length = func_80065900(&strncpy_ret_end, str, format, va_list + 16);
    if (length >= 0) {
        str[length] = '\0';
    }
    return length;
}

char* strncpy_ret_end(char* dst, char* src, int len) {
    cstrncpy(dst, src, len);
    return &dst[len];
}
