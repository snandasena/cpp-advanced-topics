//
// Created by sajith on 10/17/21.
//

#include "base.h"

class Solution
{
    int pathSumRoot(TreeNode *root, int sum)
    {
        if (root == nullptr) return 0;
        int res = 0;
        if (root->val == sum) ++res;
        res += pathSumRoot(root->left, sum - root->val);
        res += pathSumRoot(root->right, sum - root->val);
        return res;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr) return 0;
        return pathSum(root->left, targetSum) + pathSumRoot(root, targetSum) + pathSum(root->right, targetSum);
    }
};