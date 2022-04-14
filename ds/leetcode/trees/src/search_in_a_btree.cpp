//
// Created by sajith on 4/14/22.
//

#include "base.h"


class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        return searchBST(root->val > val ? root->left : root->right, val);
    }
};