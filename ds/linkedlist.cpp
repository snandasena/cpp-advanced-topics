//
// Created by sajith on 3/17/21.
//

#include <iostream>

using namespace std;

struct Node
{

    int data;
    Node *next; // link
};

Node *Insert(Node *head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node *node = head;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        node->next = temp;
    }
    return head;
}

void Delete(Node *head, int item)
{
    Node *node = head;
    Node *prev = nullptr;
    while (node->next != nullptr)
    {
        prev = node;
        node = node->next;
        if (node->data == item)
        {
            break;
        }
    }

    if (prev != nullptr)
    {
        prev->next = node->next;
        delete (node);
    }
}

Node *Reverse(Node *head)
{
    Node *curr, *prev, *next;
    curr = head;
    prev = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main()
{
    Node *head;
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);
    head = Insert(head, 6);
    head = Insert(head, 7);
    head = Insert(head, 8);
    head = Insert(head, 9);
    head = Insert(head, 10);

    Delete(head, 5);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    head = Reverse(head);
    temp = head;
    cout << "\n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }


    return 0;
};
