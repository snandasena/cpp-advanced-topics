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

using namespace std;

int main()
{
    int r;
    int sockfd;

    addrinfo hints;
    addrinfo *host;
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    const int buff_size = 1024;
    char buffer[buff_size];
    r = getaddrinfo(nullptr, "8080", &hints, &host);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    sockfd = socket(host->ai_family, host->ai_socktype, host->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    r = connect(sockfd, host->ai_addr, host->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    printf("Type something: ");
    fgets(buffer, buff_size, stdin);
    /* remove the newline */
    for (int x = 0; x < buff_size; x++)
    {
        if (buffer[x] == '\n')
        {
            buffer[x] = '\0';
            break;
        }
    }
    r = send(sockfd, buffer, strlen(buffer), 0);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    r = recv(sockfd, buffer, 1024, 0);
    buffer[r] = '\0';
    printf("Read %d bytes: %s\n", r, buffer);

    freeaddrinfo(host);
    close(sockfd);
    return 0;
}