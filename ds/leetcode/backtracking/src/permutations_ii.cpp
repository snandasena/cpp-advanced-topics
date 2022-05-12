//
// Created by sajith on 5/12/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void backtrack(vector<int> &nums, map<int, int> &mp, vector<int> &comb)
    {
        if (nums.size() == comb.size())
        {
            ans.push_back(comb);
            return;
        }

        for (const auto &[first, second]: mp)
        {
            if (second == 0) continue;
            mp[first]--;
            comb.push_back(first);
            backtrack(nums, mp, comb);
            comb.pop_back();
            mp[first]++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        map<int, int> mp;
        for (const auto &num: nums)
        {
            mp[num]++;
        }
        vector<int> comb;
        backtrack(nums, mp, comb);
        next_permutation()
        return ans;
    }
};