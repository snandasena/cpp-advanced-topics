//
// Created by sajith on 10/11/21.
//

#include "base.h"

class Solution
{
    int diameter = 0;

    int dfs(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return diameter;
    }
};