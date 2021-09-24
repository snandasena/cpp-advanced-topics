//
// Created by sajith on 9/24/21.
//

#include "base.h"

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l = s.size() / 2;
        for (int i = 0; i < l; ++i)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};