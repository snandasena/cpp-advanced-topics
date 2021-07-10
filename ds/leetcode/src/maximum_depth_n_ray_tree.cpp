//
// Created by sajith on 7/10/21.
//
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth2(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int ans = 0;

        for (Node *n: root->children)
        {
            ans = max(ans, maxDepth2(n));
        }

        return ans + 1;
    }

    // BFS
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<Node *> que;
        que.push(root);

        int depth = 0;
        while (!que.empty())
        {
            size_t se = que.size();

            while (se--)
            {
                Node *curr = que.front();
                que.pop();
                for (Node *n: curr->children)
                {
                    que.push(n);
                }
            }

            depth++;
        }

        return depth;
    }
};