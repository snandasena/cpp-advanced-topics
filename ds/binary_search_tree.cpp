#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = getNewNode(data);
    }

    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }

    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node *root, int data)
{
    if (root == nullptr)return false;
    else if (root->data == data) return true;
    else if (root->data >= data) return search(root->left, data);
    else return search(root->right, data);
}

int getMin(Node *root)
{
    Node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr->data;
}

int getMax(Node *root)
{
    Node *curr = root;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }

    return curr->data;
}

int getMinRecursive(Node *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }

    getMinRecursive(root->left);
}

int getMaxRecursive(Node *root)
{
    if (root->right == nullptr)
    {
        return root->data;
    }

    return getMaxRecursive(root->right);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    string out = search(root, 10) ? "Found\n" : "Not found\n";
    cout << out;

    cout << getMin(root) << "\n";
    cout << getMinRecursive(root) << "\n";
    cout << getMax(root) << "\n";
    cout << getMaxRecursive(root) << "\n";
    return 0;
}
