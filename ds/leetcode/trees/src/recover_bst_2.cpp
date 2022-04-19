//
// Created by sajith on 4/19/22.
//
#include "base.h"

class Solution
{
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void inorder(TreeNode *root)
    {
        if (root == nullptr) return;

        inorder(root->left);
        if (first == nullptr && prev != nullptr && root->val < prev->val)
        {
            first = prev;
        }

        if (first != nullptr && prev != nullptr && root->val < prev->val)
        {
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }
};