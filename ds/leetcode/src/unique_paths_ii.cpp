//
// Created by sajith on 9/5/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        obstacleGrid[0][0] = 1;

        // filling the values for the first column
        for (int i = 1; i < rows; ++i)
        {
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1)
            {
                obstacleGrid[i][0] = 1;
            } else
            {
                obstacleGrid[i][0] = 0;
            }
        }

        for (int i = 1; i < cols; ++i)
        {
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1)
            {
                obstacleGrid[0][i] = 1;
            } else
            {
                obstacleGrid[0][i] = 0;
            }
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else
                {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        return obstacleGrid[rows - 1][cols - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // filling the 0th row
        for (int i = 0; i < cols; ++i)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }
            dp[0][i] = 1;
        }

        // filling the 0th column
        for (int i = 0; i < rows; ++i)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            dp[i][0] = 1;
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};