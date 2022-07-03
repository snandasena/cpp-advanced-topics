//
// Created by sajith on 7/2/22.
//

#include "base.h"


class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string mx{"0"};
        string curr;
        for (int i = 0; i < number.size(); ++i)
        {
            if (digit == number[i])
            {
                curr = number.substr(0, i) + number.substr(i + 1);
                mx = max(curr, mx);
            }
        }

        return mx;
    }
};