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
    addrinfo *host;
    const int size = 1024;
    char buffer[size];

    int r;
    int sockfd;

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

    r = sendto(sockfd, "\n", 1, 0, host->ai_addr, host->ai_addrlen);
    r = recvfrom(sockfd, buffer, size, 0, host->ai_addr, &host->ai_addrlen);

    buffer[r] = '\0';
    printf("%s", buffer);

    freeaddrinfo(host);
    close(sockfd);

    return 0;
}