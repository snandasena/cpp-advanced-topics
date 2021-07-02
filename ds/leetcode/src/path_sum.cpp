//
// Created by sajith on 7/2/21.
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        dfs(root, targetSum, 0);
        return ans;
    }


    void dfs(TreeNode *node, int target, int curr)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr && target == node->val + curr)
        {
            ans = true;
            return;
        }

        dfs(node->left, target, curr + node->val);
        dfs(node->right, target, curr + node->val);
    }

private:
    bool ans = false;
};

