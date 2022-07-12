//
// Created by sajith on 7/12/22.
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
    addrinfo *server;

    int r;
    int sockfd;
    int clientfd;

    sockaddr client_address;
    socklen_t client_len;

    const int size = 1024;
    char input[size];
    char output[size];

    // configure the server to use the localhost
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    r = getaddrinfo(nullptr, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    // create a socket to use for communications
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    // bind the server to a socket
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // listen for incoming connections
    printf("The TCP server is listening...\n");
    r = listen(sockfd, 1);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // accept a new connection
    client_len = sizeof(client_address);
    while (1)
    {
        clientfd = accept(sockfd, &client_address, &client_len);
        if (clientfd == -1)
        {
            perror("failed");
            return 1;
        }

        // client is now connected
        r = recv(clientfd, input, size, 0);
        if (r > 0)
        {
            input[r] = '\0';

            strcpy(output, "SERVER>");
            strcat(output, input);

            r = send(clientfd, output, strlen(output), 0);
            if (r < 1)
            {
                perror("send failed");
                return 1;
            }
        }
        close(clientfd);
    }

    freeaddrinfo(server);
    close(sockfd);
    return 0;
}