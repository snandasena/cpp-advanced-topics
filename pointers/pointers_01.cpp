#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

int main()
{
    int a = 10;
    int *p;
    p = &a;
    cout << p << endl;
    cout << *p << endl;
    cout << &a << endl;
    cout << &p << endl;

    *p = 12;
    cout << a << endl;
    cout << *p << endl;
    cout << p << endl;
    cout << p+1 << endl;
    cout << sizeof(int) << endl;

    return 0;
}