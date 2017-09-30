#include <ctype.h>

int
mystrspccmp(const char *str1, const char *str2)
{
    for (;;) {
        while (isspace(*str1)) {
            str1++;
        }
        while (isspace(*str2)) {
            str2++;
        }

        int res = *((unsigned char *) str1) - *((unsigned char *) str2);

        if (res) {
            return res;
        } else if (*str1) {
            str1++;
            str2++;
        } else {
            return 0;
        }
    }
}
