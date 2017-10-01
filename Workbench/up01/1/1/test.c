#include <stdio.h>

int
bitcount(STYPE value)
{
    int count = 0;
    UTYPE left = (UTYPE) value;
    while (left) {
        count += left & 1;
        sample >>= 1;
    }
    return count;
}