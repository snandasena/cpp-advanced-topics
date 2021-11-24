//
// Created by sajith on 11/24/21.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int >> ans;
        int i = 0;
        int j = 0;
        int lo;
        int hi;
        while (i < firstList.size() && j < secondList.size())
        {
            lo = max(firstList[i][0], secondList[j][0]);
            hi = min(firstList[i][1], secondList[j][1]);
            if (lo <= hi)
            {
                ans.push_back({lo, hi});
            }

            if (firstList[i][1] < secondList[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return ans;
    }
};