//
// Created by sajith on 4/30/22.
//

#include "base.h"

// eq = [A, B]
// val = A/B
// a/b = 2
// b/c = 3
// a/c = a/b * b/c = 2 * 3 = 6
class Solution
{
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_map<string, unordered_map<string, bool>> visited;

    void dfs(const string &a, const string &b)
    {
        for (auto const &[c, value]: graph[b])
        {
            if (visited[a][c]) continue;

            graph[a][c] = graph[a][b] * graph[b][c];
            visited[a][c] = true;
            dfs(a, c);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries)
    {
        string a;
        string b;
        int i = 0;
        for (auto &equation: equations)
        {
            a = equation[0];
            b = equation[1];

            graph[a][b] = values[i];
            visited[a][b] = true;

            graph[b][a] = 1.0 / values[i];
            visited[b][a] = true;

            graph[b][b] = 1.0;
            visited[b][b] = true;

            graph[a][a] = 1.0;
            visited[a][a] = true;
            ++i;
        }

        vector<double> ans;
        string c;
        for (auto &query: queries)
        {
            a = query[0];
            c = query[1];

            for (auto const &[b, value]: graph[a])
            {
                dfs(a, b);
            }

            ans.push_back(!visited[a][c] ? -1 : graph[a][c]);
        }
        return ans;
    }
};