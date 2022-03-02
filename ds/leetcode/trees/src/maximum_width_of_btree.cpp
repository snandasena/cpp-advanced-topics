//
// Created by sajith on 2/27/22.
//

#include "base.h"

class Solution
{
    vector<int> ans;

    void postOrder(TreeNode *node)
    {
        if (node == nullptr) return;

        postOrder(node->left);
        postOrder(node->right);
        ans.push_back(node->val);
    }

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr) return 0;

        postOrder(root);
        return ans[ans.size() - 1] - ans[0];
    }
};