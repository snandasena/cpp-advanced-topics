//
// Created by sajith on 10/14/21.
//

#include "base.h"

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            int minval = i;
            int y = 1, sq = 1;
            while (sq <= i)
            {
                minval = min(minval, 1 + dp[i - sq]);
                y++;
                sq = y * y;
            }
            dp[i] = minval;
        }

        return dp[n];
    }
};