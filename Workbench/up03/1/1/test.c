#include <stdio.h>
#include <stdlib.h>

enum { PARAMNUM = 4 };

int
main(int argc, char *argv[])
{
    if (argc < PARAMNUM) {
        return 1;
    }

    double sum = strtod(argv[1], NULL);
    double dep = strtod(argv[2], NULL) / 100 + 1;
    double cred = strtod(argv[3], NULL) / 100 + 1;

    for (int i = PARAMNUM; i < argc; i++) {
        sum += strtod(argv[i], NULL);
        sum *= (sum > 0) ? dep : cred;
    }

    printf("%.10g\n", sum);
    return 0;
}