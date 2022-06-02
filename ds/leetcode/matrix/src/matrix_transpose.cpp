//
// Created by sajith on 6/2/22.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        auto R = matrix.size();
        auto C = matrix[0].size();
        vector<vector<int>> ans(C, vector<int>(R));

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};