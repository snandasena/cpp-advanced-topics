//
// Created by sajith on 2/17/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void backtrack(vector<int> &combination, int remain, vector<int> &candidates, size_t start)
    {
        if (remain < 0) return;
        else if (remain == 0)
        {
            ans.push_back(combination);
            return;
        }

        for (size_t i = start; i < candidates.size(); ++i)
        {
            combination.push_back(candidates[i]);
            backtrack(combination, remain - candidates[i], candidates, i);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> com;
        backtrack(com, target, candidates, 0);
        return ans;
    }
};