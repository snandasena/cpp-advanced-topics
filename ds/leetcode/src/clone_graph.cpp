//
// Created by sajith on 7/23/21.
//
/*
// Definition for a Node.

 */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        map<Node *, Node *> mp;
        queue<Node *> que;

        Node *clone = new Node(node->val);
        que.push(node);
        mp.insert({node, clone});

        while (!que.empty())
        {

            Node *curr = que.front();
            que.pop();

            for (const auto &child : curr->neighbors)
            {
                if (mp[child] == nullptr)
                {
                    Node *temp = new Node(child->val);
                    mp[child] = temp;
                    que.push(child);
                }

                mp[curr]->neighbors.push_back(mp[child]);
            }
        }

        return mp[node];
    }
};
