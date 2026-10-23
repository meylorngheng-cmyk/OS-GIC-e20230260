#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *filename = "created_by_syscall.txt";
    const char *message = "This file was created using open() and write().\n";

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    size_t len = strlen(message);
    ssize_t n = write(fd, message, len);
    if (n == -1 || (size_t)n != len) {
        perror("write");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    printf("Created %s successfully.\n", filename);
    return 0;
}
