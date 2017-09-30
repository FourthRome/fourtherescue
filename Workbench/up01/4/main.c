#include <stdio.h>

enum
{ 
    MAXNAMELEN = 61,
    NUMBERS = 10
};

int
main(void)
{
    char path[MAXNAMELEN + 1];
    path[0] = '\0';

    int values[NUMBERS];
    for (int i = 0; i < NUMBERS; i++) {
        values[i] = 0;
    }

    int c, i;
    for (i = 0; ((c = getchar()) != EOF) && (c != '\r') && (c != '\n'); i++) {
        if (i >= MAXNAMELEN) {
            path[0] = '\0';
            break;
        } else {
            path[i] = c;
        }
    }
    path[i] = '\0';

    FILE *input;
    if ((input = fopen(path, "r"))) {
        while ((c = getc(input)) != EOF) {
            int val = c - '0';
            if ((val >= 0) && (val <= 9)) {
                values[val]++;
            }
        }
        fclose(input);
    }

    for (i = 0; i < NUMBERS; i++) {
        printf("%d %d\n", i, values[i]);
    }

    return 0;
}