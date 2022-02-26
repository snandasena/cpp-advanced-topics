//
// Created by sajith on 2/26/22.
//

#include "base.h"

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        if (graph.size() == 1) return 0;

        auto N = graph.size();
        int endingmask = (1 << N) - 1;
        vector<vector<bool>> seen(N, vector<bool>(endingmask,false));
        queue<pair<int, int>> que;

        for (int i = 0; i < N; ++i)
        {
            que.push({i, 1 << i});
            seen[i][1 << i] = true;
        }

        int steps = 0;
        while (!que.empty())
        {
            auto sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                auto[node, mask] = que.front();
                que.pop();
                for (auto &neighbor: graph[node])
                {
                    auto nextmask = mask | (1 << neighbor);
                    if (nextmask == endingmask) return 1 + steps;

                    if (!seen[neighbor][nextmask])
                    {
                        seen[neighbor][nextmask] = true;
                        que.push({neighbor, nextmask});
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> g{{1, 2, 3},
                          {0},
                          {0},
                          {0}};

    cout<<solution.shortestPathLength(g)<<endl;
    return 0;
}