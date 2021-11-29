//
// Created by sajith on 11/29/21.
//

#include "../base.h"


bool is_unique_chars(string const &str)
{
    if (str.length() < 128) return false;
    vector<bool> charv(128, false);
    for (auto c: str)
    {
        if (charv[int(c)])
        {
            return false;
        }
        charv[int(c)] = true;
    }
    return true;
}

bool check_permutations(string const &str1, string const &str2)
{
    vector<int> v(str1.length(), 0);
    for (auto ch: str1)
    {
        ++v[int(ch - 'a')];
    }

    for (auto ch: str2)
    {
        if (v[int(ch - 'a')] == 0) return false;
    }

    return true;
}