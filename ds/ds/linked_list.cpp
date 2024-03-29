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

void InsertIntoSpecificPosition(int, int, Node **);

void DeleteDFromSpecificPosition(int, Node **);

void ReverseLinkedList(Node **);

void PrintLinkedList(Node *);

void PrintLinkedListRecursive(Node *);

void PrintLinkedListRecursiveReverseOrder(Node *);

void ReverseLinkedListRecursive(Node **);

Node *Reverse(Node *);

int main()
{
    buildBasicLinkedList();

    // insert into linked list
    Node *head = nullptr;
    for (int i = 1; i <= 10; ++i)
    {
        InsertIntoBegin(i, &head);
    }
    // print the linked list
    PrintLinkedList(head);

    // insert into specific position
    InsertIntoSpecificPosition(3, 3, &head);
    // print the linked list
    PrintLinkedList(head);

    // delete a node from a given position
    DeleteDFromSpecificPosition(3, &head);
    // print the linked list
    PrintLinkedList(head);

    // reverse linked list
    ReverseLinkedList(&head);
    PrintLinkedList(head);
    // print linked list recursive
    cout << "Recursive print\n";
    PrintLinkedListRecursive(head);
    cout << "Recursive print reverse order\n";
    PrintLinkedListRecursiveReverseOrder(head);
    cout << el;

    head = Reverse(head);
    cout << "After reverse\n";
    PrintLinkedListRecursive(head);
    return 0;
}


void InsertIntoBegin(int x, Node **head)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void InsertIntoSpecificPosition(int pos, int data, Node **head)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *tmp = *head;
    for (int i = 0; i < pos - 2; ++i)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;

}

void DeleteDFromSpecificPosition(int pos, Node **head)
{
    Node *node = *head;
    if (pos == 1)
    {
        *head = node->next;
        delete (node);
        return;
    }
    for (int i = 0; i < pos - 2; ++i)
    {
        node = node->next;
    }

    Node *tmp = tmp->next;
    node->next = tmp->next;
    delete (tmp);
}

void ReverseLinkedList(Node **head)
{
    Node *curr = *head;
    Node *prev = nullptr;
    Node *next;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
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

void PrintLinkedListRecursive(Node *head)
{
    if (head == nullptr)
    {
        cout << el;
        return;
    }
    cout << head->data << " ";
    PrintLinkedList(head->next);
}

void PrintLinkedListRecursiveReverseOrder(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    PrintLinkedListRecursiveReverseOrder(head->next);
    cout << head->data << " ";
}

// Global head pointer
//Node *head;
//
//void ReverseLinkedListRecursive(Node *p)
//{
//    if (p->next == nullptr)
//    {
//        head = p;
//        return;
//    }
//    Node *q = p;
//    q->next = p;
//    p->next = nullptr;
//}

Node *Reverse(Node *head)
{
    if (head->next == nullptr)
    {
        return head;
    }

    Node *rest = Reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}