#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

enum { BUFSIZE = 16 };

int
main(void)
{
    char buf[BUFSIZE];
    long long sum = 0;
    int left, sign = 1, value = 0;
    bool inside = false;

    while ((left = read(0, buf, sizeof(buf))) > 0) {
        for (int i = 0; i < left; i++) {
            if (inside) {
                if (isdigit(buf[i])) {
                    value = value * 10 + buf[i] - '0';
                } else if (isspace(buf[i])) {
                    inside = false;
                    sum += value * sign;
                    value = 0;
                    sign = 1;
                } else {
                    return 1;
                }
            } else {
                if ((buf[i] == '+') || (buf[i] == '-')) {
                    sign = (buf[i] == '+') ? 1 : -1;
                    inside = true;
                } else if (isdigit(buf[i])) {
                    value = buf[i] - '0';
                    inside = true;
                }
            }
        }
    }
    if (left == -1) {
        return 1;
    }

    sum += sign * value;
    printf("%Ld\n", sum);

    return 0;
}