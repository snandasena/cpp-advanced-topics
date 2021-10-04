//
// Created by sajith on 10/4/21.
//


#include "base.h"

class Solution
{
public:

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 1;
        }
        if (grid[i][j] == -1)
        {
            return 0;
        }
        grid[i][j] = -1;
        return dfs(grid, i + 1, j)+ dfs(grid, i - 1, j)+ dfs(grid, i, j + 1)+ dfs(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};