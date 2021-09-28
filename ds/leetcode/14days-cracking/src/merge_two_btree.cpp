//
// Created by sajith on 9/28/21.
//

#include "base.h"

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr) { return root2; }
        stack<vector<TreeNode *>> stck;
        stck.push({root1, root2});
        while (!stck.empty())
        {
            auto t = stck.top();
            stck.pop();

            if (t[0] == nullptr || t[1] == nullptr)
            {
                continue;
            }
            t[0]->val += t[1]->val;

            if (t[0]->left == nullptr)
            {
                t[0]->left = t[1]->left;
            } else
            {
                stck.push({t[0]->left, t[1]->left});
            }

            if (t[0]->right == nullptr)
            {
                t[0]->right = t[1]->right;
            } else
            {
                stck.push({t[0]->right, t[1]->right});
            }
        }
        return root1;
    }
};