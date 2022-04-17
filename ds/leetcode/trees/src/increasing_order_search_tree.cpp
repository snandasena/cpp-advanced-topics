//
// Created by sajith on 4/17/22.
//

#include "base.h"

class Solution
{
    TreeNode *curr;

    void inorder(TreeNode *node)
    {
        if (node == nullptr) return;
        inorder(node->left);
        node->left = nullptr;
        curr->right = node;
        curr = node;
        inorder(node->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        return ans->right;
    }
};