#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

int main()
{

    int A[] = {1, 4, 5, 8, 2};

    for (int i = 0; i < 5; ++i)
    {

        printf("%d\n", A+i);
        printf("%d\n", &A[i]);
        printf("%d\n", A[i]);
        printf("%d\n", *(A+1));

    }
    return 0;
}