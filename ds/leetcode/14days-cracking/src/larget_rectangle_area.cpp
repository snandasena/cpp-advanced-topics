//
// Created by sajith on 11/30/21.
//

#include "base.h"

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        auto n = heights.size();
        vector<int> sL(n, 0);
        vector<int> sR(n, 0);
        sL[0] = -1;
        sR[n - 1] = n;

        int idx;
        for (int i = 1; i < n; ++i)
        {
            idx = i - 1;
            while (idx >= 0 && heights[idx] >= heights[i])
            {
                idx = sL[idx];
            }
            sL[i] = idx;
        }

        for (int i = n - 2; i >= 0; --i)
        {
            idx = i + 1;
            while (idx < n && heights[idx] >= heights[i])
            {
                idx = sR[idx];
            }
            sR[i] = idx;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res = max(res, heights[i] * (sR[i] - sL[i] - 1));
        }
        return res;
    }
};