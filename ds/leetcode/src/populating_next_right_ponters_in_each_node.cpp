//
// Created by sajith on 7/7/21.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            size_t nodes = q.size();

            while (nodes > 0)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }

                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }

                if (nodes > 1)
                {
                    curr->next = q.front();
                }

                nodes--;
            }
        }

        return root;
    }
};