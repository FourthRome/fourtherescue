#include <stdio.h>
#include <stdlib.h>

enum { MAXSIZE = 16384 };

typedef struct Pair
{
    double first;
    int second;
    int num;
} Pair;

int
compar(const void *p1, const void *p2)
{
    const Pair *a = (Pair *) p1;
    const Pair *b = (Pair *) p2;
    
    if (a->first < b->first) {
        return -1;
    } else if (a->first > b->first) {
        return 1;
    } else {
        return a->num - b->num;
    }
}


int
main(void)
{
    Pair arr[MAXSIZE];
    int size = 0;

    double first_buf;
    int second_buf;

    while (scanf("%lf%d", &first_buf, &second_buf) == 2) {
        arr[size] = (Pair)
        {
            .first = first_buf,
            .second = second_buf,
            .num = size
        };
        size++;
    }

    if (size) {
        qsort(arr, size, sizeof(*arr), compar);

        for (int i = 0; i < size; i++) {
            printf("%.10g %d\n", arr[i].first, arr[i].second);
        }
    }

    return 0;
}