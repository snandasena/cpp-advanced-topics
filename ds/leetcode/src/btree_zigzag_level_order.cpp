
//
// Created by sajith on 8/11/21.
//


#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
        {
            return ans;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            size_t sz = que.size();
            vector<int> v;
            for (size_t i = 0; i < sz; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

                v.push_back(node->val);
                if (node->left != nullptr)
                {
                    que.push(node->left);
                }

                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
            }

            if (ans.size() % 2 == 0)
            {
                ans.push_back(v);
            } else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};