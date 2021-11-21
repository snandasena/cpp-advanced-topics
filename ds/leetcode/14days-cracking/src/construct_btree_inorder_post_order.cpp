//
// Created by sajith on 11/21/21.
//

#include "base.h"

class Solution
{
    vector<int> pIn;
    vector<int> pPost;

    TreeNode *buildBtree(int l1, int l2, int p1, int p2)
    {
        if (l1 >= l2 || p1 >= p2) return nullptr;
        TreeNode *root = new TreeNode(pPost[p2 - 1]);
        auto it = find(pIn.begin() + l1, pIn.end() + l2, pPost[p2 - 1]);
        auto diff = it - pIn.begin() - l1;

        root->left = buildBtree(l1, l1 + diff, p1, p1 + diff);
        root->right = buildBtree(l1 + diff + 1, l2, p1 + diff, p2 - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        auto n = inorder.size();
        pIn = move(inorder);
        pPost = move(postorder);
        return buildBtree(0, n, 0, n);
    }
};


int main()
{
    vector<int> in{9, 3, 15, 20, 7};
    vector<int> post{9, 15, 7, 20, 3};

    Solution solution;
    auto root = solution.buildTree(in, post);
    return 0;
}