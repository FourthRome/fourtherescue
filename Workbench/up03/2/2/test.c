#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

enum { PARAMNUM = 2 };

int
main(int argc, char *argv[])
{
    if (argc != PARAMNUM) {
        return 1;
    }

    int output = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (output == -1) {
        return 1;
    }
    
    unsigned short tmp;
    char buff[sizeof(tmp)];

    while (scanf("%hu", &tmp) > 0) {
        buff[0] = tmp >> CHAR_BIT;
        buff[1] = tmp;
        write(output, buff, sizeof(buff));
    }

    close(output);
    return 0;
}