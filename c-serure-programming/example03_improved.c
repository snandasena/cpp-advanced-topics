#include <stdio.h>

int main()
{
    char string[] = "Hello, there!\n";
    int x;
    x = 0;
    while (putchar(string[x]) != '\0')
    {
        x++;
    }
    return (0);
}