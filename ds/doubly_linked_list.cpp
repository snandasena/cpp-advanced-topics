#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head;

Node *getNode(int);

void InsertAtHead(int);

int main()
{

    return 0;
}

Node *getNode(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void InsertAtHead(int x)
{
    Node *newNode = getNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}