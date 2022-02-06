//
// Created by sajith on 2/6/22.
//

#include "base.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 3) return nums.size();

        int cnt = 1;
        int j = 1;
        int pre = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (pre == nums[i])
            {
                ++cnt;
                if (cnt > 2) continue;
            }
            else
            {
                cnt = 1;
                pre = nums[i];
            }
            swap(nums[i], nums[j]);
            ++j;
        }

        return j;
    }
};