//
// Created by sajith on 7/8/22.
//


#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

int main()
{

    addrinfo hints;
    addrinfo *server;
    int r;
    int sockfd;

    printf("configuring host....\n");
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    r = getaddrinfo("google.com", "80", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 0;
    }

    puts("done");
    printf("assign a socket\n");
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);

    if (sockfd == -1)
    {
        printf("failed");
        return 0;
    }

    puts("done");
    printf("connecting socket...\n");

    r = connect(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 0;
    }

    puts("done");
    freeaddrinfo(server);
    close(sockfd);
    puts("socket  close, done");
    return 0;

}