//
// Created by sajith on 7/3/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());

        int i = 0;
        for (const auto &item: nums)
        {
            if (item >= 0)
            {
                ans[i] = item;
                i += 2;
            }
        }

        i = 1;
        for (const auto &item: nums)
        {
            if (item < 0)
            {
                ans[i] = item;
                i += 2;
            }
        }

        return ans;
    }
};