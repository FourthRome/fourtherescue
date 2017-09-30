#include <stdint.h>

uint32_t TOP = ~(uint32_t) 0 >> 1;
uint32_t DOWN = ~(~(uint32_t) 0 >> 1);

int32_t
satsum(int32_t v1, int32_t v2)
{
    int32_t res;
    if (!__builtin_add_overflow(v1, v2, &res)) {
        return res;
    } else if (v1 < 0) {
        return DOWN;
    } else {
        return TOP;
    }
}
