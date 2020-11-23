#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

void PrintHello()
{
    printf("Hello\n");
}

int *Add(int *a, int *b)
{
    int *c = new int; // allocate memory in heap
    *c = (*a) + (*b);
    return c;
}

int main()
{
    // pointers as function returns
    int a = 2, b = 10;
    int *ptr = Add(&a, &b);
    PrintHello();
    printf("%d\n", *ptr);

    return 0;
}