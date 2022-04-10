//
// Created by sajith on 4/10/22.
//

#include "base.h"

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> st;
        int curr;
        int prev;
        for (const auto &item: ops)
        {
            if (item == "+")
            {
                curr = st.top();
                prev = st.top();
                st.pop();
                curr += st.top();
                st.push(prev);
                st.push(curr);

            }
            else if (item == "D")
            {
                curr = st.top();
                curr *= 2;
                st.push(curr);
            }
            else if (item == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(item));
            }
        }

        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};