//
// Created by sajith on 9/6/21.
//

#include <bits//stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stck;
        stck.push(-1);
        int mx = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                stck.push(i);
            } else
            {
                stck.pop();
                if (stck.empty())
                {
                    stck.push(i);
                } else
                {
                    mx = max(mx, i - stck.top());
                }
            }
        }
        return mx;
    }
};