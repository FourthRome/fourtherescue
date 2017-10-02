#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        char buf;
        errno = 0;
        unsigned long num = strtoul(argv[i], &buf, 10);
        if ((argv[i][0] != '\0') && (buf == '\0')) {
            
        }
        
        if () {
            printf("%lu\n", ceil(log2((double) val + 1)));
        } else {
            printf("-1\n");
        }
    }

    return 0;
}