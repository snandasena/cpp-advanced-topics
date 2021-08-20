//
// Created by sajith on 8/20/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> ans;
public:

    void backtrack(vector<int> &comb, int remain, vector<int> &candidates, int remider_startidx)
    {
        if (remain <= 0)
        {
            if (remain == 0)
            {
                ans.push_back(comb);
            }
            return;
        }

        for (int i = remider_startidx; i < candidates.size(); ++i)
        {
            comb.push_back(candidates[i]);
            backtrack(comb, remain - candidates[i], candidates, i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> comb;
        backtrack(comb, target, candidates, 0);
        return ans;
    }
};