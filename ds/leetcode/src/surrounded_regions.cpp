//
// Created by sajith on 7/14/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    size_t m;
    size_t n;
    vector<vector<bool>> visited;

public:

    void dfs(vector<vector<char>> &board, size_t i, size_t j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != 'O')
        {
            return;
        }

        visited[i][j] = true;

        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (size_t i = 0; i < n; ++i)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, 0, i);
            }

            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i);
            }
        }

        for (size_t i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }

            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1);
            }
        }

        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

    }

};