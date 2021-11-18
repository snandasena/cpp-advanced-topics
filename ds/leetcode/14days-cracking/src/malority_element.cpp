//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    int majorityElement2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int candidate{0};
        for (int const &i: nums)
        {
            if (cnt == 0)
            {
                candidate = i;
            }
            cnt += (i == candidate) ? 1 : -1;
        }
        return candidate;
    }


};