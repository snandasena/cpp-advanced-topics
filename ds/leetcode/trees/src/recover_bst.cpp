//
// Created by sajith on 4/19/22.
//

#include "base.h"

class Solution
{
    TreeNode *prev = nullptr;
    TreeNode *fist = nullptr;
    TreeNode *second = nullptr;
public:
    void helper(TreeNode *root)
    {
        if (root == nullptr) return;

        stack<TreeNode *> stck;
        while (root || !stck.empty())
        {
            while (root)
            {
                stck.push(root);
                root = root->left;
            }

            root = stck.top();
            stck.pop();
            if (prev && root->val <= prev->val)
            {
                second = root;
                if (fist == nullptr)
                {
                    fist = prev;
                }
                else
                {
                    break;
                }
            }

            prev = root;
            root = root->right;
        }
    }

    void recoverTree(TreeNode *root)
    {
        helper(root);
        swap(fist->val, second->val);
    }
};