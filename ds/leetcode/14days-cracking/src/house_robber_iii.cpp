//
// Created by sajith on 12/5/21.
//

#include "base.h"

class Solution
{
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root) return {0, 0};

        auto[leftwith, leftwithout] = dfs(root->left);
        auto[rightwith,     rightwithout] = dfs(root->right);

        int with = root->val + leftwithout + rightwithout;
        int without = max(leftwith, leftwithout) + max(rightwith, rightwithout);

        return {with, without};
    }

public:
    int rob(TreeNode *root)
    {
        auto[first, second] = dfs(root);
        return max(first, second);
    }
};