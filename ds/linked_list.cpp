#include <bits/stdc++.h>

using namespace std;
#define el '\n'
struct Node
{
    int data;
    Node *next;
};

void buildBasicLinkedList()
{
    Node *node = nullptr;

    // first node
    Node *temp = new Node;
    temp->data = 12;
    temp->next = nullptr;
    node = temp;

    // second node
    temp = new Node;
    temp->data = 20;
    temp->next = nullptr;

    node->next = temp;

    temp = new Node;
    temp->data = 30;
    temp->next = nullptr;

    node->next->next = temp;

    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }

    cout << el;
}


void InsertIntoBegin(int, Node **);

void PrintLinkedList(Node *);

int main()
{
    buildBasicLinkedList();

    // insert into linked list
    Node *head = nullptr;
    for (int i = 1; i <= 10; ++i)
    {
        InsertIntoBegin(i, &head);
    }
    PrintLinkedList(head);

    return 0;
}


void InsertIntoBegin(int x, Node **head)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void PrintLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << el;
}