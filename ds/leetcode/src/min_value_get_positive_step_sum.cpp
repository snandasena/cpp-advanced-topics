
//
// Created by sajith on 11/11/21.
//

#include "base.h"

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int minval = 0;
        int prefixsum = 0;
        for (const int &i: nums)
        {
            prefixsum += i;
            minval = min(minval, prefixsum);
        }
        return -minval + 1;
    }
};