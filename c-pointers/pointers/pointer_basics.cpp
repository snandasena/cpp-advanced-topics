//
// Created by sajith on 7/12/21.
//

#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    printf("%p", arr);

    for (int i = 0; i < 10; ++i)
    {
        printf("Position: %d, Pointer %p\n", i, arr + i);
    }

    return 0;
}