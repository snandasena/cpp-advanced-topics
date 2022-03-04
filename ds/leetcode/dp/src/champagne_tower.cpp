//
// Created by sajith on 3/4/22.
//

#include "base.h"

class Solution
{
public:
    double champagneTower(int p, int r, int q)
    {
        vector<vector<double>> dp(r + 2, vector<double>(101, 0.0));
        dp[0][0] = p * 1.0;
        double temp;
        for (int i = 0; i <= r; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                temp = (dp[i][j] - 1.0) / 2.0;
                if (temp > 0)
                {
                    dp[i + 1][j] += temp;
                    dp[i + 1][j + 1] += temp;
                }
            }
        }
        return min(1.0, dp[r][q]);
    }
};