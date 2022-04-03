
//
// Created by sajith on 4/3/22.
//

#include "base.h"

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        auto i = static_cast<int >(nums.size()) - 2;
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            --i;
        }

        if (i >= 0)
        {
            auto j = static_cast<int >(nums.size()) - 1;
            while (nums[j] <= nums[i])
            {
                --j;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};