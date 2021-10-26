//
// Created by sajith on 10/26/21.
//

#include <bits/stdc++.h>

using namespace std;

int addWithoutCarry(int num1, int num2)
{
    int ans = 0;
    int k = 1;
    while (num2 || num1)
    {
        ans += ((num1 % 10 + num2 % 10) % 10)* k;
        num1 /= 10;
        num2 /= 10;
        k *= 10;
    }

    return ans;
}


int main()
{
    cout << addWithoutCarry(1734, 456);
    return 0;
}