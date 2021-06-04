//
// Created by sajith on 6/4/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), l = p.size();
        vector<vector<bool>> dp(l + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= l; ++i)
        {
            if (p[i - 1] == '*')
            {
                dp[i][0] = dp[i - 2][0];
            }

            for (int j = 1; j <= n; ++j)
            {
                if (p[i - 1] == '.' || p[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*')
                {
                    if (p[i - 2] == '.' || p[i - 2] == s[j - 1])
                    {
                        dp[i][j] = dp[i][j - 1];
                    }

                    dp[i][j] = dp[i][j] || dp[i - 2][j];
                }
            }
        }

        return dp[l][n];
    }
};


int main()
{

    Solution solution;
    cout << boolalpha << solution.isMatch("mississippi", "mis*is*p*.");

    return 0;
}
