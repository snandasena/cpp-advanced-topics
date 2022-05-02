//
// Created by sajith on 5/2/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0;
        int j = static_cast<int>(nums.size()) - 1;
        while (i < j)
        {
            if (nums[j] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                ++i;
            }
            else
            {
                --j;
            }
        }
        return nums;
    }
};