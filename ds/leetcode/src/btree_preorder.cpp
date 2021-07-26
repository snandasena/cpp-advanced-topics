//
// Created by sajith on 7/26/21.
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        preorder(root);
        return vals;
    }

    void preorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        vals.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> vals;
};

int main()
{
    return 0;
}