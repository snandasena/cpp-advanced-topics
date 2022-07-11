//
// Created by sajith on 7/11/22.
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

    int r;
    int sockdf;
    addrinfo hints;
    addrinfo *host;

    const char *hello = "Hello, TCP Server!\n";
    const int buff_size = 1024;
    char buffer[buff_size];

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    r = getaddrinfo(nullptr, "8080", &hints, &host);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    // create a socket
    sockdf = socket(host->ai_family, host->ai_socktype, host->ai_protocol);
    if (sockdf == -1)
    {
        perror("failed");
        return 1;
    }

    // connect and get the info
    r = connect(sockdf, host->ai_addr, host->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // send something to say hello
    r = send(sockdf, hello, strlen(hello), 0);

    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    r = recv(sockdf, buffer, buff_size, 0);
    buffer[r] = '\0';
    printf("%s\n", buffer);
    freeaddrinfo(host);
    close(sockdf);
    return 0;

}
