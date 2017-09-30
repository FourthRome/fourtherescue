#include <stdio.h> 
#include <stdlib.h>

char template[] = "rwxrwxrwx";

int
main(int argc, char *argv[])
{
    char res[sizeof(template)];
    for (int i = 1; i < argc; i++) {
        unsigned perm = ~strtoul(argv[i], NULL, 8) & 0777;
        for (int k = 0; k < sizeof(template); k++) {
            res[k] = template[k];
        }
        for (int ind = sizeof(template) - 2; perm; ind--, perm >>= 1) {
            if (perm & 1) {
                res[ind] = '-';
            }
        }
        printf("%s\n", res);
    }

    return 0;
}