//
// Created by sajith on 10/28/21.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l, r, sum;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                if (l > i + 1 && nums[l] == nums[l - 1])
                {
                    ++l;
                    continue;
                }
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                } else if (sum < 0)
                {
                    ++l;
                } else
                {
                    --r;
                }

            }
        }

        return res;
    }
};