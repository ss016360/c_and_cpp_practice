#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8123
#define BUFFER_SIZE 1024

void setup_server(int *server_fd, struct sockaddr_in *address) {
    int opt = 1;

    // Create socket
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);

    // Bind socket
    if (bind(*server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(*server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void handle_request(int new_socket) {
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Hello from server";

    // Read request
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Request: %s\n", buffer);

    // Send response
    send(new_socket, message, strlen(message), 0);
    printf("Response sent\n");
}

void accept_and_handle_requests(int server_fd, struct sockaddr_in *address) {
    int new_socket;
    int addrlen = sizeof(*address);

    // Accept connections and handle requests
    while (1) {
        printf("\nWaiting for a connection...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_request(new_socket);
    }
}

int main() {
    int server_fd;
    struct sockaddr_in address;

    setup_server(&server_fd, &address);
    accept_and_handle_requests(server_fd, &address);

    return 0;
}