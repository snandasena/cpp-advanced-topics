#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

int Add(int a, int b)
{
    return a + b;
}

int (*Func)(int, int);

int main()
{
    // Function Pointers in C/C++
    int c;
    int (*p)(int, int);
    p = &Add;

    c = (*p)(2, 10);
    printf("%d\n", c);

    Func = Add;
    c = Func(10, 3);
    printf("%d\n", c);
    return 0;
}
