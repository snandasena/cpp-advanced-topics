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

    addrinfo hints;
    addrinfo *server;
    int r;
    int sockfd;
    int clientfd;
    int option;

    sockaddr client_address;
    socklen_t client_len;
    const int buff_size = 1024;
    char buffer[buff_size];
    const char *http_data =
            "HTTP/1.1 200 OK\r\n"
            "Connection: close\r\n"
            "Content-Type: text/html\r\n\r\n"
            "<h1>Hello from your server!</h1>";

    printf("Configuring server....\n");
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    r = getaddrinfo(nullptr, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    // assign a socket
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    // activate dual stack configuration
    option = 0;
    r = setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, (void *) &option, sizeof(option));
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // Bind the server to a socket
    printf("Binding socket....\n");
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    // listen for incoming connections
    printf("listening....\n");

    r = listen(sockfd, 1);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    // accept the new connection
    client_len = sizeof(client_address);
    clientfd = accept(sockfd, &client_address, &client_len);
    if (clientfd == -1)
    {
        perror("failed");
        return 1;
    }

    printf("on file descriptor %d\n", clientfd);

    //client is now connected
    r = recv(clientfd, buffer, buff_size, 0);
    if (r > 0)
    {
        printf("Received %d bytes:\n---\n", r);
        for (int i = 0; i < r; ++i)
        {
            putchar(buffer[i]);
        }
    }

    // send the response
    r = send(clientfd, http_data, strlen(http_data), 0);
    if (r < 1)
    {
        perror("failed");
        return 1;
    }

    printf("sent %d bytes\n", r);
    close(clientfd);
    freeaddrinfo(server);
    close(sockfd);
    return 0;
}