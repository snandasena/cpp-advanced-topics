//
// Created by sajith on 7/15/22.
//

#include "base.h"

class Solution
{
public:
    bool canJump1(vector<int> &nums)
    {
        if (nums.size() == 1)return true;
        auto pos = 0;
        for (auto i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == 0 && pos == i)
            {
                return false;
            }

            pos = max(pos, nums[i] + i);

            if (pos >= nums.size() - 1) return true;
        }
        return false;
    }

    bool canJump(vector<int> &nums)
    {
        int mx = 0;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            if (mx < nums[i] + i)
            {
                mx = nums[i] + i;
            }

            if (mx == i)
                break;
        }
        return mx >= nums.size() - 1;
    }
};