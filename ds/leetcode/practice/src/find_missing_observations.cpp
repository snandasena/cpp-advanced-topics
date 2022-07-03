//
// Created by sajith on 7/2/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        int remain = mean * (n + static_cast<int >(rolls.size())) - sum;
        if (remain > n * 6 || remain < n) return {};

        vector<int> ans(n, remain / n);
        auto rem = remain % n;
        for (int i = 0; i < rem; ++i)
        {
            ans[i]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> v{3, 2, 4, 3};
    Solution solution;
    solution.missingRolls(v, 4, 2);
    return 0;
}