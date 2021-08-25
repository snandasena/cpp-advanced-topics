//
// Created by sajith on 8/24/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> ans;

public:

    // STL answer
    vector<vector<int>> permuteUnique2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return ans;
    }

    void backtrack(vector<int> &nums, map<int, int> &mp, vector<int> &comb, size_t n)
    {
        if (n == comb.size())
        {
            ans.push_back(comb);
            return;
        }

        for (const auto &p: mp)
        {
            if (p.second == 0)
            {
                continue;
            }
            mp[p.first]--;
            comb.push_back(p.first);
            backtrack(nums, mp, comb, n);
            comb.pop_back();
            mp[p.first]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        map<int, int> mp;
        for (const auto &i: nums)
        {
            mp[i]++;
        }
        vector<int> comb;
        backtrack(nums, mp, comb, nums.size());
        return ans;
    }
};