//
// Created by sajith on 11/4/21.
//

#include "base.h"

class Solution
{
    int sum{0};
public:

    void calSum(TreeNode *node)
    {
        if (!node) return;

        if (node->left && (!node->left->left && !node->left->right))
        {
            sum += node->left->val;
        }
        calSum(node->left);
        calSum(node->right);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        calSum(root);
        return sum;
    }
};

int main()
{
    TreeNode *treeNode = new TreeNode(3);
    treeNode->left = new TreeNode(9);
    treeNode->right = new TreeNode(20);
    treeNode->right->right = new TreeNode(7);
    treeNode->right->left = new TreeNode(15);

    Solution solution;
    cout << solution.sumOfLeftLeaves(treeNode) << endl;
    return 0;
}