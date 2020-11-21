#include <bits/stdc++.h>

using namespace std;
#define  endl '\n';

int main()
{
    int a = 1025;
    // 1025 === 00000000 00000000 00000100 00000001
    int *p;
    p = &a;
    cout << "size of integer is " << sizeof(int) << " bytes\n";
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p + 1, *(p + 1));

    char *p0;
    p0 = (char *) p; // typecasting
    cout << "Size of char is " << sizeof(char) << " bytes\n";
    printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d, value = %d\n", p0 + 1, *(p0 + 1)); // output will be memory add and value = 1

    // void pointers
    void *p1;
    p1 = p;
    printf("Address = %d\n", p1);
    return 0;
}