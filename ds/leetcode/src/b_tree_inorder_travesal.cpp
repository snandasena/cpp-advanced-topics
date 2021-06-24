//
// Created by sajith on 6/24/21.
//

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

    // 1, null ,2, 3
    /*      1
     *       \
     *        2
     *       /
     *      3
     *
     */
    // 1, 3, 2
    void helper(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        helper(root->left, res);
        res.emplace_back(root->val);
        helper(root->right, res);

    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);

    root->right->left = new TreeNode(3);

    Solution solution;

    vector<int> res = solution.inorderTraversal(root);
    for (int i: res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

