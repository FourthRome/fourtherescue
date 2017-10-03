#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

enum
{
    BUFSIZE = 16,
    MAXNAMELEN = 256
};

void
walkthrough (char *path, int pathlen, int pathmax, char *print) {
    DIR *dir = opendir(path);
    if (!dir) {
        return;
    }

    if (print) {
        printf("cd %s\n", print);
    }

    char (*buf)[MAXNAMELEN];
    int bufsize = BUFSIZE;
    int used = 0;
    buf = calloc(bufsize, sizeof(*buf));

    struct dirent *file;
    struct stat info;
    while ((file = readdir(dir))) {
        if (strcmp(file->d_name, ".") && strcmp(file->d_name, "..")) {
            snprintf(path + pathlen, pathmax - pathlen, "%s", file->d_name);
            if (!lstat(path, &info) && ((info.st_mode & S_IFMT) == S_IFDIR)) {
                if (used == bufsize) {
                    bufsize <<= 1;
                    if (!realloc(buf, bufsize * sizeof(*buf))) {
                        free(buf);
                        return;
                    }
                }
                snprintf((char *) (buf + used), sizeof(*buf), "%s", file->d_name);
                used++;
            }
        }

    }
    closedir(dir);

    qsort(buf, used, sizeof(*buf), (int (*) (const void *, const void *)) strcmp);

    for (int i = 0; i < used; i++) {
        snprintf(path + pathlen, pathmax - pathlen, "%s/", buf[i]);
        walkthrough(path, strlen(path), pathmax, buf[i]);
    }

    free(buf);

    path[pathlen] = '\0';
    if (print) {
        printf("cd ..\n");
    }
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    DIR *root = opendir(argv[1]);
    if (!root) {
        return 1;
    }

    char path[PATH_MAX];
    memset(path, 0, sizeof(path));
    snprintf(path, sizeof(path), "%s", argv[1]);
    int pathlen = strlen(path);
    if (path[pathlen - 1] != '/') {
        path[pathlen++] = '/';
    }

    walkthrough(path, pathlen, sizeof(path), NULL);

    closedir(root);
    return 0;
}