#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 16

char *input(void)
{
    static char buffer[SIZE];
    char *r;
    int x;
    buffer[0] = '\0';
    r = fgets(buffer, SIZE, stdin);

    if (r == NULL)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }

    for (x = 0; x < SIZE; ++x)
    {
        if (buffer[x] == '\n')
        {
            buffer[x] = '\0';
            break;
        }
    }
    return (buffer);
}