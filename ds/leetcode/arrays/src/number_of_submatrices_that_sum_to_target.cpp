//
// Created by sajith on 7/18/22.
//


#include "base.h"

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        auto N = static_cast<int >(matrix.size());
        auto M = static_cast<int>(matrix[0].size());

        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j < M; ++j)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int ans = 0;

        for (int c1 = 0; c1 < M; ++c1)
        {
            for (int c2 = c1; c2 < M; ++c2)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for (int row = 0; row < N; ++row)
                {
                    sum += (c1 > 0 ? matrix[row][c2] - matrix[row][c1 - 1] : matrix[row][c2]);

                    if (mp.find(sum - target) != mp.end())
                    {
                        ans += mp[sum - target];
                    }
                    ++mp[sum];
                }
            }
        }
        return ans;
    }
};
