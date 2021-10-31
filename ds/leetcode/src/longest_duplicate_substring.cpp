
#include "base.h"

class Solution
{
    unordered_map<char, vector<int>> hash;

public:
    string longestDupSubstring(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            hash[s[i]].push_back(i);
        }

        int mx = 0, idx = -1, j = 0;
        char f;

        for (int i = 0; i < n; ++i)
        {
            f = s[i];
            hash[f].erase(hash[f].begin());

            for (int &it: hash[f])
            {
                j = 0;
                while (i + j < n && it + j < n && s[i + j] == s[it + j])
                {
                    ++j;
                }

                if (j > mx)
                {
                    mx = j;
                    idx = i;
                }

                if (mx == n - i - 1)
                {
                    return s.substr(idx, mx);
                }
            }
        }

        if (mx == 0) return "";
        return s.substr(idx, mx);
    }
};
