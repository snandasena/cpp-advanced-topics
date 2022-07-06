//
// Created by sajith on 7/6/22.
//

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>
#include <cstring>

using namespace std;

int main()
{
    const char *google_dns_server = "8.8.8.8";
    const char *dns_port = "53";
    const char *p;

    char buffer[BUFSIZ];
    int sockfd;
    int r;

    addrinfo hints;
    addrinfo *peer_address;

    sockaddr_in name;
    socklen_t namelen;
    // configure the peer_address addrinfo structue
    memset(&hints, 0, sizeof(addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    r = getaddrinfo(google_dns_server, dns_port, &hints, &peer_address);
    if (r != 0)
    {
        perror("failed");
        return 1;
    }

    sockfd = socket(peer_address->ai_family, peer_address->ai_socktype, peer_address->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        return 1;
    }

    // connect to the server
    r = connect(sockfd, peer_address->ai_addr, peer_address->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // obtain the local socket's name
    namelen = sizeof(name);
    r = getsockname(sockfd, (sockaddr *) &name, &namelen);
    if (r == -1)
    {
        perror("failed");
        return 1;
    }

    // output the results
    p = inet_ntop(peer_address->ai_family, &name.sin_addr, buffer, BUFSIZ);
    if (p)
    {
        printf("Local IP is: %s\n", buffer);
    }
    else
    {
        fprintf(stderr, "operation failed\n");
    }

    close(sockfd);
    return 0;
}
