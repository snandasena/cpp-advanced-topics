//
// Created by sajith on 7/27/21.
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
    vector<int> vals;

public:
    void naryopstorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        for (Node *n: root->children)
        {
            postorder(n);
        }
        vals.push_back(root->val);
    }

//    vector<int> postorder(Node *root)
//    {
//        naryopstorder(root);
//        return vals;
//    }

    vector<int> postorder(Node *root)
    {
        if (root == nullptr)
        {
            return vals;
        }
        stack<Node *> stck;
        stck.push(root);

        while (!stck.empty())
        {
            auto *top = stck.top();
            stck.pop();
            vals.push_back(top->val);

            for (const auto &node: top->children)
            {
                if (node != nullptr)
                {
                    stck.push(node);
                }
            }
        }


        reverse(vals.begin(), vals.end());
        return vals;
    }

};