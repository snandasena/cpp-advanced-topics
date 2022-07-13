//
// Created by sajith on 7/13/22.
//


#include "base.h"


class Solution
{
public:
    vector<vector<int>> levelOrderBottom2(TreeNode *root)
    {
        if (root == nullptr) return {{}};

        queue<TreeNode *> que;
        que.push(root);
        vector<pair<int, vector<int>>> ans;
        int count = 0;
        while (!que.empty())
        {
            auto level = que.size();
            ++count;
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

            ans.emplace_back(count, v);
        }


        sort(ans.begin(), ans.end(), [](const pair<int, vector<int>> &p1, const pair<int, vector<int>> &p2)
        {
            return p1.first > p2.first;
        });

        vector<vector<int>> res;

        for (const auto &item: ans)
        {
            res.push_back(item.second);
        }

        return res;
    }


    vector<vector<int>> levelOrderBottom(TreeNode *root)
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

        reverse(ans.begin(), ans.end());
        return ans;
    }

};