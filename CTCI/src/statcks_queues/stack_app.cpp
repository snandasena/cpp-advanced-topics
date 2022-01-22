//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

using namespace std;

class Stack
{
    struct Node
    {
        Node *next{nullptr};
        int data;

        explicit Node(int d) : data{d} {}
    };


    Node *head{nullptr};
public:

    Stack() = default;

    ~Stack()
    {
        if (head)
        {
            delete head;
            head = nullptr;
        }
    }

    void Push(int data)
    {
        Node *node = new Node(data);
        node->next = this->head;
        this->head = node;
    }

    int Top()
    {
        if (this->head) return head->data;
        return -1;
    }

    void Pop()
    {
        Node *node = head;
        head = head->next;
        delete node;

    }

};

