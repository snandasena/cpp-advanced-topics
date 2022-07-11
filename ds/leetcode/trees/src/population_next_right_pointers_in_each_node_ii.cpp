//
// Created by sajith on 7/11/22.
//

#include "base.h"

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr) return root;

        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            auto sz = que.size();
            auto *dummy = new Node;
            while (sz--)
            {
                auto *node = que.front();
                que.pop();
                dummy->next = node;
                dummy = dummy->next;
                if (node->left != nullptr)
                {
                    que.push(node->left);
                }

                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};