//
// Created by sajith on 6/26/21.
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
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

private:
    TreeNode *prev = new TreeNode(INT_MIN);
    TreeNode *first = nullptr, *second;

    void inorder(TreeNode *root)
    {
        if (root->left != nullptr)
        {
            inorder(root->left);
        }

        if (first == nullptr && root->val < prev->val)
        {
            first = prev;
        }

        if (first != nullptr && root->val < prev->val)
        {
            second = root;
        }

        prev = root;
        if (root->right != nullptr)
        {
            inorder(root->right);
        }
    }

};