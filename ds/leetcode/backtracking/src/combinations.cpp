//
// Created by sajith on 2/17/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void backtracking(vector<int> &combination, vector<int> &candidates, int k, size_t start)
    {
        if (k == 0)
        {
            ans.push_back(combination);
            return;
        }

        for (size_t i = start; i < candidates.size(); ++i)
        {
            combination.push_back(candidates[i]);
            backtracking(combination, candidates, k - 1, i + 1);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> candidates;
        for (int i = 1; i <= n; ++i)
        {
            candidates.push_back(i);
        }
        vector<int> com;
        backtracking(com, candidates, k, 0);
        return ans;
    }
};