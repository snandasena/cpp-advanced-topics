//
// Created by sajith on 7/11/22.
//


#include "base.h"


class Solution
{
    vector<int> ans;
    void helper(TreeNode *node, int level)
    {
        if (node == nullptr) return;

        if (level == ans.size())
        {
            ans.push_back(node->val);
        }

        helper(node->right, level + 1);
        helper(node->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode *root)
    {
        helper(root, 0);
        return ans;
    }
};