//
// Created by sajith on 6/29/21.
//


#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<TreeNode *> que;
        que.push(root);
        int level = 0;

        while (!que.empty())
        {
            level++;
            size_t n = que.size();
            for (size_t i = 0; i < n; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

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
        return level;
    }
};