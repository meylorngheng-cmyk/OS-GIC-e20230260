#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char fullpath[PATH_MAX];

        int len = snprintf(fullpath, sizeof(fullpath), "%s/%s",
                           path, entry->d_name);
        if (len < 0 || (size_t)len >= sizeof(fullpath)) {
            fprintf(stderr, "Path too long: %s\n", entry->d_name);
            continue;
        }

        struct stat info;
        if (stat(fullpath, &info) == -1) {
            perror(fullpath);
            continue;
        }

        const char *type = S_ISDIR(info.st_mode) ? "Directory" :
                           S_ISREG(info.st_mode) ? "File" : "Other";

        printf("%-30s %10ld bytes  %s\n",
               entry->d_name, (long)info.st_size, type);
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        return 1;
    }

    return 0;
}
