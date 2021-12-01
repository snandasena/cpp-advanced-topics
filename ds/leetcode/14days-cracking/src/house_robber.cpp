//
// Created by sajith on 12/1/21.
//


#include "base.h"

class Solution
{
    int rob(vector<int> &nums, int n)
    {
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(rob(nums, n - 1), nums[n - 1] + rob(nums, n - 2));
    }

public:
    int rob1(vector<int> &nums)
    {
        auto n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int v1 = nums[0];
        int v2 = nums[1];
        int temp;
        for (int i = 1; i < n; ++i)
        {
            temp = v2;
            v2 = max(v2, v1 + nums[i]);
            v1 = temp;
        }
        return v2;
    }

    int rob(vector<int> &nums)
    {
        auto n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[n];
    }
};