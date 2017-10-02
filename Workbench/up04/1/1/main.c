#include <stdio.h>

int
main(void)
{
    int n, w;
    scanf("%d%d", &n, &w);

    unsigned max = 0;
    for (int i = 0; i < n; i++) {
        max <<= 1;
        max += 1;
    }

    unsigned mask = max ^ (max >> 1);
    for (unsigned i = 0; i <= max; i++) {
        int s = (i & mask) ? -(~(i - 1) & max) : i;
        printf("|%*d|%*x|%*d|\n", w, i, w, i, w, s);
    }

    return 0;
}