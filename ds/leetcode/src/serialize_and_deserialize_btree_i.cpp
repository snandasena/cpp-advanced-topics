//
// Created by sajith on 8/8/21.
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


class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "null,";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> que;
        string str;

        for (const auto &c: data)
        {
            if (c == ',')
            {
                que.push(str);
                str = "";
                continue;
            }
            str += c;
        }
        return makeTree(que);
    }

    TreeNode *makeTree(queue<string> &que)
    {
        string str = que.front();
        que.pop();

        if (str == "null")
        {
            return nullptr;
        }

        auto *root = new TreeNode(stoi(str));
        root->left = makeTree(que);
        root->right = makeTree(que);

        return root;
    }
};

