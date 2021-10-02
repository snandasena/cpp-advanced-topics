//
// Created by sajith on 10/2/21.
//

#include "base.h"

class Solution
{
    int ep[4][2] = {{1,  0},
                    {-1, 0},
                    {0,  1},
                    {0,  -1}};

    int bfs(vector<vector<int>> &grid, queue<pair<int, int>> &que, int &fresh)
    {
        int mins = 0;
        while (!que.empty() && fresh > 0)
        {
            auto sz = que.size();
            while (sz--) // bfs
            {
                auto pr = que.front();
                que.pop();
                for (auto &i : ep)
                {
                    int r = pr.first + i[0];
                    int c = pr.second + i[1];

                    if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        que.push({r, c});
                        fresh--;
                    }
                }
            }
            mins++; // four directions rotting
        }
        return (fresh == 0) ? mins : -1;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> que;
        int fresh = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                }
            }
        }
        return bfs(grid, que, fresh);
    }
};