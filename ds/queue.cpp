//
// Created by sajith on 3/19/21.
//

#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *link;
};


template<typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;

public:
    Queue() : front(nullptr), rear(nullptr)
    {

    }

    void Enqueue(T data)
    {
        Node<T> *temp = GetNode(data);
        if (front == nullptr && rear == nullptr)
        {
            front = rear = temp;
            return;
        }

        rear->link = temp;
        rear = temp;
    }

    void Dequeue()
    {
        Node<T> *temp = front;
        if (front == nullptr)
        {
            return;
        }

        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->link;
        }

        delete (temp);
    }

    T Front()
    {
        if (front == nullptr)
        {
            std::cout << "Queue is empty\n";
            return static_cast<int>(0);
        }

        return front->data;
    }


    void Print()
    {
        Node<T> *temp = front;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->link;
        }

        std::cout << "\n";
    }

private:

    Node<T> *GetNode(T data)
    {
        auto *node = new Node<T>;
        node->data = data;
        node->link = nullptr;

        return node;
    }

};


int main()
{

    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Print();
    queue.Dequeue();
    queue.Print();
    std::cout << queue.Front() << "\n";

    return 0;

}