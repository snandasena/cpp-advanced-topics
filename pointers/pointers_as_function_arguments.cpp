#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

// call by value
void Increament01(int a)
{
    a += 1;
    printf("Address of 'a' in Increment01 is %d\n", &a);

}

void Increament(int *ptra)
{
    *ptra = (*ptra) + 1;
    printf("Address of 'a' in Increment is %d\n", ptra);
}

int main()
{

    int a;
    a = 10;
    Increament01(a);
    printf("Address of a = %d, value = %d\n", &a, a);
    Increament(&a);
    printf("Address of a = %d, value = %d\n", &a, a);
    return 0;
}