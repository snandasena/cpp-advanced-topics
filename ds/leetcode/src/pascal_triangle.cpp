//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                {
                    res[i].push_back(1);
                    continue;
                }

                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
        return res;
    }
};