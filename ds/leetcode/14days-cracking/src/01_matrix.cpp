//
// Created by sajith on 10/1/21.
//


#include "base.h"

class Solution
{
    int ep[4][2] = {{1,  0},
                    {-1, 0},
                    {0,  1},
                    {0,  -1}};

public:
    vector<vector<int>> updateMatrixDP(vector<vector<int>> &mat)
    {
        int r = mat.size();
        if (r == 0)return mat;
        int c = mat[0].size();

        vector<vector<int>> dp(r, vector<int>(c, INT_MAX - 10000));

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                } else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }

                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (i < r - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                if (j < c - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
        return dp;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int r = mat.size();
        if (r == 0)return mat;
        int c = mat[0].size();

        vector<vector<int>> ans(r, vector<int>(c, INT_MAX));
        queue<pair<int, int>> que;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while (!que.empty())
        {
            auto pr = que.front();
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nr = pr.first + ep[i][0];
                int nc = pr.second + ep[i][1];

                if (nr >= 0 && nc >= 0 && nr < r && nc < c && ans[nr][nc] > ans[pr.first][pr.second] + 1)
                {
                    ans[nr][nc] = ans[pr.first][pr.second] + 1;
                    que.push({nr, nc});
                }
            }
        }
        return ans;
    }
};