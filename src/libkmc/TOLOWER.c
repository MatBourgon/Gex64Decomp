#include <CTYPE.h>

tolower(c)
int c;
{
    return (isupper(c) ? _tolower(c) : c);
}