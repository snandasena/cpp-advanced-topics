//
// Created by sajith on 8/30/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (const auto &v: intervals)
        {
            if (res.empty() || res.back()[1] < v[0])
            {
                res.push_back(v);
            } else
            {
                res.back()[1] = max(res.back()[1], v[1]);
            }
        }
        return res;
    }
};