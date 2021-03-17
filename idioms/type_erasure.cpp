//
// Created by sajith on 3/16/21.
//

#include <iostream>

using namespace std;


int main()
{
    int arr[4] = {1, 2, 3, 4};

    cout << arr[0] << "\n";
    cout << arr << "\n";
    int *ptr = &arr[0];

    ptr += 1;
    cout << *ptr << '\n';

    cout << ptr;
    return 0;
}