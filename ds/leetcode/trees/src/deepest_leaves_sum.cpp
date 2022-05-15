//
// Created by sajith on 5/15/22.
//

#include "base.h"

class Solution
{
    int ans{0};
    int height{0};

    void dfs(TreeNode *node, int level)
    {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr)
        {
            if (level > height)
            {
                height = level;
                ans = node->val;
            }
            else if (height == level)
            {
                ans += node->val;
            }
            else
            {
                return;
            }
        }

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
//    int deepestLeavesSum(TreeNode *root)
//    {
//        if (!root) return 0;
//        queue<TreeNode *> que;
//        que.push(root);
//        que.push(nullptr);
//        int ans = 0;
//        TreeNode *curr;
//        while (que.size() > 1)
//        {
//            curr = que.front();
//            que.pop();
//            if (!curr)
//            {
//                que.push(curr);
//                ans = 0;
//                continue;
//            }
//
//            ans += curr->val;
//            if (curr->left)
//            {
//                que.push(curr->left);
//            }
//
//            if (curr->right)
//            {
//                que.push(curr->right);
//            }
//        }
//
//        return ans;
//    }
};