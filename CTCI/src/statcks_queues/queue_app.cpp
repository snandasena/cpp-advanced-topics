//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

using namespace std;

class Queue
{

    struct Node
    {
        Node *next{nullptr};
        int data;
        explicit Node(int d) : data{d}
    };


    Node *head{nullptr};
    Node *tail{nullptr};
public:

    Queue() = default;

    void Push(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = tail = node;
        }

        
    }


};