//
// Created by sajith on 9/13/21.
//

#include <bits/stdc++.h>

using namespace std;


class Solution
{
    vector<vector<string>> ans;
public:

    bool isSafe(vector<string> &board, int x, int y, int n)
    {
        for (int row = 0; row < x; ++row)
        {
            // column check
            if (board[row][y] == 'Q')
            {
                return false;
            }
        }

        int row = x, col = y;
        // lower  upper diagonal check
        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        row = x, col = y;
        while (row >= 0 and col < n)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }

            row--;
            col++;
        }

        return true;
    }

    void solve(vector<string> &board, int x, int n)
    {
        if (x >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (isSafe(board, x, col, n))
            {
                board[x][col] = 'Q';
                solve(board, x + 1, n);
                board[x][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; ++i)
        {
            board[i] = s;
        }

        solve(board, 0, n);
        return ans;
    }
};