#include <stdio.h>
#include <unistd.h>

enum { BUFSIZE = 4096 };

void
copy_file(int in_fd, int out_fd)
{
    char buf[BUFSIZE];
    ssize_t left, written;
    char *p = buf;

    while ((left = read(in_fd, buf, sizeof(buf))) > 0) {
        for (; left > 0; left -= written, p += written) {
            written = write(out_fd, p, left);
            if (written == -1) {
                return;
            }
        }
    }
}