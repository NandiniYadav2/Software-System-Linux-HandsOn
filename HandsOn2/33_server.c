/*
============================================================================
Name : 33_server.c
Author : Nandini Yadav
Description : Write a program to communicate between two machines using socket. 
Date: 14th oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {

    int server_socket, new_socket;
    
    struct sockaddr_in server_addr, new_addr;
    
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) ==-1 ) {
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 15) == 0) {
        printf("Listening...\n");
    } else {
        perror("Listening error");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size); // Accept a connection

    // Receive data from the client
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Received message: %s\n", buffer);

    close(new_socket);
    close(server_socket);

    return 0;
}

