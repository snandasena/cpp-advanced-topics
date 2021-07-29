//
// Created by sajith on 7/29/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> adj;
    vector<int> ordering;
    vector<int> visited{};
    bool circleFound = false;

public:

    void dfs(int i)
    {
        if (visited[i] == 1)
        {
            circleFound = true;
            return;
        }

        if (visited[i] == 2)
        {
            return;
        }

        visited[i] = 1;
        for (const auto &edge: adj[i])
        {
            dfs(edge);
        }

        visited[i] = 2;
        ordering.push_back(i);
    }

    vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
    {
        adj.assign(N, {});
        visited.assign(N, 0);

        for (const auto &pre: prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < N; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        if (circleFound)
        {
            return {};
        }
        return ordering;
    }
};