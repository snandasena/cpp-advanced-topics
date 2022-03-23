//
// Created by sajith on 3/23/22.
//

#include "base.h"

class Solution
{
public:
    int brokenCalc(int S, int T)
    {
        int ans = 0;
        while (T > S)
        {
            ++ans;
            if (T % 2 == 1)
            {
                ++T;
            }
            else
            {
                T /= 2;
            }
        }
        return ans + S - T;
    }
};