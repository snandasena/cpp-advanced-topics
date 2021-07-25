//
// Created by sajith on 3/17/21.
//

#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template<typename T>
class DoublyLinkedList
{
    Node<T> *head = nullptr;

public:
    DoublyLinkedList() = default;

    void InsertAtHead(T item)
    {
        Node<T> *temp = GetNewNode(item);
        if (head == nullptr)
        {
            head = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    void Print()
    {
        Node<T> *node = head;
        while (node != nullptr)
        {
            std::cout << node->data << " ";
            node = node->next;
        }

        std::cout << '\n';
    }

    void PrintReverse()
    {
        Node<T> *node = head;
        while (node->next != nullptr)
        {
            node = node->next;
        }

        while (node != nullptr)
        {
            std::cout << node->data << " ";
            node = node->prev;
        }

        std::cout << '\n';
    }

private:

    Node<T> *GetNewNode(T data)
    {
        Node<T> *node = new Node<T>;
        node->data = data;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }
};


int main()
{
    DoublyLinkedList<int> dl;
    dl.InsertAtHead(1);
    dl.InsertAtHead(2);
    dl.InsertAtHead(3);
    dl.InsertAtHead(4);
    dl.Print();
    dl.PrintReverse();
    return 0;
}