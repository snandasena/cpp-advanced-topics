//
// Created by sajith on 4/18/22.
//

#include "base.h"

class Solution
{
    int ans = 0;
    int cnt = 0;
    void inorder(TreeNode *node, int k)
    {
        if (node == nullptr) return;
        inorder(node->left, k);
        ++cnt;
        if (k == cnt)
        {
            ans = node->val;
            return;
        }
        inorder(node->right, k);

    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};