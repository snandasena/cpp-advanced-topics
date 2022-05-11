//
// Created by sajith on 5/10/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> res;

    int sum(const vector<int> &comb)
    {
        int ans = 0;
        for (const auto &item: comb)
        {
            ans += item;
        }
        return ans;
    }

    void helper(int k, int n, vector<int> &comb, int num)
    {
        if (k == 0)
        {
            if (sum(comb) == n)
            {
                res.push_back(comb);
            }
            return;
        }

        if (num > 9)return;
        comb.push_back(num);
        helper(k - 1, n, comb, num + 1);
        comb.pop_back();
        helper(k, n, comb, num + 1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> comb;
        helper(k, n, comb, 1);
        return res;
    }
};