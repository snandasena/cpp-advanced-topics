//
// Created by sajith on 8/1/21.
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
    int ans{0}, cnt{0};
public:

    void inorder(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, k);
        cnt++;
        if (cnt == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return 0;
        }

        inorder(root, k);
        return ans;
    }

    int kthSmallest2(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return 0;
        }

        stack<TreeNode *> stck;

        while (root != nullptr || !stck.empty())
        {
            while (root != nullptr)
            {
                stck.push(root);
                root = root->left;
            }

            root = stck.top();
            stck.pop();

            if (--k == 0)
            {
                return root->val;
            }

            root = root->right;
        }
        return ans;
    }
};