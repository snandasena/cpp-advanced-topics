//
// Created by sajith on 5/14/22.
//

#include "base.h"


class Solution
{

    vector<pair<int, int>> adj[101];

    void dfs(vector<int> &signal_received_at, int curr_node, int curr_time)
    {
        if (curr_time >= signal_received_at[curr_node])return;

        signal_received_at[curr_node] = curr_time;

        for (const auto &[travel_time, neighbor_node]: adj[curr_node])
        {
            dfs(signal_received_at, neighbor_node, curr_time + travel_time);
        }
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        int src;
        int dest;
        int travel_time;

        for (const vector<int> &time: times)
        {
            src = time[0];
            dest = time[1];
            travel_time = time[2];
            adj[src].emplace_back(travel_time, dest);
        }

        for (int i = 1; i <= n; ++i)
        {
            sort(adj[i].begin(), adj[i].end());
        }

        vector<int> signal_received_at(n + 1, INT_MAX);

        dfs(signal_received_at, k, 0);
        int ans = INT_MIN;
        for (int node = 1; node <= n; ++node)
        {
            ans = max(ans, signal_received_at[node]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};