//
// Created by sajith on 7/7/22.
//

#include "base.h"


class Solution
{

    bool helper(const string &s1, size_t i, const string &s2, size_t j, const string &res, const string &s3)
    {
        if (res == s3 && i == s1.length() && j == s2.length()) return true;

        bool ans = false;
        if (i < s1.length())
        {
            ans |= helper(s1, i + 1, s2, j, res + s1[i], s3);
        }
        if (j < s2.length())
        {
            ans |= helper(s1, i, s2, j + 1, res + s2[j], s3);
        }
        return ans;
    }


public:
    bool isInterleave2(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length()) return false;

        return helper(s1, 0, s2, 0, "", s3);
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<bool> dp(s2.length() + 1);

        for (int i = 0; i <= s1.length(); ++i)
        {
            for (int j = 0; j <= s2.length(); ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = true;
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};

int main()
{
    Solution sol;
    cout << boolalpha << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}