#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8123
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int create_socket() {
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    return sock;
}

int connect_to_server(int sock, struct sockaddr_in *serv_addr) {
    if (connect(sock, (struct sockaddr *)serv_addr, sizeof(*serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    return 0;
}

void send_message(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    printf("Message sent\n");
}

void read_response(int sock, char *buffer) {
    ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    buffer[bytes_read] = '\0'; // Null-terminate the string
    printf("Response: %s\n", buffer);
}

int main() {
    int sock = create_socket();
    if (sock == -1) return -1;

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect_to_server(sock, &serv_addr) == -1) return -1;

    char *message = "Hello from client";
    send_message(sock, message);

    char buffer[BUFFER_SIZE] = {0};
    read_response(sock, buffer);

    return 0;
}