//
// Created by sajith on 11/22/21.
//

#include "base.h"

class Solution
{
    TreeNode *rightMost(TreeNode *node)
    {
        while (node && node->right) node = node->right;
        return node;
    }

    TreeNode *leftMost(TreeNode *node)
    {
        while (node && node->left) node = node->left;
        return node;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root) return nullptr;

        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
//                TreeNode *temp = leftMost(root->right);
//                root->val = temp->val;
//                root->right = deleteNode(root->right, temp->val);

                TreeNode *temp = rightMost(root->left);
                temp->right = root->right;
                return root->left;
            }
        }
        return root;
    }
};