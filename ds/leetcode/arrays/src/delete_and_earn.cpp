//
// Created by sajith on 3/6/22.
//

#include "base.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> points;
        int max_num = 0;
        for (const auto &item : nums)
        {
            points[item] += item;
            max_num = max(item, max_num);
        }

        vector<int> max_points(max_num + 1,0);
        max_points[1] = points[1];
        for (int i = 2; i < max_points.size(); ++i)
        {
            max_points[i] = max(max_points[i - 1], max_points[i - 2] + points[i]);
        }
        return max_points[max_num];
    }
};