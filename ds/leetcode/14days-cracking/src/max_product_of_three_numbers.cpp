//
// Created by sajith on 12/3/21.
//

#include "base.h"

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        if (nums.size() == 3)return nums[0] * nums[1] * nums[2];
        sort(nums.begin(), nums.end(), greater<>());
        auto sz = nums.size();
        return max(nums[0] * nums[1] * nums[2], nums[sz - 1] * nums[sz - 2] * nums[sz - 3]);
    }
};