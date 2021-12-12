//
// Created by sajith on 12/12/21.
//

#include "base.h"

class Solution
{
    vector<int> v;
    vector<int> dp;

    bool reduceToZero(int sum, int idx)
    {
        if (sum == 0) return true;
        if (idx == v.size()) return false;

        if (dp[sum] != -1)
        {
            return dp[sum] == 1;
        }

        bool ret = false;
        for (int i = idx; i < v.size(); ++i)
        {
            if (sum - v[i] >= 0)
            {
                ret = reduceToZero(sum - v[i], i + 1);
                if (ret) break;
            }
        }

        dp[sum] = ret ? 1 : 0;
        return ret;
    }

public:
    bool canPartition1(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;
        v = move(nums);
        dp.assign(sum + 1, -1);
        return reduceToZero(sum, 0);
    }
};

int main()
{
    Solution solution;
    vector<int> v{1, 5, 11, 5};
    cout << boolalpha << solution.canPartition(v) << endl;
    return 0;
}