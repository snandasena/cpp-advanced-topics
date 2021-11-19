//
// Created by sajith on 11/19/21.
//

#include "base.h"

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
//        return __builtin_popcount(x ^ y);

        int dist = 0;
        for (int i = x ^ y; i > 0; ++dist)
        {
            i = i & (i - 1);
        }
        return dist;
    }
};