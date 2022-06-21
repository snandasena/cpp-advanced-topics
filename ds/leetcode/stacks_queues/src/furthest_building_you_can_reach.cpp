//
// Created by sajith on 6/21/22.
//

#include "base.h"

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        auto n = heights.size();
        int bricks_sum = 0;
        int diff;
        for (int i = 1; i < n; ++i)
        {
            diff = heights[i] - heights[i - 1];

            if (diff <= 0) continue;

            pq.push(diff);
            if (pq.size() > ladders)
            {
                bricks_sum += pq.top();
                pq.pop();
            }

            if (bricks_sum > bricks) return i - 1;
        }
        return n - 1;
    }
};