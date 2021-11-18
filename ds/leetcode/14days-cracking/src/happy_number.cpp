//
// Created by sajith on 11/18/21.
//

#include "base.h"

using lli = long long int;

class Solution
{
    set<int> cache;
public:
    int next(int n)
    {
        int sum = 0;
        lli d;
        while (n > 0)
        {
            d = n % 10;
            n /= 10;
            sum += (d * d);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = next(n);
        while (fast != 1 && slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};