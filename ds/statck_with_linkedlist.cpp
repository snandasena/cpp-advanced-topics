//
// Created by sajith on 3/17/21.
//

#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node *link;
};


template<typename T>
class Stack
{

    Node<T> *top = nullptr;

public:
    Stack() = default;

    void Push(T item)
    {
        Node<T> *element = new Node<T>;
        element->data = item;

        if (top == nullptr)
        {
            top = element;
        }
        else
        {
            element->link = top;
            top = element;
        }
    }

    void Pop()
    {
        Node<T> *temp = top;
        top = temp->link;
        delete (temp);
    }


    T Top()
    {
        return top->data;
    }

};


int main()
{
    Stack<int> iStack;
    iStack.Push(1);
    iStack.Push(2);
    iStack.Push(3);
    iStack.Push(4);
    cout << iStack.Top()<<'\n';
    iStack.Pop();
    cout << iStack.Top()<<'\n';

    return 0;
}