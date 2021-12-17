#pragma once

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next{nullptr};

    explicit Node(int d)
    {
        this->data = d;
    }
};

void InsertNode(Node **head, int data)
{
    Node *node = new Node(data);
    node->next = *head;
    *head = node;
}

void InsertToTail(Node *head, int data)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *node = new Node(data);
    temp->next = node;
}



