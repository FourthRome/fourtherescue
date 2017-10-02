#include <unistd.h>
#include <stdio.h>
#include <errno.h>

enum { BUFSIZE = 4096 };

void
copy_file(int in_fd, int out_fd)
{
    char buf[BUFSIZE];
    ssize_t size;
    ssize_t ret;
    while ((size = read(in_fd, buf, BUFSIZE)) > 0) {
        char *buf_p = buf;
        while (size && ((ret = write(out_fd, buf_p, size) != size))) {
            if (ret == -1) {
                perror("An error during write() occurred");
                return;
            }
            size -= ret;
            buf_p += ret;
        }
    }
}
