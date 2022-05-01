//
// Created by sajith on 5/1/22.
//

#include "base.h"

class Solution
{

    string helper(const string &str)
    {
        stack<char> st;
        for (const auto &item: str)
        {
            if (item != '#')
            {
                st.push(item);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        string s{};
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }


        return s;
    }


public:
    bool backspaceCompare(string s, string t)
    {
        return helper(s) == helper(t);
    }
};