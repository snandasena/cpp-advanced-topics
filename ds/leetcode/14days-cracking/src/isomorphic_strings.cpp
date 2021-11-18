//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
    string genString(string s)
    {
        unordered_map<char, int> mps;
        string ss;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mps.count(s[i]) == 0)
            {
                mps[s[i]] = i;
            }
            ss += " " + to_string(mps[s[i]]);
        }
        return ss;
    }

public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mps.count(s[i]) == 0)
            {
                mps[s[i]] = i;
            }

            if (mpt.count(t[i]) == 0)
            {
                mpt[t[i]] = i;
            }

            if (mps[s[i]] != mpt[t[i]]) return false;
        }
        return true;
    }
};


int main()
{
    string s = "foo";
    string t = "bar";

    s = "abcdefghijklmnopqrstuvwxyzva";
    t = "abcdefghijklmnopqrstuvwxyzck";
    Solution solution;
    cout << boolalpha << solution.isIsomorphic(s, t) << endl;
    return 0;
}