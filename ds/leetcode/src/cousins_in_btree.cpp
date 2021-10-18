//
// Created by sajith on 10/18/21.
//

#include "base.h"

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == nullptr) return false;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto sz = que.size();
            for (int i = sz, j = 0, k = 0; i > 0; i--)
            {
                auto node = que.front();
                que.pop();
                if (node == nullptr) continue;
                if (node->val == x) j = i;
                if (node->val == y) k = i;
                if (j > 0 && k > 0)
                {
                    return (abs(k - j) > 1) || (min(j, k) % 2 == 0);
                }
                que.push(node->left);
                que.push(node->right);
            }
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    Solution solution;
    cout << boolalpha << solution.isCousins(root, 4, 3);
    return 0;
}