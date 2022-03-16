//
// Created by sajith on 3/15/22.
//

#include "base.h"

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<char> stck;
        string ans{};
        for (auto &item : s)
        {
            if (item == ')')
            {
                if (stck.empty())
                {

                }
            }
            else if (item == '(')
            {
                if (stck.empty())
                {

                }
                else if (stck.top() == ')')
                {
                    ans+=item;
                }
            }
        }
    }
};