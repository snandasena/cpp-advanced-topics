//
// Created by sajith on 11/28/21.
//
#include "base.h"

class Solution
{
    vector<vector<int>> _graph;
    vector<vector<int>> _result;

    void dfs(vector<int> &path, int u)
    {
        path.push_back(u);
        if (u == _graph.size() - 1) _result.push_back(path);
        else
        {
            for (auto v: _graph[u])
            {
                dfs(path, v);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        _graph = move(graph);
        vector<int> path;
        dfs(path, 0);
        return _result;
    }
};