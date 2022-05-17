//
// Created by sajith on 5/17/22.
//

#include "base.h"

class Solution
{
    TreeNode *target_node;
    TreeNode *ans;

    void inorder(TreeNode *original, TreeNode *cloned)
    {
        if (original != nullptr)
        {
            inorder(original->left, cloned->left);
            if (original == target_node) ans = cloned;
            inorder(original->right, cloned->right);
        }
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        target_node = target;
        inorder(original, cloned);
        return ans;
    }
};