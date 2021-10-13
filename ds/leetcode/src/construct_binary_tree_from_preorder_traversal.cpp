//
// Created by sajith on 10/13/21.
//

#include "base.h"

class Solution
{
public:
    void preorderInsert(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
        }

        if (root->val > val)
        {
            if (root->left == nullptr)
            {
                root->left = new TreeNode(val);
            } else
            {
                preorderInsert(root->left, val);
            }

        } else
        {
            if (root->right == nullptr)
            {
                root->right = new TreeNode(val);
            } else
            {
                preorderInsert(root->right, val);
            }
        }
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i)
        {
            preorderInsert(root, preorder[i]);
        }
        return root;
    }
};