//
// Created by sajith on 6/8/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxarea = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            maxarea = max(area, maxarea);

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maxarea;
    }
};