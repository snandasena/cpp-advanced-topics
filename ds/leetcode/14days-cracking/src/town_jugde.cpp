//
// Created by sajith on 1/3/22.
//

#include "base.h"


class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> v(n + 1, 0);
        for (auto const &p: trust)
        {
            v[p[0]] -= 1;
            v[p[1]] += 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (v[i] == n-1)
            {
                return i;
            }
        }

        return -1;
    }
};