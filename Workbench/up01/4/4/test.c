#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum
{ 
    NUMBERS = 10,
    MAXNAME = 61
};

int
main(void)
{
    char filename[MAXNAME + 1];
    memset(filename, 0, sizeof(filename));        
    int counts[NUMBERS];
    memset(counts, 0, sizeof(counts));
    int c;

    for (int i = 0; ((c = getchar()) != EOF) && (c != '\r') && (c != '\n'); i++) {
        if (i >= MAXNAME) {
            filename[0] = '\0';
            break;
        }
        filename[i] = c;
    }

    FILE *file;
    if ((filename[0]) && (file = fopen(filename, "r"))) {
        while ((c = getc(file)) != EOF) {
            if (isdigit(c)) {
                counts[c - '0']++;
            }
        }
        fclose(file);
    }

    for (int i = 0; i < NUMBERS; i++) {
        printf("%d %d\n", i, counts[i]);
    }

    return 0;
}