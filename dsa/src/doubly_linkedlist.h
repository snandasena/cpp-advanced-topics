//
// Created by sajith on 12/28/21.
//

#ifndef ADVANCED_TOPICS_DOUBLY_LINKEDLIST_H
#define ADVANCED_TOPICS_DOUBLY_LINKEDLIST_H

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data{};
    Node *prev{};
    Node *next{};

    Node() {}

    explicit Node(int d)
    {
        this->data = d;
    }
};


Node *GetNode(int x)
{
    auto *nodePtr = new Node(x);
    nodePtr->prev = nullptr;
    nodePtr->next = nullptr;
    return nodePtr;
}


void InsertAtHead(int x, Node **head)
{
    Node *node = GetNode(x);
    if (*head == nullptr)
    {
        *head = node;
        return;
    }

    (*head)->prev = node;
    node->next = *head;
    *head = node;
}

void Print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << '\t';
        head = head->next;
    }
    cout << '\n';
}

void ReversePrint(Node *head)
{
    if (head == nullptr) return;

    while (head->next != nullptr)
    {
        head = head->next;
    }

    while (head != nullptr)
    {
        cout << head->data << '\t';
        head = head->prev;
    }
    cout << '\t';

}


#endif //ADVANCED_TOPICS_DOUBLY_LINKEDLIST_H
