//
// Created by sajith on 9/22/21.
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
            curr = max(curr + nums[i], nums[i]);
            mx = max(mx, curr);
        }

        return mx;
    }
};