//
// Created by sajith on 8/27/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int up = 0;
        int left = 0;
        int right = cols - 1;
        int down = rows - 1;

        while (res.size() < rows * cols)
        {
            // left to right
            for (int col = left; col <= right; ++col)
            {
                res.push_back(matrix[up][col]);
            }

            // downwards
            for (int row = up + 1; row <= down; ++row)
            {
                res.push_back(matrix[row][right]);
            }

            if (up != down)
            {
                for (int col = right - 1; col >= left; col--)
                {
                    res.push_back(matrix[down][col]);
                }
            }

            if (left != right)
            {
                for (int row = down - 1; row > up; row--)
                {
                    res.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            up++;
            down--;
        }

        return res;
    }
};