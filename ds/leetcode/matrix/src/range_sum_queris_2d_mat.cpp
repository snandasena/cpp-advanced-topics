//
// Created by sajith-csi on 6/3/2022.
//
#include "base.h"


class NumMatrix
{
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) : dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0))
    {
        for (auto i = 0; i < matrix.size(); ++i)
        {
            for (auto j = 0; j < matrix[i].size(); ++j)
            {
                dp[i][j + 1] = dp[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = 0;
        for (int i = row1; i <= row2; ++i)
        {
            ans += dp[i][col2 + 1] - dp[i][col1];
        }
        return ans;
    }
};