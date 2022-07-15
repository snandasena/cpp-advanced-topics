//
// Created by sajith on 7/15/22.
//


#include "base.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int mx = 0;
        int steps = 0;
        int end = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            mx = max(mx, i + nums[i]);

            if (i == end)
            {
                end = mx;
                ++steps;
            }
        }
        return steps;
    }
};