//
// Created by sajith on 7/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    struct addrinfo hints, *server;
    int r, sockfd, clientfd;
    struct sockaddr client_address;
    socklen_t client_len;
    const char *hello = "Hello, client!\nYou sent me: ";
    const int buffer_size = 1024;
    char buffer[buffer_size];

    /* configure the server to use the localhost, port 8080, TCP */
    memset(&hints, 0, sizeof(struct addrinfo));    /* use memset_s() */
    hints.ai_family = AF_INET;            /* IPv4 connection */
    hints.ai_socktype = SOCK_STREAM;    /* TCP, streaming */
    r = getaddrinfo(0, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        exit(1);
    }

    /* create the socket to use for communications */
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        exit(1);
    }

    /* bind the server to a socket */
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }

    /* listen for incoming connections */
    r = listen(sockfd, 1);
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }

    /* accept a new connection */
    client_len = sizeof(client_address);
    clientfd = accept(sockfd, &client_address, &client_len);
    if (clientfd == -1)
    {
        perror("failed");
        exit(1);
    }

    /* client is now connected */
    /* receive a chunk of text from the client */
    r = recv(clientfd, buffer, buffer_size, 0);
    /* zero==disconnected, so process any incoming text */
    if (r > 0)
    {
        buffer[r] = '\0';            /* terminate the incoming string */
        /* error-checking isn't done here */
        send(clientfd, hello, strlen(hello), 0);        /* send the hello string */
        send(clientfd, buffer, strlen(buffer), 0);    /* send back the client string */
    }

    /* close-up */
    freeaddrinfo(server);
    close(clientfd);
    close(sockfd);
    return (0);
}