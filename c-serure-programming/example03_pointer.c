#include <stdio.h>

int main()
{
    char string[] = "Hello, there!\n";
    char *s;
    s = string;
    while (putchar(*s))
    {
        s++;
    }
    return (0);
}