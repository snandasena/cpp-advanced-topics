//
// Created by sajith on 6/14/22.
//

#include "base.h"

class Solution
{
    int LCS(const string &s1, const string &s2, int m, int n, vector<vector<int>> memo)
    {
        if (m == 0 || n == 0) return 0;
        if (memo[m][n] > 0) return memo[m][n];

        if (s1[m - 1] == s2[n - 1])
        {
            memo[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, memo);
        }
        else
        {
            memo[m][n] = max(LCS(s1, s2, m, n - 1, memo), LCS(s1, s2, m - 1, n, memo));
        }

        return memo[m][n];
    }

public:
    int minDistance1(string word1, string word2)
    {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        return word1.size() + word2.size() - 2 * LCS(word1, word2, word1.size(), word2.size(), memo);
    }

    int minDistance(string word1, string word2)
    {
        auto M = word1.size();
        auto N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return M + N - 2 * dp[M][N];
    }
};