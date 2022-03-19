//
// Created by sajith on 3/18/22.
//

#include "base.h"

class Solution
{
public:
    string smallestSubsequence(string s) // removeDuplicateLetters
    {
        vector<int> letters(26, 0);
        for (const auto &item : s)
        {
            ++letters[item - 'a'];
        }
        string ans{"0"};
        vector<bool> visited(26, false);
        for (const auto &item : s)
        {
            --letters[item - 'a'];
            if (visited[item - 'a']) continue;
            while (item < ans.back() && letters[ans.back() - 'a'] > 0)
            {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += item;
            visited[item - 'a'] = true;
        }
        return ans.substr(1);
    }
};

int main()
{
    Solution solution;
    cout << solution.smallestSubsequence("cbaacabcaaccaacababa");
    return 0;
}