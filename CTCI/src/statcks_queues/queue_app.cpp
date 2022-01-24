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

        explicit Node(int d) : data{d} {}
    };


    Node *front{nullptr};
    Node *rear{nullptr};
public:

    Queue() = default;

    void Enqueue(int data)
    {
        Node *node = new Node(data);
        if (rear == nullptr)
        {
            front = rear = node;
            return;
        }

        rear->next = node;
        rear = node;
    }

    void Dequeue()
    {
        if (front)
        {
            front = front->next;
        }
        if (!front)
        {
            rear = nullptr;
        }
    }

};

int main()
{
    Queue que;
    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    que.Enqueue(4);
    que.Enqueue(5);
    que.Enqueue(6);
    que.Enqueue(7);
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();


    return 0;
}