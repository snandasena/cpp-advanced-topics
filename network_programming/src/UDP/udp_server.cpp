//
// Created by sajith on 7/11/22.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    addrinfo hints;
    addrinfo *server;

    sockaddr client;
    socklen_t client_size;

    int r, sockfd;
    const char *buffer = "UDP Server says \"Hello!\"\n";
    const int size = 1024;
    char input[size];

    memset(&hints, 0, sizeof(hints));
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

    puts("UDP server is listening...\n");

    client_size = sizeof(sockaddr);
    r = recvfrom(sockfd, input, size, 0, &client, &client_size);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    r = sendto(sockfd, buffer, strlen(buffer), 0, &client, client_size);

    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    freeaddrinfo(server);
    close(sockfd);
    return 0;
}