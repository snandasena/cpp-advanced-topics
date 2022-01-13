//
// Created by sajith on 1/13/22.
//

#include "base.h"

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](auto &a, auto &b)
        {
            return a[1] < b[1];
        });

        int ans = 1;
        int min_end = points[0][1];
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] > min_end) // curr_start > min_end
            {
                ++ans;
                min_end = points[i][1]; // min_end = curr_end
            }
        }
        return ans;
    }
};