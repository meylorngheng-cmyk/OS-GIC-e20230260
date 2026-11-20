
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9090

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    char *message = "Hello from client!";

    // 1. Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // 2. Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1",
                  &server_address.sin_addr) <= 0) {
        perror("Invalid server address");
        close(sock);
        return 1;
    }

    // 3. Connect to server
    if (connect(sock, (struct sockaddr *)&server_address,
                sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    printf("Connected to server!\n");

    // 4. Send message
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // 5. Receive reply
    read(sock, buffer, sizeof(buffer) - 1);
    printf("Server says: %s\n", buffer);

    // 6. Close socket
    close(sock);

    return 0;
}

