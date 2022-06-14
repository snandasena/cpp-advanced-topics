//
// Created by sajith on 6/13/22.
//

#include "base.h"


class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = static_cast<int>( triangle.size()) - 2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};