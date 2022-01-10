//
// Created by sajith on 1/10/22.
//
#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data;
    Node *next{nullptr};
public:
    Node() = default;

    explicit Node(int d) : data{d} {}

    friend class LinkedList;
};

class LinkedList
{
    Node *head{nullptr};

public:
    LinkedList() = default;

    explicit LinkedList(Node *h) : head{h} {};

    void InsertToHead(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void InsertToTail(int data)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *node = new Node(data);
        temp->next = node;
    }

    void PrintAll()
    {
        Node *node = head;
        while (node)
        {
            cout << node->data << '\t';
            node = node->next;
        }
        cout << '\n';
    }

    void DeleteNode(int key)
    {
        Node *node = head;
        Node *prev;
        while (node->next != nullptr)
        {
            prev = node;
            if (node->next->data == key)
            {
                Node *temp = node->next;
                prev->next = node->next->next;
                delete temp;
            }
            node = node->next;
        }
    }

    void DeleteDuplicatesNodes()
    {
        set<int> cache;
        Node *node = head;
        Node *prev;
        while (node != nullptr)
        {
            if (cache.count(node->data) > 0)
            {
                Node *temp = node;
                assert(prev != nullptr);
                prev->next = node->next;
                node = node->next;
                delete temp;
            }else
            {
                cache.insert(node->data);
                prev = node;
                node = node->next;
            }
        }
    }

};


int main()
{
    LinkedList ll;
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(20);
    ll.InsertToTail(200);
    ll.InsertToTail(300);
    ll.InsertToTail(400);
    ll.InsertToTail(500);

    ll.PrintAll();

    ll.DeleteNode(200);

    ll.PrintAll();
    ll.DeleteDuplicatesNodes();
    ll.PrintAll();

    return 0;
}