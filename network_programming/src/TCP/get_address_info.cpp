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


using namespace std;

int main()
{
    const char *host = "yahoo.com";
    const char *port = "80";

    int r;
    addrinfo hints;
    addrinfo *resource;

    printf("Configuring host....\n");
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET; // IPV4
    hints.ai_socktype = SOCK_STREAM; // TCP

    r = getaddrinfo(host, port, &hints, &resource);
    if (r != 0)
    {
        perror("Failed");
        return 0;
    }
    puts("done!");
    freeaddrinfo(resource);
    return 0;
}