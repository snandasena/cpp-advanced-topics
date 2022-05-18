//
// Created by sajith on 5/18/22.
//

#include "base.h"


class Solution
{
    vector<vector<int>> ans;
    int time{0};

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &timestamps, int v, int prev)
    {
        visited[v] = true;
        timestamps[v] = time++;
        int curr_time = timestamps[v];

        for (auto &u: adj[v])
        {
            if (u == prev) continue;
            if (!visited[u])
            {
                dfs(adj, visited, timestamps, u, v);
            }
            timestamps[v] = min(timestamps[v], timestamps[u]);
            if (curr_time < timestamps[u])
            {
                ans.push_back({v, u});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n+1);
        for (auto &v: connections)
        {
            auto a = v[0];
            auto b = v[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n+1);
        vector<int> timestamps(n+1);
        dfs(adj, visited, timestamps, 0, -1);
        return ans;
    }
};


int main()
{

    vector<vector<int>> v{{0,1}};

    Solution solution;
    auto ans = solution.criticalConnections(2, v);

    return 0;
}