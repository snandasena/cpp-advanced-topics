
//
// Created by sajith on 7/16/22.
//


#include "base.h"


class Solution
{
    using LI = long int;
    const int MOD = 1e9 + 7;
    long dfs(int m, int n, int max_move, int srow, int scolumn, vector<vector<vector<int>>> &dp)
    {
        if (srow < 0 || srow >= m || scolumn < 0 || scolumn >= n)
        {
            return 1;
        }
        if (max_move <= 0) return 0;
        if (dp[srow][scolumn][max_move] != -1) return dp[srow][scolumn][max_move];

        long res = 0;
        res += dfs(m, n, max_move - 1, srow, scolumn + 1, dp);
        res += dfs(m, n, max_move - 1, srow, scolumn - 1, dp);
        res += dfs(m, n, max_move - 1, srow + 1, scolumn, dp);
        res += dfs(m, n, max_move - 1, srow - 1, scolumn, dp);
        return dp[srow][scolumn][max_move] = res % MOD;

    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(51, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, dp) % MOD;
    }
};

int main()
{
//    Solution sol;
//    sol.findPaths(0, 0, 0, 0, 0);
    const int MOD = 1e9 + 7;
    cout << MOD;

    return 0;
}