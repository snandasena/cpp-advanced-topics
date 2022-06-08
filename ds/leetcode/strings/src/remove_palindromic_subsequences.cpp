//
// Created by sajith on 6/8/22.
//

#include "base.h"

class Solution
{
public:
    int removePalindromeSub1(string s)
    {
        auto i = 0;
        auto j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j]) return 2;
            ++i;
            --j;
        }
        return 1;
    }

    int removePalindromeSub(string s)
    {
        string p = s;
        reverse(s.begin(), s.end());
        if (p == s) return 1;
        return 2;
    }
};