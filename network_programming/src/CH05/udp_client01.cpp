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
    addrinfo hints;
    addrinfo *host;

    int r;
    int sockfd;
    const int size = 1024;
    char input[size];
    char buffer[size];

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

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

    printf("Type something: ");
    fgets(input, size, stdin);
    for (auto &item: input)
    {
        if (item == '\n')
        {
            item = '\0';
        }
    }

    r = sendto(sockfd, input, strlen(input), 0, host->ai_addr, host->ai_addrlen);

    r = recvfrom(sockfd, buffer, size, 0, host->ai_addr, &host->ai_addrlen);
    buffer[r] = '\0';
    printf("%s\n", buffer);

    freeaddrinfo(host);
    close(sockfd);
    return 0;
}