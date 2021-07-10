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
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int ans = 0;

        for (Node *n: root->children)
        {
            ans = max(ans, maxDepth(n));
        }

        return ans + 1;
    }
};