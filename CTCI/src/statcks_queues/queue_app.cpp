//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

using namespace std;

class Queue
{
    struct Node
    {
        shared_ptr<Node> next{nullptr};
        int data;

        explicit Node(int d) : data{d} {}

    };

    shared_ptr<Node> front{nullptr};
    shared_ptr<Node> rear{nullptr};
public:

    Queue() = default;

    void Enqueue(int data)
    {
        auto node = make_shared<Node>(data);
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

    int Peek()
    {
        if (front)
        {
            return front->data;
        }

        return -1;
    }

    bool Empty()
    {
        return front == nullptr;
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

    cout<<que.Peek()<<endl;
    cout<<boolalpha<<que.Empty()<<endl;


    return 0;
}