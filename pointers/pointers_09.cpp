#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

int main()
{
    // Dynamic memory allocation

    int a; // goes to stack
    int *p; // goes to stack
    p = new int; // goes to heap with a 4 bytes
    *p = 10; // allocate memory from heap
    delete p; // delete memory from heap

    p = new int[20]; // allocate 20 * 4 bytes from heap
    delete[] p; // delete from the heap

    return 0;
}