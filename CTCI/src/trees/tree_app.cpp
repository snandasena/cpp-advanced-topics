//
// Created by sajith on 1/14/22.
//

#include <bits/stdc++.h>
#include <memory>

using namespace std;

class Node
{
    int data;
    shared_ptr<Node> left{};
    shared_ptr<Node> right{};

    friend class Tree;

public:
    explicit Node(int d) : data{d} {}
};

class Tree
{
    shared_ptr<Node> root{};

public:
    Tree() = default;

    void InsertLevelOrder(int data)
    {
        if (this->root == nullptr)
        {
            root = make_unique<Node>(data);
            return;
        }

        queue<shared_ptr<Node>> que;
        que.push(root);
        while (!que.empty())
        {
            auto node = que.front();
            que.pop();

            if (node->left == nullptr)
            {
                node->left = make_shared<Node>(data);
                return;
            }
            else
            {
                que.push(node->left);
            }

            if (node->right == nullptr)
            {
                node->right = make_shared<Node>(data);
                return;
            }
            else
            {
                que.push(node->right);
            }
        }
    }

    void PrintLevelOrder()
    {
        queue<pair<Node *, int>> que;
        que.push({this->root, 0});
        while (!que.empty())
        {
            auto[node, level] = que.front();
            que.pop();
            if (node != nullptr)
            {
                cout << "(" << node->data << "," << level << ")" << "\n";
                que.push({node->left, level + 1});
                que.push({node->right, level + 1});
            }
        }

        cout << '\n';
    }

    void DeleteNode(int key)
    {
        if (root == nullptr) return;

        if (root->data == key)
        {
            root = nullptr;
            return;
        }

        if (root->left && root->left->data == key)
        {
            root->left = nullptr;
            return;
        }

        if (root->right && root->right->data == key)
        {
            root->right = nullptr;
            return;
        }

        Node *key_node = nullptr;
        Node *curr;

        queue<Node *> que;
        que.push(root);

        while (!que.empty())
        {
            curr = que.front();
            que.pop();

            if (curr->data == key)
            {
                key_node = curr;
            }

            if (curr->left)
            {
                que.push(curr->left);
            }

            if (curr->right)
            {
                que.push(curr->right);
            }
        }

        if (key_node)
        {

        }

    }
};


int main()
{
    Tree *tree = new Tree();
    tree->InsertLevelOrder(10);
    tree->InsertLevelOrder(20);
    tree->InsertLevelOrder(30);
    tree->InsertLevelOrder(40);
    tree->InsertLevelOrder(50);
    tree->InsertLevelOrder(60);
    tree->InsertLevelOrder(70);
    tree->InsertLevelOrder(80);
    tree->InsertLevelOrder(90);
    tree->InsertLevelOrder(100);
    tree->PrintLevelOrder();
    return 0;
}
