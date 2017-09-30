void
normalize_path(char *buf)
{
    char *p = buf;
    int found = 0;
    for (; *buf; buf++) {
        if (*buf == '/') {
            if (found) {
                continue;
            } else {
                found = 1;
            }
        } else if (found) {
            found = 0;
        }
        *p = *buf;
        p++;
    }
    *p = '\0';
}