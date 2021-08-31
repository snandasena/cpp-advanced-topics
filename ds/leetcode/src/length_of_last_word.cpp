//
// Created by sajith on 8/31/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string curr;
        string pre;
        for (char c: s)
        {
            if (c != ' ')
            {
                curr += c;
            } else
            {
                if (!curr.empty())
                {
                    pre = curr;
                }
                curr = "";
            }
        }

        if (!curr.empty())
        {
            return curr.length();
        }
        return pre.length();
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    return 0;
}