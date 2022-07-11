//
// Created by sajith on 7/10/22.
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
    const char *hostname = "time.nist.gov";
    const char *servname = "daytime";

    addrinfo hints;
    addrinfo *host;
    int r;
    int sockfd;

    const int buffer_size = 1024;
    char buffer[buffer_size];

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    r = getaddrinfo(hostname, servname, &hints, &host);
    if (r != 0)
    {
        perror("time client");
        return 1;
    }

    sockfd = socket(host->ai_family, host->ai_socktype, host->ai_protocol);
    if (sockfd == -1)
    {
        perror("time client");
        return 1;
    }

    // connect and get info
    r = connect(sockfd, host->ai_addr, host->ai_addrlen);
    if (r == -1)
    {
        perror("time client");
        return 1;
    }

    r = read(sockfd, buffer, buffer_size);
    buffer[r] = '\0';
    printf("Read %d bytes: %s\n", r, buffer);
    freeaddrinfo(host);
    close(sockfd);

    return 0;
}