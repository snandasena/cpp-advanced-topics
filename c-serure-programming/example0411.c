#include <stdio.h>
#include <stdlib.h>

#define UNIX

int main()
{
#ifdef UNIX
    system("ls -la");
#endif

#ifdef WINDOWS
    system("dir");
#endif

    puts("All done!");

    return (0);
}