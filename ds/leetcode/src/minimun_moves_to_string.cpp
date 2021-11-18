//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    int minimumMoves(string s)
    {
        int steps = 0;
        for (int i = 0; i < s.size();)
        {
            if (s[i] == 'X')
            {
                if (i > s.size() - 3)
                {
                    return ++steps;
                }
                else
                {
                    i += 3;
                    ++steps;
                }
            }
            else ++i;
        }
        return steps;
    }
};