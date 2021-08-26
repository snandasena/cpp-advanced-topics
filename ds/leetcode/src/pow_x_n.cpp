//
// Created by sajith on 8/26/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            return myPow(1.0 / x, abs(n));
        }

        if (n == 0)
        {
            return 1.0;
        }

        double tmp = myPow(x, n / 2);
        double res = tmp * tmp;

        if (n % 2 != 0)
        {
            res *= x;
        }

        return res;
    }
};