//
// Created by sajith on 5/6/22.
//

#include "base.h"

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> stk;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (stk.empty() || stk.back().first != s[i])
            {
                stk.emplace_back(s[i], 1);
            }
            else
            {
                stk.back().second += 1;
            }

            if (stk.back().second == k)
            {
                stk.pop_back();
            }
        }

        string ans{};
        for (const auto &[first, second]: stk)
        {
            ans += string(second, first);
        }

        return ans;
    }
};