#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

//void Func(int ***A) // except first dimensional others must be provided
void Func(int (*A)[2][2]) // except first dimensional others must be provided
{

}

int main()
{
    // multi dimensional arrays
    int C[3][2][2] = {{{2, 5}, {7,  9}},
                      {{3, 4}, {6,  1}},
                      {{0, 8}, {11, 13}}};

    printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]); // same reference
    printf("%d\n", *(C[0][0] + 1));

    Func(C);
    return 0;
}