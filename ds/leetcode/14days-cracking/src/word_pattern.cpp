//
// Created by sajith on 1/17/22.
//

#include "base.h"

class Solution
{
public:
    bool wordPattern(string p, string s)
    {
        int i = 0;
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        string curr;
        auto N = static_cast<int>(s.length());
        auto M = static_cast<int>(p.length());

        int space = 0;
        for (auto const &c: s)
        {
            if (c == ' ')
            {
                ++space;
            }
        }

        if (space == 0 && M >1)
        {
            return false;
        }

        for (int j = 0; j < N; ++j)
        {
            if (s[j] != ' ')
            {
                curr = "";
                while (j < N && s[j] != ' ')
                {
                    curr += s[j];
                    ++j;
                }
            }

            if (mp.count(p[i]) > 0 && mp[p[i]] != curr)
            {
                return false;
            }
            else if (mp2.count(curr) > 0 && mp2[curr] != p[i])
            {
                return false;
            }
            else
            {
                mp[p[i]] = curr;
                mp2[curr] = p[i];
            }

            ++i;
        }

        return true;
    }
};

// "abba"
//"dog dog dog dog"

int main()
{
    Solution sol;

    string p{"unit"};
    string s{"unit"};

    cout << boolalpha << sol.wordPattern(p, s) << endl;

    return 0;
}