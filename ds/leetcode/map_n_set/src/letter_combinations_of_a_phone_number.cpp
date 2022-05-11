//
// Created by sajith on 5/9/22.
//

#include "base.h"


class Solution
{
    vector<string> v;
    vector<string> dp{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(int i, int n, string &p, string &s)
    {
        if (i >= n)
        {
            v.push_back(p);
            return;
        }
        string q = dp[s[i] - '0'];
        for (const auto &item: q)
        {
            p += item;
            helper(i + 1, n, p, s);
            p.erase(p.size() - 1, 1);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return v;

        string p;
        helper(0, digits.size(), p, digits);
        return v;
    }
};