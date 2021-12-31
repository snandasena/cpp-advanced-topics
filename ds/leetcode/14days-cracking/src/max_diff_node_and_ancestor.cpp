//
// Created by sajith on 12/31/21.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "base.h"

class Solution
{
    int res{};
    int curr{};

    void dfs(TreeNode *root, int mx, int mn)
    {
        if (root == nullptr) return;
        // curr = max(abs(mx- root->val), abs(mn- root->val));
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        res = max(mx - mn, res);

        dfs(root->left, mx, mn);
        dfs(root->right, mx, mn);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root, root->val, root->val);
        return res;
    }
};