//
// Created by sajith on 6/30/21.
//

#include <cstdio>

int main()
{
    const int bufsize = 256;
    static char buf[bufsize];

    fputs("prompt: ", stdout);
    fgets(buf, bufsize, stdin);
    puts("output:");

    fputs(buf, stdout);
    fflush(stdout);
    return 0;
}