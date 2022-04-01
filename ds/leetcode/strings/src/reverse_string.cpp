//
// Created by sajith on 4/1/22.
//
#include "base.h"

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        auto N = s.size();
        for (auto i = 0; i < N / 2; ++i)
        {
            swap(s[i], s[N - i - 1]);
        }
    }
};