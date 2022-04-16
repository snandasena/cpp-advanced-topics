//
// Created by sajith on 4/16/22.
//

#include "base.h"

class Solution
{
    int sum = 0;
public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root != nullptr)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};