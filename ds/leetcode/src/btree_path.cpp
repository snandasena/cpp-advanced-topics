//
// Created by sajith on 8/5/21.
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

    vector<string> result;
public:

    void path(TreeNode *root, string ans)
    {
        ans += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(ans);
        }

        if (root->left != nullptr)
        {
            path(root->left, ans + "->");
        }

        if (root->right != nullptr)
        {
            path(root->right, ans + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        string ans;
        if (root == nullptr)
        {
            return result;
        }

        path(root, ans);
        return result;
    }

    vector<string> binaryTreePaths2(TreeNode *root)
    {
        if (root == nullptr)
        {
            return result;
        }
        queue<pair<TreeNode *, string>> que;
        que.push({root, to_string(root->val)});

        while (!que.empty())
        {
            auto p = que.front();
            que.pop();

            if (p.first->left == nullptr && p.first->right == nullptr)
            {
                result.push_back(p.second);
            }

            if (p.first->left != nullptr)
            {
                que.push({p.first->left, p.second + "->" + to_string(p.first->left->val)});
            }

            if (p.first->right != nullptr)
            {
                que.push({p.first->right, p.second + "->" + to_string(p.first->right->val)});
            }
        }
        return result;
    }
};