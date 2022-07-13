
//
// Created by sajith on 7/13/22.
//


#include "base.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto level = que.size();
            vector<int> v;
            for (auto i = 1; i <= level; ++i)
            {
                auto *curr = que.front();
                que.pop();
                if (curr != nullptr)
                {
                    v.push_back(curr->val);

                    if (curr->left != nullptr)
                    {
                        que.push(curr->left);
                    }

                    if (curr->right != nullptr)
                    {
                        que.push(curr->right);
                    }
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};