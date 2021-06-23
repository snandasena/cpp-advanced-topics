//
// Created by sajith on 6/23/21.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    bool helper(const string &s, const string &word)
    {
        size_t idx = 0;
        for (char c: word)
        {
            idx = s.find_first_of(c, idx);
            if (idx++ == string::npos)
            {
                return false;
            }
        }

        return true;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        for (string word: words)
        {
            if (helper(s, word))
            {
                ++ans;
            }
        }
        return ans;
    }
};


int main()
{
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};

    Solution solution;
    cout << solution.numMatchingSubseq(s, words) << endl;

    s = "dsahjpjauf";
    words.clear();
    words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << solution.numMatchingSubseq(s, words) << endl;

    return 0;
}