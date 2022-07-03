//
// Created by sajith on 7/3/22.
//

#include "base.h"

class Solution
{
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (st.count(s[i]) && st.count(s[j]))
            {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            else if (st.count(s[i]) && !st.count(s[j]))
            {
                --j;
            }
            else if (!st.count(s[i]) && st.count(s[j]))
            {
                ++i;
            }
            else
            {
                ++i;
                --j;
            }
        }
        return s;
    }
};


int main()
{
    Solution solution;
    cout << solution.reverseVowels("leetcode");
    return 0;
}