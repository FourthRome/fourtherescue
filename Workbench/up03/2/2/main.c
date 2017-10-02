#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

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
        buf[1] = temp;
        buf[0] = temp >> CHAR_BIT;
        write(out, buf, sizeof(buf));
    }

    close(out);

    return 0;
}