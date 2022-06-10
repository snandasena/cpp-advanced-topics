//
// Created by sajith on 6/10/22.
//

#include "base.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> v(256, -1);

        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            i = max(i, v[s[j]] + 1);
            ans = max(ans, j - i + 1);
            v[s[j]] = j;
        }

        return ans;
    }
};