//
// Created by sajith on 7/14/22.
//


#include "base.h"

class Solution
{
    unordered_map<int, int> mp;
    int preorderIndex = 0;

    TreeNode *arrayToTree(const vector<int> &preorder, int left, int right)
    {
        if (left > right) return nullptr;

        int rootVal = preorder[preorderIndex];
        ++preorderIndex;
        auto root =new TreeNode{rootVal};

        root->left = arrayToTree(preorder, left, mp[rootVal] - 1);
        root->right = arrayToTree(preorder, mp[rootVal] + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            mp[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};

void Preorder(TreeNode *root)
{
    if (root == nullptr) return;

    cout << root->val << '\t';
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{

    Solution solution;

    vector<int> pre{3, 9, 20, 15, 7};
    vector<int> in{9, 3, 15, 20, 7};

    auto *root = solution.buildTree(pre, in);
    Preorder(root);
    return 0;
}