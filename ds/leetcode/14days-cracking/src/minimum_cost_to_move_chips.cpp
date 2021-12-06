//
// Created by sajith on 12/6/21.
//

#include "base.h"

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int even_cnt = 0;
        int odd_cnt = 0;
        for (auto &num: position)
        {
            if (num % 2 == 0) ++even_cnt;
            else ++odd_cnt;
        }
        return min(odd_cnt, even_cnt);
    }
};