//
// Created by sajith on 2/27/22.
//

#include "base.h"

class Solution
{
    using LI = long int;
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, LI>> que({{root, 1}});
        size_t sz;
        LI i;
        LI j = 1;
        LI res = 1;
        while (!que.empty())
        {
            sz = que.size();
            i = que.front().second;
            while (sz--)
            {
                auto[curr, pos] = que.front();
                que.pop();
                j = pos;
                pos = pos * 2 - i;
                if (curr->left) que.push({curr->left, pos});
                if (curr->right) que.push({curr->right, pos + 1});
            }
            res = max(res, j - i + 1);
        }
        return static_cast<int>(res);
    }
};