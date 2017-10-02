#include <stdio.h>
#include <limits.h>

enum
{
    GIDSIZE = 32
}

int
main(void)
{
    unsigned uid;
    unsigned gid[GIDSIZE];

    scanf("%u", &uid);

    char **buf;
    getline(buf, LINEMAX, stdin);
    while (*buf, sscanf("%u"))


    return 0;
}