#include <string.h>

char template[] = "rwxrwxrwx";

int
parse_rwx_permissions(const char *str)
{
    if ((str == NULL) || (strlen(str) != sizeof(template) - 1))  {
        return -1;
    }
    int res = 0;
    for (int i = sizeof(template) - 2, add = 1; i >= 0; i--, add <<= 1) {
        if (str[i] == template[i]) {
            res += add;
        } else if (str[i] != '-') {
            return -1;
        }
    }
    return res;
}