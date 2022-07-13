//
// Created by sajith on 7/13/22.
//


#include "base.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        auto N = nums.size();
        if (N == 1) return nums[0];

        vector<int> dp(N + 1, 0);
        dp[1] = nums[0];

        for (int i = 1; i < N - 1; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        auto mx = dp[N - 1];

        dp.clear();
        dp.assign(N+1, 0);

        dp[2] = nums[1];
        for (int i = 2; i < N; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return max(mx, dp[N]);
    }
};