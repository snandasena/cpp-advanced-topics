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
    vector<int> ans{};
public:

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return 0;
        }

        inorder(root);
        return ans[k - 1];
    }
};