#include <stdio.h>

int
bitcount(STYPE value)
{
    UTYPE sample = (UTYPE) value;
    int res = 0;

    while (sample) {
        res += sample & 1;
        sample >>= 1;
    }

    return res;
}