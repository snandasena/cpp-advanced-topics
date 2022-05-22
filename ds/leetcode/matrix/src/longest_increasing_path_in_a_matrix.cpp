//
// Created by sajith on 5/19/22.
//

#include "base.h"

class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &memo)
    {
        if (memo[i][j] > 0) return memo[i][j];
        int mx = 0;
        for (const auto  &[_i, _j]: dir)
        {
            auto x = _i + i;
            auto y = _j + j;
            if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] > mat[i][j])
            {
                mx = max(mx, dfs(mat, x, y, memo));
            }
        }
        memo[i][j] = mx + 1;
        return mx + 1;

    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int ans = 0;
        int curr;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                curr = dfs(matrix, i, j, memo);
                ans = max(curr, ans);
            }
        }

        return ans;
    }
};