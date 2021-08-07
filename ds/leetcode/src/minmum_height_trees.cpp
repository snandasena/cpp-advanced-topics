//
// Created by sajith on 8/6/21.
//


#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (const auto &v: edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);

            indegree[v[0]]++;
            indegree[v[1]]++;
        }

        queue<int> que;
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 1)
            {
                que.push(i);
                indegree[i]--;
            }
        }

        while (!que.empty())
        {
            size_t sz = que.size();
            res.clear();

            for (auto i = 0; i < sz; ++i)
            {
                int curr = que.front();
                que.pop();
                res.push_back(curr);

                for (const auto &ele: adj[curr])
                {
                    indegree[ele]--;
                    if (indegree[ele] == 1)
                    {
                        que.push(ele);
                    }
                }
            }
        }
        if (n == 1)
        {
            res.push_back(0);
        }
        return res;
    }
};