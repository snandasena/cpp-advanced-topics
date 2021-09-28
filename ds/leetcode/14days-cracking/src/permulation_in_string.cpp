//
// Created by sajith on 9/27/21.
//

#include "base.h"

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        vector<int> s1v(26, 0);
        vector<int> s2v(26, 0);

        int left = 0, right = 0;
        while (right < s1.length())
        {
            s1v[s1[right] - 'a'] += 1;
            s2v[s2[right] - 'a'] += 1;
            right += 1;
        }

        right -= 1;
        while (right < s2.length())
        {
            if (s1v == s2v)
            {
                return true;
            }

            right += 1;
            if (right != s2.length()) // 1 step increase from the end
            {
                s2v[s2[right] - 'a'] += 1;
            }
            s2v[s2[left] - 'a'] -= 1; // 1 step increase from the begin
            left += 1;
        }
        return false;
    }
};