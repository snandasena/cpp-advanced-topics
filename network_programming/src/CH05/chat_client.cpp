//
// Created by sajith on 7/13/22.
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
    const char *port = "65001";
    addrinfo hints;
    addrinfo *server;

    int r;
    int sockfd;
    char buffer[BUFSIZ];
    fd_set read_fd;

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    r = getaddrinfo(nullptr, port, &hints, &server);

    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == 1)
    {
        perror("failed");
        return 1;
    }

    r = connect(sockfd, server->ai_addr, server->ai_addrlen);
    freeaddrinfo(server);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    bool done = false;

    while (!done)
    {
        FD_ZERO(&read_fd);
        FD_SET(sockfd, &read_fd);

        FD_SET(0, &read_fd);
        r = select(sockfd + 1, &read_fd, nullptr, nullptr, 0);
        if (r == -1)
        {
            perror("failed");
            return 1;
        }

        if (FD_ISSET(sockfd, &read_fd))
        {
            r = recv(sockfd, buffer, BUFSIZ, 0);
            if (r < 1)
            {
                puts("Connection closed by peer");
                break;
            }

            buffer[r] = '\0';
            printf("%s", buffer);
        }

        if (FD_ISSET(0, &read_fd))
        {

            if (fgets(buffer, BUFSIZ, stdin) == nullptr)
            {
                putchar('\n');
            }
            else if (strcmp(buffer, "close\n") == 0)
            {
                done = true;
            }
            else
            {
                send(sockfd, buffer, strlen(buffer), 0);
            }
        }
    }
    printf("Disconnected\nBye!\n");
    close(sockfd);
    return 0;
}