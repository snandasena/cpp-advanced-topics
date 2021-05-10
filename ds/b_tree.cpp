//
// Created by sajith on 5/8/21.
//

#include <iostream>
#include <queue>

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

int FindMax(BNode *root)
{
    BNode *node = root;
    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node->data;
}

int FindHeight(BNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// Depth first traversal

// Data->Left->Right
void PreOrderTraversal(BNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << "\t";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// Left->Right->Data
void PostOrderTraversal(BNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << "\t";
}

// Left->Data->Right
void InOrderTraversal(BNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << "\t";
    InOrderTraversal(root->right);
}


// Bread first traversal
void LevelOrderTraversal(BNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<BNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        BNode *node = Q.front();
        cout << node->data << "\t";
        if (node->left != nullptr)
        {
            Q.push(node->left);
        }

        if (node->right != nullptr)
        {
            Q.push(node->right);
        }

        Q.pop();
    }
}

bool IsSubtreeLesser(BNode *root, int data)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data <= data
        && IsSubtreeLesser(root->left, data)
        && IsSubtreeLesser(root->right, data))
    {
        return true;
    } else
    {
        return false;
    }
}

bool IsSubtreeGreater(BNode *root, int data)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data > data
        && IsSubtreeGreater(root->left, data)
        && IsSubtreeGreater(root->right, data))
    {
        return true;
    } else
    {
        return false;
    }
}

bool IsBinarySearchTree(BNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    if (IsSubtreeLesser(root->left, root->data)
        && IsSubtreeGreater(root->right, root->data)
        && IsBinarySearchTree(root->left)
        && IsBinarySearchTree(root->right))
    {
        return true;
    } else
    {

        return false;
    }
}


bool IsBST(BNode *root, int minval, int maxval)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data < minval && root->data > maxval
        && IsBST(root->left, minval, root->data)
        && IsBST(root->right, root->data, maxval))
    {
        return true;
    } else
    {
        return false;
    }
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

    /*
     *               15
     *             /    \
     *           10      20
     *          /  \    /   \
     *         8    12  19   25
     *
     */

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    cout << boolalpha << Search(root, 8) << endl;
    cout << boolalpha << Search(root, 50) << endl;

    cout << "Min : " << FindMin(root) << endl;
    cout << "Max : " << FindMax(root) << endl;

    cout << "Height: " << FindHeight(root) << endl;

    // 15->10->8->12->20->19->25
    PreOrderTraversal(root);
    cout << endl;

    // 8->12->10->19->25->20->15
    PostOrderTraversal(root);
    cout << endl;

    // 8->10->12->15->19->20->25
    InOrderTraversal(root);
    cout << endl;

    // 15->10->20->8->12->19->25
    LevelOrderTraversal(root);
    cout << endl;

    cout << IsBinarySearchTree(root) << endl;

    cout << IsBST(root, INT32_MIN, INT32_MAX) << endl;

    return 0;
}