//
// Created by sajith on 6/13/21.
//

#include <stdio.h>

extern "C"
{
extern void printey();
extern int calcey(int x, int y);
}

int main()
{
    printey();
    printf("%d\n", calcey(10, 22));

    return 0;
}