//
// Created by sajith on 9/1/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; ++layer)
        {
            // left to right
            for (int i = layer; i < n - layer; ++i)
            {
                res[layer][i] = cnt++;
            }
            // top to bottom
            for (int i = layer + 1; i < n - layer; ++i)
            {
                res[i][n - layer - 1] = cnt++;
            }
            // right to left
            for (int i = n - layer - 2; i >= layer; i--)
            {
                res[n - layer - 1][i] = cnt++;
            }
            // bottom to top
            for (int i = n - layer - 2; i > layer; i--)
            {
                res[i][layer] = cnt++;
            }
        }

        return res;
    }
};