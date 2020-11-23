#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

int SumOfArray(int *A, int size)
{
    // this only copying one value of the array
//    int size = sizeof(A) / sizeof(A[0]);
//    printf("size of the array = %d\n", size);
    int i, sum = 0;
    for (i = 0; i < size; ++i)
    {
//        sum += A[i];
        sum += *(A + i);
    }

    return sum;
}

int main()
{
    int A[] = {1, 4, 5, 8, 2};
    int size = sizeof(A) / sizeof(A[0]);
    printf("size of the array = %d\n", size);
    printf("SOE = %d\n", SumOfArray(A, size));
    return 0;
}