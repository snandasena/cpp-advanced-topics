//
// Created by sajith on 6/30/21.
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

    int height(TreeNode *node, bool &isBalance)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = height(node->left, isBalance);
        int r = height(node->right, isBalance);

        if (abs(l - r) > 1)
        {
            isBalance = false;
        }

        return max(r, l) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        bool isBalance = true;
        height(root, isBalance);
        return isBalance;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    cout << boolalpha << solution.isBalanced(root) << endl;

    return 0;
}