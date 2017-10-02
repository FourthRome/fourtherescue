#include <stdio.h>
#include <stdlib.h>

enum { MAXAMOUNT = 16384 };

typedef struct Pair
{
    double a;
    int b;
    int idx;
} Pair;

int
my_cmp(const void *ptr1, const void *ptr2)
{
    const Pair *p1 = (Pair *) ptr1;
    const Pair *p2 = (Pair *) ptr2;
    
    if (p1->a > p2->a) {
        return 1;
    } else if (p1->a < p2->a) {
        return -1;
    } else {
        return p1->idx - p2->idx;
    }
}

int
main(void)
{
    Pair array[MAXAMOUNT];
    int len = 0;

    double tmp_a;
    int tmp_b;

    while (scanf("%lf%d", &tmp_a, &tmp_b) == 2) {
        array[len++] = (Pair)
        {
            .a = tmp_a,
            .b = tmp_b,
            .idx = len
        };
    }

    qsort(array, len, sizeof(*array), my_cmp);
    for (int i = 0; i < len; i++) {
        printf("%.10g %d\n", array[i].a, array[i].b);
    }

    return 0;
}