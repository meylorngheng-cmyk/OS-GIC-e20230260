#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        const char usage[] = "Usage: copyfilesyscall source destination\n";
        write(STDERR_FILENO, usage, sizeof(usage) - 1);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open source");
        return 1;
    }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst == -1) {
        perror("open destination");
        close(src);
        return 1;
    }

    char buffer[4096];
    ssize_t n;

    while ((n = read(src, buffer, sizeof(buffer))) > 0) {
        ssize_t written = 0;
        while (written < n) {
            ssize_t w = write(dst, buffer + written, (size_t)(n - written));
            if (w == -1) {
                perror("write");
                close(src);
                close(dst);
                return 1;
            }
            written += w;
        }
    }

    if (n == -1) {
        perror("read");
        close(src);
        close(dst);
        return 1;
    }

    close(src);
    close(dst);
    return 0;
}
