//
// Created by sajith on 7/9/21.
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
    TreeNode *invertTree1(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);

        root->right = left;
        root->left = right;

        return root;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            size_t sz = que.size();

            while (sz--)
            {
                TreeNode *curr = que.front();
                que.pop();

                if (curr->left != nullptr)
                {
                    que.push(curr->left);
                }

                if (curr->right != nullptr)
                {
                    que.push(curr->right);
                }

                swap(curr->left, curr->right);
            }
        }

        return root;
    }


};

