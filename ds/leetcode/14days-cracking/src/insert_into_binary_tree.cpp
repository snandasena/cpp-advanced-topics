//
// Created by sajith on 1/12/22.
//

#include "base.h"


class Solution
{
    void helper(TreeNode *node, int val)
    {
        if (node == nullptr) return;

        if (node->left == nullptr && node->val > val)
        {
            node->left = new TreeNode(val);
        }
        else if (node->right == nullptr && node->val < val)
        {
            node->right = new TreeNode(val);
        }

        if (node->val < val)
        {
            helper(node->right, val);
        }
        else
        {
            helper(node->left, val);
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr) return new TreeNode(val);
        if(val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};