//
// Created by sajith on 7/28/21.
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
    vector<int> result;
public:
    vector<int> rightSideView1(TreeNode *root)
    {
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            size_t sz = que.size();
            for (size_t i = 0; i < sz; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

                if (i == sz - 1)
                {
                    result.push_back(node->val);
                }

                if (node->left)
                {
                    que.push(node->left);
                }

                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }

        return result;
    }


    vector<int> rightSideView(TreeNode *root)
    {
        rightSide(root, 0);
        return result;
    }

    void rightSide(TreeNode *root, size_t level)
    {
        if (root == nullptr)
        {
            return;
        }

        if (level == result.size())
        {
            result.push_back(root->val);
        }

        rightSide(root->right, level + 1);
        rightSide(root->left, level + 1);
    }
};