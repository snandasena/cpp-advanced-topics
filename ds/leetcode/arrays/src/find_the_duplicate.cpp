//
// Created by sajith on 3/29/22.
//

#include "base.h"

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int x =0;
        for (const auto &item : nums)
        {
            if((x ^ item) == 0)
            {
                return item;
            }
            x = item;
        }
        return -1;
    }
};