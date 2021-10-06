
//
// Created by sajith on 10/6/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> findDuplicates1(vector<int> &nums)
    {
        vector<int> res;
        unordered_set<int> mp;

        for (const int &i: nums)
        {
            if (mp.count(i) == 0)
            {
                mp.insert(i);
            } else if (mp.count(i) == 1)
            {
                mp.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }

    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int x = abs(nums[i]);
            if (nums[x - 1] < 0)
            {
                res.push_back(x);
            }
            nums[x - 1] *= -1;
        }
        return res;
    }
};