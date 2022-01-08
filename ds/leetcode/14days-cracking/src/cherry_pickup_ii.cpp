//
// Created by sajith on 1/8/22.
//

#include "base.h"

class Solution
{
public:
    int helper(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
        {
            return 0;
        }

        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }

        int res = 0;
        res += grid[row][col1];
        if (col1 != col2)
        {
            res += grid[row][col2];
        }

        if (row != grid.size() - 1)
        {
            int mx = 0;
            for (int new_col1 = col1 - 1; new_col1 <= col1 + 1; ++new_col1)
            {
                for (int new_col2 = col2 - 1; new_col2 <= col2 + 1; ++new_col2)
                {
                    mx = max(mx, helper(row + 1, new_col1, new_col2, grid, dp));
                }
            }
            res += mx;
        }
        dp[row][col1][col2] = res;
        return res;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        auto n = grid.size();
        auto m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return helper(0, 0, n - 1, grid, dp);
    }
};


int main()
{
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(5, vector<int>(3, -1)));
    return 0;
}
