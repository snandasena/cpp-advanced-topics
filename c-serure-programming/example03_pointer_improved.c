#include <stdio.h>

int main()
{
    char string[] = "Hello, there!\n";
    char *s;
    s = string;
    while (putchar(*s) != '\0')
    {
        s++;
    }
    return (0);
}