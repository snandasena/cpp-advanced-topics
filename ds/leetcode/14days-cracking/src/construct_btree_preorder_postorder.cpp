//
// Created by sajith on 11/26/21.
//

#include "base.h"

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        auto *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stck;
        stck.push(root);
        int j = 0;
        for (int i = 1; i < preorder.size(); ++i)
        {
            auto *node = new TreeNode(preorder[i]);
            if (!stck.empty())
            {
                if (!stck.top()->left)
                {
                    stck.top()->left = node;
                }
                else
                {
                    stck.top()->right = node;
                }
            }
            stck.push(node);
            while (!stck.empty() && postorder[j] == stck.top()->val)
            {
                stck.pop();
                ++j;
            }
        }
        return root;
    }
};