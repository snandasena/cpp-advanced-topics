//
// Created by sajith on 12/5/21.
//

#include "base.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        auto n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < n - 1; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        int mx = dp[n - 1];
        dp.clear();
        dp.assign(n + 1, 0);
        dp[2] = nums[1];

        for (int i = 2; i < n; ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        int mx2 = dp[n];
        return max(mx, mx2);
    }
};


int main()
{
    Solution solution;
    vector<int> v{2, 3, 2};
    cout << solution.rob(v);
    return 0;
}