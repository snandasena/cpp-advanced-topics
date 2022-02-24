//
// Created by sajith on 2/23/22.
//

#include "base.h"

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node) return node;
        unordered_map<Node *, Node *> graph;
        graph[node] = new Node(node->val);
        queue<Node *> que;
        que.push(node);
        Node *head;
        while (!que.empty())
        {
            head = que.front();
            que.pop();
            for (auto neighbor: head->neighbors)
            {
                if (graph.find(neighbor) == graph.end())
                {
                    graph[neighbor] = new Node(neighbor->val);
                    que.push(neighbor);
                }
                graph[head]->neighbors.push_back(graph[neighbor]);
            }
        }
        return graph[node];
    }
};