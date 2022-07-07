//
// Created by sajith on 7/7/22.
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
    int sockfd;
    printf("Assign a socket...\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("failed");
        return 0;
    }
    puts("done");

    close(sockfd);
    puts("socket closed, done");
    return 0;
}