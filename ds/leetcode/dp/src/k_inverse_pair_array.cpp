
//
// Created by sajith on 7/17/22.
//


#include "base.h"

class Solution
{
    const int MOD = 1e9 + 7;
public:
    int kInversePairs2(int n, int k) //TLE
    {
        vector<vector<int>> memo(1001, vector<int>(1001, -1));

        if (n == 0) return 0;

        if (k == 0) return 1;

        if (memo[n][k] != -1) return memo[n][k];

        int inv = 0;
        for (int i = 0; i <= min(k, n - 1); ++i)
        {
            inv = (inv + kInversePairs2(n - 1, k - i)) % MOD;
        }
        memo[n][k] = inv;
        return inv;
    }

    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    for (int l = 0; l <= min(j, i - 1); ++l)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
                    }
                }
            }
        }
        return dp[n][k];
    }
};