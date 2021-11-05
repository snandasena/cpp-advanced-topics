//
// Created by sajith on 11/5/21.
//

#include "queue.h"

int main()
{
//    Queue queue(5);
//    queue.enqueue(1);
//    queue.enqueue(2);
//    queue.enqueue(3);
//    queue.enqueue(4);
//    queue.enqueue(5);
//    queue.enqueue(6);
//    queue.display_queue();
//
//    cout << queue.dequeue() << endl;
//    cout << queue.dequeue() << endl;
//    cout << queue.dequeue() << endl;

//    queue.display_queue();


    int arr[5];// = new int[5];
    for (int i = 0; i < 10; ++i)
    {
        *(arr + i) = i * 10;
    }

    for (int i = 0; i < 10; ++i)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}