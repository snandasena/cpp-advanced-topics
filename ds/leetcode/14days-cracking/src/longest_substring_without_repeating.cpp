//
// Created by sajith on 9/26/21.
//

#include "base.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mp;
        int res = 0;
        int len = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mp.count(s[i]) == 0)
            {
                len++;
            } else
            {
                len = min(len + 1, i - mp[s[i]]);
            }

            mp[s[i]] = i;
            res = max(len, res);
        }
        return res;
    }
};