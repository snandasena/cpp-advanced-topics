//
// Created by sajith on 7/2/22.
//


#include "base.h"

class Solution
{
    int search(TreeNode *node, int X)
    {
        if (!node) return 0;

        int count = 0;
        if (node->val >= X)
        {
            ++count;
            X = node->val;
        }

        count += search(node->left, X);
        count += search(node->right, X);
        return count;
    }
public:
    int goodNodes(TreeNode *root)
    {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        int good_nodes = 1;
        good_nodes += search(root->left, root->val);
        good_nodes += search(root->right, root->val);
        return good_nodes;
    }
};
int main()
{
    char  a = 'a';
    char x = a-32;

    cout<<x<<endl;
    return 0;
}