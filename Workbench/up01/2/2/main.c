#include <stdio.h>

enum
{
    MASK = 0x00FFFFFF,
    ITERS = 9
};

int
check_num(unsigned int num)
{
    unsigned mask = MASK;
    for (int i = 0; i < ITERS; ++i) {
        if (!(num & ~mask)) {
            return 1;
        }
        mask <<= 1;
    }
    return 0;
}

int
main(void)
{
    unsigned num;
    while (scanf("%u", &num) == 1) {
        printf("%d\n", check_num(num));
    }
    return 0;
}