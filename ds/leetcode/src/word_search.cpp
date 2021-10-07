//
// Created by sajith on 10/7/21.
//

#include "base.h"

class Solution
{
    int ep[4][2] = {{1, 0},
                    {-1, 0},
                    {0, 1},
                    {0, -1}};

    bool dfs(vector<vector<char>> &board, int r, int c, string &word, int idx)
    {
        if (idx == word.size() - 1)
        {
            return true;
        }
        board[r][c] -= 65;
        if (r > 0 && board[r - 1][c] == word[idx + 1] && dfs(board, r - 1, c, word, idx + 1)) return true;
        if (c > 0 && board[r][c - 1] == word[idx + 1] && dfs(board, r, c - 1, word, idx + 1)) return true;
        if (r < board.size() - 1 && board[r + 1][c] == word[idx + 1] && dfs(board, r + 1, c, word, idx + 1))
            return true;
        if (c < board[0].size() - 1 && board[r][c + 1] == word[idx + 1] && dfs(board, r, c + 1, word, idx + 1))
            return true;

        board[r][c] += 65;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (word[0] == board[i][j] && dfs(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};