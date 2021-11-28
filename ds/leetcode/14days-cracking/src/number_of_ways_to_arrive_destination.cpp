//
// Created by sajith on 11/28/21.
//
#include "base.h"

class Solution
{
    int ans{0};

    void dfs(vector<vector<int>> &roads, int n, int time, int u)
    {
        time += roads[u][2];
        if (u == roads.size() - 1)
        {
            if (time <= n) ++ans;
        }
        else
        {
            for (auto v: roads[u])
            {
                dfs(roads, n, time, v);
            }
        }
    }

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        dfs(roads, n, 0, 0);
        return ans;
    }
};

int main()
{
    vector<vector<int>> roads{{0, 6, 7},
                              {0, 1, 2},
                              {1, 2, 3},
                              {1, 3, 3},
                              {6, 3, 3},
                              {3, 5, 1},
                              {6, 5, 1},
                              {2, 5, 1},
                              {0, 4, 5},
                              {4, 6, 2}};

    Solution solution;
    cout << solution.countPaths(7, roads) << '\n';
    return 0;
}