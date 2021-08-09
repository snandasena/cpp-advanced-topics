//
// Created by sajith on 8/9/21.
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
        string str;
        encode(root, str);
        return str;
    }

    void encode(TreeNode *n, string &str)
    {
        if (n == nullptr)
        {
            str += " #";
            return;
        }

        str += " " + to_string(n->val);
        encode(n->left, str);
        encode(n->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        return decode(ss);
    }

    TreeNode *decode(stringstream &ss)
    {
        if (ss.eof())
        {
            return nullptr;
        }

        string curr;
        ss >> curr;

        if (curr == "#")
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(curr));
        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }
};
