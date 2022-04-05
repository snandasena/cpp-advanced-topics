//
// Created by sajith on 4/5/22.
//

#include "base.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int mx = 0;
        auto i = height.size() - 1;
        size_t j = 0;
        int curr;
        while (j < i)
        {
            curr = (i - j) * min(height[i], height[j]);
            mx = max(mx, curr);

            if (height[i] > height[j])
            {
                ++j;
            }
            else
            {
                --i;
            }
        }
        return mx;
    }
};