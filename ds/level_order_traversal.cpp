#include<iostream>
#include <queue>


using namespace std;


struct Node
{
    char data;
    Node *left;
    Node *right;
};


void LevelOrder(Node *root)
{
    if (root == nullptr) return;

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);

        Q.pop(); // remove to front of the queue
    }
}


Node *getNewNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}


Node *insert(Node *root, char data)
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

int main()
{

    Node *root = nullptr;
    root = insert(root, 'F');
    root = insert(root, 'D');
    root = insert(root, 'J');
    root = insert(root, 'B');
    root = insert(root, 'E');
    root = insert(root, 'G');
    root = insert(root, 'K');
    root = insert(root, 'A');
    root = insert(root, 'C');
    root = insert(root, 'I');
    root = insert(root, 'H');

    LevelOrder(root);
    return 0;
}