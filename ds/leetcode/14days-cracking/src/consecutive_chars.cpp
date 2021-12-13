//
// Created by sajith on 12/13/21.
//

#include "base.h"

class Solution
{
public:
    int maxPower(string s)
    {
        int total = 1;
        int curr = 1;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i - 1] == s[i])
            {
                ++curr;
            }
            else
            {
                curr = 1;
            }

            total = max(curr, total);
        }
    }
};