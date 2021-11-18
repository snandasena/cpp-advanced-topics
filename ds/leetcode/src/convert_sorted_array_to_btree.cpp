//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
    TreeNode *constructTree(int start, int end, vector<int> &nums)
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = constructTree(start, mid - 1, nums);
        node->right = constructTree(mid + 1, end, nums);
        return node;
    }

public:


    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return constructTree(0, nums.size() - 1, nums);
    }
};