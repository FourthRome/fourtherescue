#include <ctype.h>

int
mystrspccmp(const char *str1, const char *str2)
{
    for ( ; ; str1++, str2++) {
        while (isspace(*str1)) {
            str1++;
        }
        while (isspace(*str2)) {
            str2++;
        }
        int diff = *((unsigned char *) str1) - *((unsigned char *) str2);
        if (diff) {
            return diff;
        } else if (!*str1 && !*str2) {
            return 0;
        }
    }
}
