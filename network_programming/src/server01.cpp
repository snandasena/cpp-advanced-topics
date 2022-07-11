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

    sockaddr client_address;
    socklen_t client_len;
    const int buffer_size = 1024;
    char buffer[buffer_size];
    const char *http_data =
            "HTTP/1.1 200 OK\r\n"
            "Connection: close\r\n"
            "Content-Type: text/html\r\n\r\n"
            "<h1>Hello from your server!</h1>";

    // configure the server to use the localhost, port 8080, TCP
    printf("Configuring server ...\n");
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    r = getaddrinfo(nullptr, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    printf("assign a socket...\n");
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    printf("Binding socket...\n");
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    puts("done");

    printf("Listening...\n");
    r = listen(sockfd, 1);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    printf("Accepting new connection ");
    client_len = sizeof(client_address);
    clientfd = accept(sockfd, &client_address, &client_len);
    if (clientfd == -1)
    {
        perror("failed");
        return 1;
    }
    printf("on file descriptor %d\n", clientfd);

    // client is now connected
    r = recv(clientfd, buffer, buffer_size, 0);
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
        perror("send failed");
        return 1;
    }

    printf("Sent %d bytes\n", r);

    close(clientfd);
    freeaddrinfo(server);
    close(sockfd);
    return 0;
}