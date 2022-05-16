//
// Created by sajith-csi on 5/16/2022.
//

#include "base.h"

class Solution
{
    int dir[8][2] = {{0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0},
                     {1,  1},
                     {1,  -1},
                     {-1, 1},
                     {-1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1) return -1;
        auto M = grid.size();
        auto N = grid[0].size();

        queue<tuple<int, int, int>> que;
        que.push({0, 0, 1});
        grid[0][0] = 1;

        size_t sz;

        while (!que.empty())
        {
            sz = que.size();
            while (sz--)
            {
                auto[x, y, t] = que.front();
                que.pop();

                if (x == N - 1 && y == M - 1) return t;

                for (auto &[r, c]: dir)
                {
                    auto X = r + x;
                    auto Y = c + y;
                    if (X >= 0 && Y >= 0 && X < N && Y < M && grid[X][Y] == 0)
                    {
                        que.push({X, Y, t + 1});
                        grid[X][Y] = 1;
                    }
                }

            }
        }
        return -1;
    }
};