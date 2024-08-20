/*
============================================================================
Name : 34_b.c
Author : Nandini Yadav
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 4 nov, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void *newThread(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            pthread_exit(NULL);
        }

        buffer[bytes_received] = '\0';
        printf("Received message: %s", buffer);

        // Process the client's request here

        // Send a response (echo the received message back to the client)
        send(client_socket, buffer, bytes_received, 0);
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == 0) {
        printf("Listening...\n");
    } else {
        perror("Listening error");
        exit(1);
    }

    while (1) {
        // Accept a connection from a client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Accept error");
            continue;
        }

        // Create a new thread for new client
        pthread_t thread;
        int *client_socket_ptr = (int *)malloc(sizeof(int));
        if (client_socket_ptr == NULL) {
            perror("Thread creation error");
            close(client_socket);
            continue;
        }

        *client_socket_ptr = client_socket;

        if (pthread_create(&thread, NULL, newThread, (void *)client_socket_ptr) != 0) {
            perror("Thread creation error");
            close(client_socket);
            free(client_socket_ptr);
        } 
    }

    close(server_socket);

    return 0;
}

