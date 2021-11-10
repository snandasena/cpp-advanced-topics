//
// Created by sajith on 11/10/21.
//

#include "base.h"

class Solution
{
    set<pair<int, int> > cache;
    int m, n;
public:

    void fill_col(vector<vector<int>> &matrix, int j)
    {
        for (int i = 0; i < m; ++i)
        {
            matrix[i][j] = 0;
        }
    }

    void fill_row(vector<vector<int>> &matrix, int i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0) cache.insert({i, j});
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (cache.count({i, j}) != 0)
                {
                    fill_col(matrix, j);
                    fill_row(matrix, i);
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},
                                  {3,4,5,2},
                                  {1,3,1,5}};

    Solution solution;
    solution.setZeroes(matrix);
    return 0;
}