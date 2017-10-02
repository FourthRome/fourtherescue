#include <stdio.h>

enum
{
    POWER = 8,
    MASK = 0x00FFFFFF
};

int
main(void)
{
    unsigned temp;
    while (scanf("%u", &temp) == 1) {
        int res = 0;
        unsigned gap = MASK;
        for (int i = 0; i <= POWER; i++) {
            if ((temp & ~gap) == 0) {
                res = 1;
                break;
            }
            gap <<= 1;
        }
        printf("%d\n", res);
    }
    return 0;
}