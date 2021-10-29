//
// Created by sajith on 10/29/21.
//

#include "base.h"

class Solution
{
private:
    int ep[4][2] = {{1,  0},
                    {-1, 0},
                    {0,  1},
                    {0,  -1}};
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> que;
        int fresh = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                } else if (grid[i][j] == 1)
                {
                    ++fresh;
                }
            }
        }
        int ans = 0, x, y, sz;
        pair<int, int> pr;
        while (!que.empty() && fresh > 0)
        {
            sz = que.size();
            while (sz--)
            {
                pr = que.front();
                que.pop();
                for (auto &i : ep)
                {
                    x = pr.first + i[0];
                    y = pr.second + i[1];
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        que.push({x, y});
                        --fresh;
                    }
                }
            }
            ++ans;
        }
        return (fresh == 0) ? ans : -1;
    }
};