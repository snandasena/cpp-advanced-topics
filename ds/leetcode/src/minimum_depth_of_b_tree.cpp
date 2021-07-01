//
// Created by sajith on 7/1/21.
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
    int findmin(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = findmin(node->left);
        int r = findmin(node->right);

        if (l == 0)
        {
            return r + 1;
        } else if (r == 0)
        {
            return l + 1;
        }
        return min(l, r) + 1;
    }

    int minDepth(TreeNode *root)
    {
        return findmin(root);
    }
};

int main()
{
    TreeNode
    return 0;
}