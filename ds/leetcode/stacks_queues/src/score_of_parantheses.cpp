//
// Created by sajith on 3/17/22.
//

#include "base.h"


class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        int ans = 0;
        st.push(1);
        int curr = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                curr = st.empty()? 1: st.top() * 2;
                st.push(curr);

            }
            else
            {
                ans += curr;
                curr = 0;
                st.pop();
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.scoreOfParentheses("(())");
    return 0;
}