#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum
{
    BYTEVALUEBORDER = 0xFF,
    SHIFT = 8
};

int
main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    int out = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);

    unsigned short temp;
    char buf[sizeof(temp)];

    while (scanf("%hu", &temp) > 0) {
        for (int i = sizeof(temp) - 1; i >= 0; i--) {
            buf[i] = temp & BYTEVALUEBORDER;
            temp >>= SHIFT;
        }
        write(out, buf, 2);
    }

    close(out);

    return 0;
}