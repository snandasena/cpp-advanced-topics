#include <stdio.h>

int main()
{
    char string[] = "Hello, there!\n";
    char *s;
    s = string;
    while (1)
    {
        if (*s == '\0')
        {
            break;
        }
        putchar(*s);
        s++;
    }
    return (0);
}