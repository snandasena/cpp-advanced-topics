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
#include <ifaddrs.h>

int main()
{
    ifaddrs *adapters;
    ifaddrs *a;
    int r;
    int addrfam;
    const int ap_size = 100;
    char ap[ap_size];

    puts("This computer's network interfaces:");
    r = getifaddrs(&adapters);

    if (r == -1)
    {
        perror("Interfaces");
        return 1;
    }

    printf("%-8s%-8s%s\n", "Name", "Family", "Address");
    a = adapters;

    while (a)
    {
        addrfam = a->ifa_addr->sa_family;
        if (addrfam == AF_INET || addrfam == AF_INET6)
        {
            getnameinfo(a->ifa_addr,
                        addrfam == AF_INET ? sizeof(sockaddr_in) : sizeof(sockaddr_in6),
                        ap,
                        ap_size,
                        0,
                        0,
                        NI_NUMERICHOST);

            printf("%-8s%-8s%s\n",
                   a->ifa_name,
                   addrfam == AF_INET ? "IPv4" : "IPv6",
                   ap
            );
        }
        a = a->ifa_next;
    }

    freeifaddrs(adapters);
    return 0;
}