//
// Created by sajith on 4/15/22.
//

#include "base.h"

class Solution
{
public:
    TreeNode *trimBST2(TreeNode *root, int low, int high)
    {
        if (root == nullptr) return root;
        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low)return trimBST(root->right, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr) return root;
        while (!(root->val >= low && root->val <= high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }

            if (root == nullptr) return nullptr;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }


};