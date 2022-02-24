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

        Node *new_graph{nullptr};

        map<Node *, Node *> copied;
        queue<Node *> to_visit;
        to_visit.push(node);
        Node *source;
        Node *new_node;
        while (!to_visit.empty())
        {
            source = to_visit.front();
            new_node = new Node(source->val);
            to_visit.pop();
            if (!new_graph)
            {
                new_graph = new_node;
            }
            copied[source] = new_graph;
        }
    }
};