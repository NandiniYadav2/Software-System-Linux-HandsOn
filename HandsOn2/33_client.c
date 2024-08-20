/*
============================================================================
Name : 33_client.c
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
#define SERVER_IP "127.0.0.1" // Replace with the server's IP address

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[] = "Hello from the client!";

    // Create the client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Connected to the server.\n");
    } else {
        perror("Connection error");
        exit(1);
    }

    // Send a message to the server
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    close(client_socket);

    return 0;
}

