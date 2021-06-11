//
// Created by sajith on 6/11/21.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> *v = new vector<string>;

    void solve(int i, int n, string dp[], string &p, string s)
    {
        if (i >= n)
        {
            v->push_back(p);
            return;
        }

        string q = dp[s[i] - '0'];
        for (char j : q)
        {
            p += j;
            solve(i + 1, n, dp, p, s);
            p.erase(p.size() - 1, 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {

        v->clear();
        if (digits.empty())
        {
            return *v;
        }

        string dp[10];
        dp[2] = "abc";
        dp[3] = "def";
        dp[4] = "ghi";
        dp[5] = "jkl";
        dp[6] = "mno";
        dp[7] = "pqrs";
        dp[8] = "tuv";
        dp[9] = "wxyz";

        string p;

        solve(0, digits.size(), dp, p, digits);
        return *v;
    }
};

int main()
{
    Solution solution;
    for (auto &r: solution.letterCombinations("23"))
    {
        cout << r << " ";
    }

    return 0;
}