//
// Created by sajith on 10/1/21.
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
            while (sz > 0)
            {
                auto node = que.front();
                que.pop();
                if (sz > 1)
                {
                    node->next = que.front();
                }

                if (node->left != nullptr)
                {
                    que.push(node->left);
                }

                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
                sz--;
            }
        }
        return root;
    }
};
