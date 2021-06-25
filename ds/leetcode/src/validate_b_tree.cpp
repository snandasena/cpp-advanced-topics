//
// Created by sajith on 6/25/21.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


typedef long long ll;

class Solution
{
public:

    bool helper(TreeNode *root, ll mn, ll mx)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val > mn && root->val < mx)
        {
            return helper(root->left, mn, root->val) && helper(root->right, root->val, mx);
        }

        return false;
    }

    bool isValidBST(TreeNode *root)
    {
        ll mn = -2147483649;
        ll mx = 2147483649;
        return helper(root, mn, mx);
    }
};