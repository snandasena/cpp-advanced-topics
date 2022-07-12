//
// Created by sajith on 7/12/22.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    int r;
    int sockfd;

    addrinfo hints;
    addrinfo *server;

    socklen_t client_size;
    sockaddr client;


    const int size = 1024;
    char input[size];
    char output[size];

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    r = getaddrinfo(nullptr, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    puts("UDP server is listening....");
    client_size = sizeof(sockaddr);
    while (1)
    {
        r = recvfrom(sockfd, input, size, 0, &client, &client_size);
        if (r == -1)
        {
            perror("failed");
            return 1;
        }

        input[r] = '\0';
        strcpy(output, "SERVER> ");
        strcat(output, input);

        r = sendto(sockfd, output, strlen(output), 0, &client, client_size);
        if (r == -1)
        {
            perror("failed");
            return 1;
        }
    }

    freeaddrinfo(server);
    close(sockfd);
    return 0;
}