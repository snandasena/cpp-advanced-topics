#include <bits/stdc++.h>

using namespace std;

void FuncA()
{
    printf("Hello\n");
}

void FuncB(void (*ptr)()) // function pointer as argument
{
    ptr(); // callback function that "ptr" points to
}

int compare(int a, int b)
{
    if (a > b) return 1;
    return -1;
}

void BubbleSort(int *A, int n, int (*compare)(int, int))
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (compare(A[j], A[j + 1]) > 0)
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

void printArr(int *A, int n)
{
    for (int i = 0; i < n; ++i) printf("%d ", A[i]);
    printf("\n");
}

int compare2(const void *a, const void *b)
{
    int A = *((int *) a);
    int B = *((int *) b);

    return abs(A) - abs(B);
//    return B - A;
}

int main()
{
    // function pointers and callbacks
    void (*p)() =FuncA;
    FuncB(p);

    FuncB(FuncA);

    int A[] = {-54, 2, 4, 3, 7, 5, 6, -1, -32};
    BubbleSort(A, 9, compare);
    printArr(A, 9);

    qsort(A, 9, sizeof(int), compare2);
    printArr(A, 9);
    return 0;
}