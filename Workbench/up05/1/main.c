#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        printf("0\n");
        return 1;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s", argv[1]);
    int rootlen = strlen(path);
    if (path[rootlen - 1] != '/') {
        path[rootlen++] = '/';
        path[rootlen] = '\0';
    }

    uid_t uid = getuid();
    long long res = 0;
    struct dirent *file;
    struct stat info;
    while ((file = readdir(dir))) {
        if (isupper(file->d_name[0])) {
            snprintf(path + rootlen, sizeof(path) - rootlen, "%s", file->d_name);
            if (!stat(path, &info)) {
                if (((info.st_mode & S_IFMT) == S_IFREG) && (info.st_uid == uid)) {
                    res += info.st_size;
                }
            }
        }
    }
    closedir(dir);
    
    printf("%Ld\n", res);

    return 0;
}