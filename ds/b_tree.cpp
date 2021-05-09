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

bool Search(BNode *root, int data)
{
    if (root == nullptr)
    {
        return false;
    } else if (root->data == data)
    {
        return true;
    } else if (data < root->data)
    {
        return Search(root->left, data);
    } else
    {
        return Search(root->right, data);
    }
}

int FindMin(BNode *root)
{
    BNode *node = root;

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node->data;

}

int main()
{
    BNode *root = nullptr;
    InsertBNode(&root, 15);
    InsertBNode(&root, 10);
    InsertBNode(&root, 20);
    InsertBNode(&root, 25);
    InsertBNode(&root, 8);
    InsertBNode(&root, 12);
    InsertBNode(&root, 19);

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    cout << boolalpha << Search(root, 8) << endl;
    cout << boolalpha << Search(root, 50) << endl;

    cout << "Min : " << FindMin(root) << endl;

    return 0;
}