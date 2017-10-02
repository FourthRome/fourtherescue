#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

enum { BUFSIZE = 16 };

int
main(void)
{
    char buf[BUFSIZE];
    long long res = 0;
    int len, num = 0, innum = 0, sign = 1;
    errno = 0;

    while ((len = read(0, buf, sizeof(buf))) > 0) {
        if (errno) {
            perror("Read failed somewhere!");
            return 1;
        }

        for (int i = 0; i < len; i++) {
            if (innum) {
                if (isdigit(buf[i])) {
                    num = num * 10 + buf[i] - '0';
                } else if (isspace(buf[i])) {
                    res += num * sign;
                    num = 0;
                    sign = 1;
                    innum = 0;
                } else {
                    fprintf(stderr, "Invalid input!\n");
                    return 1;
                }
            } else {
                if ((buf[i] == '-') || (buf[i] == '+')) {
                    sign = (buf[i] == '-') ? -1 : 1;
                    innum = 1;
                } else if (isdigit(buf[i])) {
                    num = buf[i] - '0';
                    innum = 1;
                } else if (!isspace(buf[i])) {
                    fprintf(stderr, "Invalid input!\n");
                    return -1;
                }
            }
        }
    }
    
    if (errno) {
        perror("Read failed somewhere!");
        return 1;
    }

    if (num) {
        res += num * sign;
    }

    printf("%Ld\n", res);

    return 0;
}