//
// Created by sajith on 6/28/21.
//

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

template<typename T>
T maxof(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    puts("Hello ");

    int x = 10;
    int *xPtr = &x;

    cout << *xPtr << endl;
    printf("%d\n", *xPtr);

    cout<<maxof(1, 3)<<endl;
    cout<<maxof<string>("aaa", "bbb")<<endl;
    cout<<maxof<const char *>("aaa", "bbb")<<endl;
    return 0;
}