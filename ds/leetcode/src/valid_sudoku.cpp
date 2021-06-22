//
// Created by sajith on 6/22/21.
//

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, set<char>> row, col, box;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (row[i].find(board[i][j]) != row[i].end() ||
                        col[j].find(board[i][j]) != col[j].end() ||
                        box[i / 3 * 3 + j / 3].find(board[i][j]) != box[i / 3 * 3 + j / 3].end())
                    {
                        return false;
                    }

                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[i / 3 * 3 + j / 3].insert(board[i][j]);
                }
            }
        }

        return true;
    }

};

