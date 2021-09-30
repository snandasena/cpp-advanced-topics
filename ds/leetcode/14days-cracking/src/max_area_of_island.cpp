//
// Created by sajith on 9/30/21.
//

#include "base.h"

class Solution
{
    int ep[4][2] = {{1,  0},
                    {-1, 0},
                    {0,  1},
                    {0,  -1}};

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1)
        {
            return 0;
        }
        grid[i][j] = -1;
        return (1 + dfs(grid, i + 1, j)
                + dfs(grid, i - 1, j)
                + dfs(grid, i, j + 1)
                + dfs(grid, i, j - 1));

    }

    int dfs2(vector<vector<int>> &grid, int i, int j)
    {
        int ans = 0;
        stack<pair<int, int>> stck;
        stck.push({i, j});
        grid[i][j] = -1;
        while (!stck.empty())
        {
            auto pr = stck.top();
            stck.pop();
            ans++;
            for (int k = 0; k < 4; ++k)
            {
                int r = pr.first + ep[k][0];
                int c = pr.second + ep[k][1];
                if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1)
                {
                    stck.push({r, c});
                    grid[r][c] = -1;
                }
            }
        }
        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ans = max(ans, dfs2(grid, i, j));
                }
            }
        }
        return ans;
    }
};