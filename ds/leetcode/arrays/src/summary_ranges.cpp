//
// Created by sajith on 2/28/22.
//
#include "base.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        auto N = static_cast<int >(nums.size());
        if (N == 0) return {};

        vector<string> ans;
        int a = nums[0];
        for (int i = 0; i < N; ++i)
        {
            if (i == N - 1 || nums[i] + 1 != nums[i + 1])
            {
                if (nums[i] != a)
                {
                    ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                }
                else
                {
                    ans.push_back(to_string(a));
                }

                if (i != N - 1)
                    a = nums[i + 1];
            }
        }
        return ans;
    }
};