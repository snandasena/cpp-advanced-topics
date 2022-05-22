//
// Created by sajith on 5/22/22.
//
#include "base.h"


class Solution
{
public:
    int countSubstrings(string s)
    {
        if (s.empty()) return 0;
        auto n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;

        for (auto i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            res++;
        }

        for (auto i = 0; i < n - 1; ++i)
        {
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i + 1]) res++;
        }

        for (auto len = 3; len <= n; ++len)
        {
            for (auto i = 0, j = i + len - 1; j < n; ++i, ++j)
            {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]) res++;
            }
        }

        return res;

    }
};

