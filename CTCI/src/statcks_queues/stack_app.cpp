//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

using namespace std;

class Stack
{
    struct Node
    {
        shared_ptr<Node> next{nullptr};
        int data;

        explicit Node(int d) : data{d} {}
    };


    shared_ptr<Node> head{nullptr};
public:

    Stack() = default;

    ~Stack()
    {
        if (head)
        {
            head = nullptr;
        }
    }

    void Push(int data)
    {
        auto node =  make_shared<Node>(data);
        node->next = this->head;
        this->head = node;
    }

    int Top() const
    {
        if (this->head) return head->data;
        return -1;
    }

    void Pop()
    {
        auto node = head;
        head = head->next;
    }

};

