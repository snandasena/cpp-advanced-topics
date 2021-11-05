//
// Created by sajith on 11/5/21.
//

#ifndef ADVANCED_TOPICS_QUEUE_H
#define ADVANCED_TOPICS_QUEUE_H

#include "base.h"

// [1,2,3,4,5,6,7,8]

class Queue
{
private:
    int size;
    int front{-1};
    int rear{-1};
    int *queue;

public:
    Queue(int sz) : size{sz}
    {
        queue = new int[size];
    }

    ~Queue()
    {
        delete[] queue;
    }

    void enqueue(int element)
    {
        if (rear == size - 1)
        {
            printf("Queue is full\n");
        }
        else
        {
            ++rear;
            *(queue + rear) = element;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            printf("Queue is empty\n");
            return -1;
        }
        else
        {
            ++front;
            return queue[front];
        }
    }

    void display_queue()
    {
        for (int i = front + 1; i <= rear; ++i)
        {
            cout << *(queue + i) << " ";
        }
        cout << endl;
    }
};

#endif //ADVANCED_TOPICS_QUEUE_H
