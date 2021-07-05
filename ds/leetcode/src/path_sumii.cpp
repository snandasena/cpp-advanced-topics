
//
// Created by sajith on 7/5/21.
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

    vector<vector<int>> ans;
    int target;

    void dfs(TreeNode *root, vector<int> &v, int val)
    {
        if (root == nullptr)
        {
            return;
        }

        val += root->val;
        v.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && val == target)
        {
            ans.push_back(v);
        }

        dfs(root->left, v, val);
        dfs(root->right, v, val);

        v.pop_back();
        val -= root->val;


    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        this->target = targetSum;
        vector<int> v;
        int val = 0;
        dfs(root, v, val);
        return ans;
    }
};