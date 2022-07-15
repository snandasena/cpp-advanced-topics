//
// Created by sajith on 7/14/22.
//


#include "base.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int mx = 0;
        for (const auto &num: nums)
        {
            mp[num] += num;
            mx = max(mx, num);
        }

        vector<int> max_points(mx + 1, 0);
        max_points[1] = mp[1];
        for (int i = 2; i <max_points.size(); ++i)
        {
            max_points[i] = max(max_points[i - 1], max_points[i - 2] + mp[i]);
        }
        return max_points[mx];
    }
};