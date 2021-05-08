//
// Created by sajith on 5/8/21.
//

#include <iostream>

using namespace std;

struct BNode
{
    int data;
    BNode *left;
    BNode *right;
};

BNode *CreateBNode(int data)
{
    BNode *node = new BNode();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

void InsertBNode(BNode **root, int data)
{
    if (*root == nullptr)
    {
        *root = CreateBNode(data);

    } else if (data <= (*root)->data)
    {
        InsertBNode(&(*root)->left, data);
    } else
    {
        InsertBNode(&(*root)->right, data);
    }
}

int main()
{
    BNode *root;
    InsertBNode(&root, 15);
    InsertBNode(&root, 10);
    InsertBNode(&root, 20);
    InsertBNode(&root, 25);
    InsertBNode(&root, 8);
    InsertBNode(&root, 12);
    InsertBNode(&root, 19);

    return 0;
}