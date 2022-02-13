//
// Created by sajith on 2/13/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void backtrack(int first, size_t k, vector<int> &curr, vector<int> &nums)
    {
        if (curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = first; i < nums.size(); ++i)
        {
            curr.push_back(nums[i]);
            backtrack(i + 1, k, curr, nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); ++i)
        {
            vector<int> v;
            backtrack(0, i, v, nums);
        }
        return ans;
    }
};