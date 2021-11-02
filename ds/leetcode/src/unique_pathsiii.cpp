//
// Created by sajith on 11/2/21.
//

#include "base.h"

class Solution
{
    int res = 0, empty = 1;
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int cnt)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) return;

        if (grid[i][j] == 2)
        {
            if (empty == cnt) ++res;
            return;
        }

        grid[i][j] = -1;
        dfs(grid, i + 1, j, cnt + 1);
        dfs(grid, i - 1, j, cnt + 1);
        dfs(grid, i, j + 1, cnt + 1);
        dfs(grid, i, j - 1, cnt + 1);
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int sx, sy;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1) sx = i, sy = j;
                else if (grid[i][j] == 0) ++empty;
            }
        }

        dfs(grid, sx, sy, 0);
        return res;
    }
};