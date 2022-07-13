//
// Created by sajith on 7/13/22.
//


#include "base.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];

        auto N = nums.size();
        vector<int> dp(N + 1, 0);
        dp[1] = nums[0];

        for (auto i = 1; i < N; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        return dp[N];
    }
};

int main()
{
    Solution solution;
    vector<int> v{2};

    cout << solution.rob(v);

    return 0;
}