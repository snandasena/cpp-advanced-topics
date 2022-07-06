//
// Created by sajith on 7/6/22.
//


#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>


int main()
{

    char host[BUFSIZ];
    int r;
    r = gethostname(host, BUFSIZ);
    if (r == -1)
    {
        fprintf(stderr, "Unable to obtain host name\n");
        return 1;
    }

    printf("This host is named: %s\n", host);

    hostent *hostdata;
    hostdata = gethostbyname(host);

    if (!hostdata)
    {
        fprintf(stderr, "Can't obtain host data\n");
        return 1;
    }

    printf("Addresses: ");
    char **addresses;
    addresses = hostdata->h_addr_list;

    while (*addresses)
    {
        printf("%s\n", inet_ntoa(*(in_addr *) *addresses));
        addresses++;
    }

    return 0;
}