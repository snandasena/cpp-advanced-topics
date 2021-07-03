#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


struct BNode
{
    int data;
    BNode *link;
};

struct CharNode
{
    char data;
    CharNode *link;
};

BNode *CreateBNode(int data)
{
    BNode *node = new BNode();
    node->data = data;
    node->link = nullptr;

    return node;
}

void InsertAtTail(BNode **head, int data)
{
    BNode *newNode = CreateBNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
    } else
    {
        BNode *temp = *head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void InsertAtHead(BNode **head, int data)
{
    BNode *newNode = CreateBNode(data);
    newNode->link = *head;
    *head = newNode;
}


void InsertAtHead(CharNode **head, char c)
{
    CharNode *node = new CharNode();
    node->data = c;
    node->link = *head;
    *head = node;
}

int main()
{
    BNode *head = nullptr;
    InsertAtTail(&head, 1);
    InsertAtTail(&head, 2);
    InsertAtTail(&head, 3);
    InsertAtTail(&head, 4);

    while (head->link != nullptr)
    {
        cout << head->data << endl;
        head = head->link;
    }
    cout << head->data << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    BNode *head2 = nullptr;
    InsertAtHead(&head2, 1);
    InsertAtHead(&head2, 2);
    InsertAtHead(&head2, 3);
    InsertAtHead(&head2, 4);

    while (head2->link != nullptr)
    {
        cout << head2->data << endl;
        head2 = head2->link;
    }
    cout << head2->data;

    string text = "hello";
    CharNode *charNode = nullptr;
    for (char c: text)
    {
        InsertAtHead(&charNode, c);
    }

    cout << "\n" << INT_MAX << "\n" << INT_MIN << "\n";


    cout << "\x1b[42m Hello World\n";

    return 0;

}