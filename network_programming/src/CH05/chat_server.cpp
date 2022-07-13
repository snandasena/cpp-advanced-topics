//
// Created by sajith on 7/13/22.
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
    const char *port = "65001";
    const int clientname_size = 32;
    char clientname[clientname_size];
    char buffer[BUFSIZ];
    char sendstr[BUFSIZ];

    const int backlog = 10;
    char connection[backlog][clientname_size];
    socklen_t address_len = sizeof(sockaddr);

    addrinfo hints;
    addrinfo *server;
    sockaddr address;

    int r;
    int max_connect;

    fd_set main_fd;
    fd_set read_fd;
    int serverfd;
    int clientfd;

    memset(&hints, 0, sizeof(addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    r = getaddrinfo(nullptr, port, &hints, &server);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    serverfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (serverfd == -1)
    {
        perror("failed");
        return 1;
    }

    r = bind(serverfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    puts("Chat server is listening...");
    listen(serverfd, backlog);

    // deal with multiple connections
    max_connect = backlog;
    FD_ZERO(&main_fd); // initialize file descriptor set
    FD_SET(serverfd, &main_fd);

    bool done = false;
    while (!done)
    {
        read_fd = main_fd;
        r = select(max_connect + 1, &read_fd, nullptr, nullptr, 0);
        if (r == -1)
        {
            perror("failed");
            return 1;
        }

        for (int fd = 1; fd <= max_connect; ++fd)
        {
            if (FD_ISSET(fd, &read_fd))
            {
                if (fd == serverfd)
                {
                    clientfd = accept(serverfd, (sockaddr *) &address, &address_len);
                    if (clientfd == -1)
                    {
                        perror("failed");
                        return 1;
                    }

                    // connection accepted, get IP address
                    getnameinfo(&address, address_len, clientname, clientname_size, nullptr, 0,
                                NI_NUMERICHOST);

                    // update array of IP addresses
                    strcpy(connection[clientfd], clientname);

                    FD_SET(clientfd, &main_fd);

                    // add new client socket to the file descriptor list
                    strcpy(buffer, "SERVER> Welcome ");
                    strcat(buffer, connection[clientfd]);
                    strcat(buffer, " to the chat server\n");
                    strcat(buffer, "SERVER> Type 'close' to disconnect; 'shutdown' to stop\\n");

                    send(clientfd, buffer, strlen(buffer), 0);

                    /* tell everyone else about the new user */
                    /* build the string: "SERVER> xxx.xxx.xxx.xxx has joined the server" */
                    strcpy(buffer, "SERVER> ");
                    strcat(buffer, connection[clientfd]);
                    strcat(buffer, " has joined the server\n");

                    for (int i = serverfd + 1; i < max_connect; ++i)
                    {
                        if (FD_ISSET(i, &main_fd))
                        {
                            send(i, buffer, strlen(buffer), 0);
                        }
                    }

                    printf("%s", buffer);
                }
                else
                {
                    r = recv(fd, buffer, BUFSIZ, 0);
                    if (r < 1)
                    {
                        FD_CLR(fd, &main_fd);
                        close(fd);

                        strcpy(buffer, "SERVER> ");
                        strcat(buffer, connection[fd]);
                        strcat(buffer, " disconnected\n");

                        for (int i = serverfd + 1; i < max_connect; ++i)
                        {
                            if (FD_ISSET(i, &main_fd))
                            {
                                send(i, buffer, strlen(buffer), 0);
                            }
                        }
                        printf("%s", buffer);
                    }
                    else
                    {
                        buffer[r] = '\0';
                        if (strcmp(buffer, "shutdown\n") == 0)
                        {
                            done = true;
                        }
                        else
                        {
                            strcpy(sendstr, connection[fd]);
                            strcat(sendstr, "> ");
                            strcat(sendstr, buffer);
                            for (int i = serverfd + 1; i < max_connect; ++i)
                            {
                                if (FD_ISSET(i, &main_fd))
                                {
                                    send(i, buffer, strlen(buffer), 0);
                                }
                            }
                            printf("%s", buffer);
                        }
                    }
                }
            }
        }
    }

    puts("SERVER> shutdown issued; cleaning up");
    close(serverfd);
    freeaddrinfo(server);
    return 0;
}