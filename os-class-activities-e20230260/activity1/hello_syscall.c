#include <unistd.h>
#include <string.h>

int main(void) {
    const char message[] = "Hello, system calls!\n";
    write(STDOUT_FILENO, message, strlen(message));
    return 0;
}
