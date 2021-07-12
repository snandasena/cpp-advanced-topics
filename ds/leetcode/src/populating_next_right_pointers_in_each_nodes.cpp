//
// Created by sajith on 7/12/21.
//

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
    Node *connect1(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }

        queue<Node *> que;
        que.push(root);

        while (!que.empty())
        {
            size_t sz = que.size();
            for (size_t i = 0; i < sz; ++i)
            {
                Node *curr = que.front();
                que.pop();

                if (i != sz - 1)
                {
                    curr->next = que.front();
                }

                if (curr->left)
                {
                    que.push(curr->left);
                }

                if (curr->right)
                {
                    que.push(curr->right);
                }
            }

        }

        return root;
    }

    Node *connect(Node *root)
    {
        Node *ans = root;

        while (root)
        {
            Node *temp = new Node;
            Node *curr = temp;

            while (root)
            {
                if (root->left)
                {
                    curr->next = root->left;
                    curr = curr->next;
                }

                if (root->right)
                {
                    curr->next = root->right;
                    curr = curr->next;
                }

                root = root->next;
            }

            root = temp->next;
        }

        return ans;
    }
};