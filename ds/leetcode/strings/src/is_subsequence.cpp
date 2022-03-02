//
// Created by sajith on 3/2/22.
//

#include "base.h"

class Solution
{
public:
    bool isSubsequence1(string s, string t)
    {
        if (s.size() == t.size() && s != t) return false;
        bool found;
        int j = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            found = false;
            for (; j < t.size(); ++j)
            {
                if (s[i] == t[j])
                {
                    found = true;
                    break;
                }
            }
            ++j;
            if (!found) return false;
        }

        return true;
    }

    bool isSubsequence(string s, string t)
    {
        size_t i = 0;
        for (auto &j : t)
        {
            if (s[i] == j)
            {
                ++i;
            }
        }
        return i == s.size();
    }

};

int main()
{
    Solution solution;
    cout << boolalpha << solution.isSubsequence("aaaaaa", "aaaaaa");
    return 0;
}