//
// Created by sajith on 8/21/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> ans;
public:

    void backtrack(vector<int> &candidates, int remain, vector<int> &comb, int index)
    {
        if (remain == 0)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = index; i < candidates.size(); ++i)
        {
            if(i > index && candidates[i]== candidates[i-1])
            {
                continue;
            }
            int pick =candidates[i];
            if(remain- pick < 0)
            {
                break;
            }
            comb.push_back(pick);
            backtrack(candidates, remain - pick, comb, i+1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        backtrack(candidates, target, comb, 0);
        return ans;
    }
};