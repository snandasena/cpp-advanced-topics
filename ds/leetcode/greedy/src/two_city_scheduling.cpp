//
// Created by sajith on 3/25/22.
//
#include "base.h"


class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [](const auto &v1, const auto &v2)
        {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });
        int ans = 0;
        auto n = costs.size() / 2;
        for (auto i = 0; i < n; ++i)
        {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
};