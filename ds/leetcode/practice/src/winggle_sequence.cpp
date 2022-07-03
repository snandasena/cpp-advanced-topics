//
// Created by sajith on 7/3/22.
//


#include "base.h"

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2) return nums.size();

        int up = 1;
        int down = 1;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i + 1] < nums[i])
            {
                up = down + 1;
            }
            else if (nums[i + 1] > nums[i])
            {
                down = up + 1;

            }
        }
        return max(down, up);
    }
};