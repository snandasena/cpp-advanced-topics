//
// Created by sajith on 1/22/22.
//


#include "base.h"

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);
        int t;
        int k;
        for (int i = 0; i <= n; ++i)
        {
            if (dp[i])
            {
                continue;
            }

            k = 1;
            t = i + 1;
            while (t <= n)
            {
                dp[t] = true;
                ++k;
                t = i + (k * k);
            }
        }

        return dp[n];
    }
};

int main()
{

    Solution sol;
    cout << sol.winnerSquareGame(1) << endl;
}