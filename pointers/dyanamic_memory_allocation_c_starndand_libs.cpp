#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

void assignValues(int *A, int n)
{
    for (int i = 0; i < n; ++i)
    {
        A[i] = i;
    }
}

void println(int *A, int n)
{
    if (A)
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", *(A + i));
        }
        printf("\n");
    }
}

int main()
{

    // C starndard libs function for dynamic memory allocation
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *A = (int *) malloc(n * sizeof(int));
    // before assign values
    println(A, n); // this will print garbage values
    // assign values for the array
    assignValues(A, n);
    // after assgin values
    println(A, n);

    free(A); // this will not granutee of free
    A = nullptr;
    println(A, n);

    int *B = (int *) calloc(n, sizeof(int));
    // before assign values
    println(B, n);
    // assign values for the array
    assignValues(B, n);
    // after assign values
    println(B, n);

    // Realloc
    int *C = (int *) realloc(B, 2 * sizeof(int));
    println(C, 2 * n);
    return 0;
}