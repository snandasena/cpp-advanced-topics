//
// Created by sajith on 8/3/21.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        } else
        {
            return root;
        }
    }

    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (p->val > temp->val && q->val > temp->val)
            {
                temp = temp->right;
            } else if (p->val < temp->val && q->val < temp->val)
            {
                temp = temp->left;
            } else
            {
                return temp;
            }
        }

        return nullptr;
    }
};