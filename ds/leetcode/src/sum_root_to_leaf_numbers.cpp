//
// Created by sajith on 11/3/21.
//
#include "base.h"


class Solution
{
public:

    int solve(TreeNode *node, int sum)
    {
        if (!node) return 0;
        sum *= 10;
        sum += node->val;
        if (!node->left && !node->right) return sum;
        return solve(node->left, sum) + solve(node->right, sum);
    }

    int sumNumbers(TreeNode *root)
    {
        return solve(root, 0);
    }

};