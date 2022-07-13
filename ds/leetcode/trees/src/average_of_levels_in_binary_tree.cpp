//
// Created by sajith on 7/13/22.
//


#include "base.h"


class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {

        if (root == nullptr) return {};

        queue<TreeNode *> que;
        que.push(root);

        vector<double> ans;
        while (!que.empty())
        {
            auto size = que.size();
            auto total = size;
            double curr = 0.0;
            for (auto i = 1; i <= size; ++i)
            {
                auto *node = que.front();
                que.pop();
                if (node != nullptr)
                {
                    curr += node->val;

                    if (node->left != nullptr)
                    {
                        que.push(node->left);
                    }

                    if (node->right != nullptr)
                    {
                        que.push(node->right);
                    }
                }
            }

            ans.push_back(curr / total);
        }
        return ans;
    }
};