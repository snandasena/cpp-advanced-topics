//
// Created by sajith on 12/18/21.
//

#include "base.h"

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        string s = to_string(n);
        auto K = s.length();
        vector<int> dp(K + 1);
        dp[K] = 1;
        int Si;
        for (int i = K - 1; i >= 0; --i)
        {
            Si = s[i] - '0';
            for (auto &c: digits)
            {
                if (c[0] - '0' < Si)
                {
                    dp[i] += pow(digits.size(), K - i - 1);
                }
                else if(c[0] -'0' == Si)
                {
                    dp[i] += dp[i + 1];
                }
            }
        }

        for (int i = 1; i < K; ++i)
        {
            dp[0] += pow(digits.size(), i);
        }

        return dp[0];
    }
};