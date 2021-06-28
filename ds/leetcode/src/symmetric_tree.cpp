//
// Created by sajith on 6/28/21.
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
    bool isSymmetric(TreeNode *root)
    {
//        return isMirror(root, root);

        queue<TreeNode *> qq;
        qq.push(root);
        qq.push(root);

        while (!qq.empty())
        {
            TreeNode *p = qq.front();
            qq.pop();

            TreeNode *q = qq.front();
            qq.pop();

            if (p == nullptr && q == nullptr)
            {
                continue;
            }

            if (p == nullptr || q == nullptr)
            {
                return false;
            }

            if (q->val != p->val)
            {
                return false;
            }

            qq.push(p->left);
            qq.push(q->right);

            qq.push(p->right);
            qq.push(q->left);
        }

        return true;
    }

    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        return (p->val == q->val) && isMirror(q->left, p->right) & isMirror(q->right, p->left);
    }
};