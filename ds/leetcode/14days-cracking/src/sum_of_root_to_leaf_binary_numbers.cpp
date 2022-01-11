//
// Created by sajith on 1/11/22.
//

#include "base.h"

class Solution
{
    int ans = 0;

    int strtoint(string const &str)
    {
        int k = 0;
        int res = 0;
        int x;
        int y;
        for (auto it = str.rbegin(); it != str.rend(); ++it)
        {
            x = (*it - '0');
            y = (1 << k);
            res += (y * x);
            ++k;
        }
        return res;
    }

    void dfs(TreeNode *node, string const &s)
    {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr)
        {
            ans += strtoint(s + to_string(node->val));
        }
        dfs(node->left, s + to_string(node->val));
        dfs(node->right, s + to_string(node->val));
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root, "");
        return ans;
    }
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << sol.sumRootToLeaf(root) << endl;
//
//    string s{"111"};
//    cout << strtoint(s) << endl;

    return 0;
}
