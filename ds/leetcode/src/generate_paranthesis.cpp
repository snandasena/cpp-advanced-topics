//
// Created by sajith on 8/19/21.
//

#include <bits//stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<set<string >> dp(n + 1);
        dp[0].insert("");
        dp[1].insert("()");

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                for (auto &s1: dp[j])
                {
                    for (auto &s2: dp[i - j])
                    {
                        string temp = s1 + s2;
                        dp[i].insert(temp);
                    }
                }
            }

            for (auto &str: dp[i - 1])
            {
                string temp = "(" + str + ")";
                dp[i].insert(temp);
            }
        }

        return vector<string>(dp[n].begin(), dp[n].end());
    }
};