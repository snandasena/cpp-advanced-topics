//
// Created by sajith on 5/11/22.
//

#include "base.h"

class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<vector<int>> dp(5, vector<int>(n + 1, 0));
        dp[0][1] = 5;
        dp[1][1] = 4;
        dp[2][1] = 3;
        dp[3][1] = 2;
        dp[4][1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[4][i] = 1;
            dp[3][i] = dp[3][i - 1] + dp[4][i - 1];
            dp[2][i] = dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1];
            dp[1][i] = dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1];
            dp[0][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1];
        }
        return dp[0][n];
    }
};