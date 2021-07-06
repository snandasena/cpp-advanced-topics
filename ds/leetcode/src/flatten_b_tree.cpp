//
// Created by sajith on 7/6/21.
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *curr = stk.top();
            stk.pop();


            // first right then left
            if (curr->right != nullptr)
            {
                stk.push(curr->right);
            }

            if (curr->left != nullptr)
            {
                stk.push(curr->left);
            }

            if (!stk.empty())
            {
                curr->right = stk.top();
            }

            curr->left = nullptr;
        }

    }
};


