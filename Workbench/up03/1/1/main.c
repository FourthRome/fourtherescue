#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
    if (argc < 4) {
        return 1;
    }

    double res = strtod(argv[1], NULL);
    double dep = 1 + strtod(argv[2], NULL) / 100;
    double cred = 1 + strtod(argv[3], NULL) / 100;

    for (int i = 4; i < argc; i++) {
        double oper = strtod(argv[i], NULL);
        res += oper;
        if (res < 0) {
            res *= cred;
        } else {
            res *= dep;
        }
    }

    printf("%.10g\n", res);

    return 0;
}