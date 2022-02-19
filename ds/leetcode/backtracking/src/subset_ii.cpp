//
// Created by sajith on 2/19/22.
//

#include "base.h"

class Solution
{
    vector<vector<int>> ans;

    void backtrack(vector<int> &curr, vector<int> candidates, unsigned start)
    {
        ans.push_back(curr);
        for (unsigned i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            curr.push_back(candidates[i]);
            backtrack(curr, candidates, i + 1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(curr, nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 2};
    Solution solution;
    auto ans = solution.subsetsWithDup(nums);
    return 0;
}