//
// Created by sajith on 7/15/22.
//


#include "base.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            curr = max(nums[i], curr + nums[i]);
            mx = max(mx, curr);
        }
        return mx;
    }
};