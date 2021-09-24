//
// Created by sajith on 9/24/21.
//

#include "base.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        string t;
        string ans;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ')
            {
                t += s[i];
            } else
            {
                reverse(t.begin(), t.end());
                ans += t + " ";
                t = "";
            }
        }
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "Let's take LeetCode contest";
    cout<<solution.reverseWords(s)<<endl;
    return 0;
}