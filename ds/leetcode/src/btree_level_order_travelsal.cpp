//
// Created by sajith on 8/10/21.
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            vector<int> v;
            size_t n = que.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *temp = que.front();
                que.pop();
                v.push_back(temp->val);

                if (temp->left)
                {
                    que.push(temp->left);
                }

                if (temp->right)
                {
                    que.push(temp->right);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    solution.levelOrder(root);

    return 0;
}