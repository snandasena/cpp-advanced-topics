//
// Created by sajith on 12/14/21.
//

#include "base.h"


class Solution
{
    int sum = 0;

    void help(TreeNode *root, int l, int r)
    {
        if (!root) return;

        if (root->val <= r && root->val >= l)
        {
            sum += root->val;
        }

        help(root->left, l, r);
        help(root->right, l, r);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        help(root, low, high);
        return sum;
    }
};