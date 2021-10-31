//
// Created by sajith on 10/27/21.
//

#ifndef ADVANCED_TOPICS_LINKED_LIST_H
#define ADVANCED_TOPICS_LINKED_LIST_H

#include "base.h"

namespace dsa
{
    class Node
    {
    public:

        int data;
        Node *next;

        Node(int data) : data{data} {}
    };


    void InsertLinkedList(int *arr, int n, Node *root)
    {
        // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

        for (int i = 0; i < n; ++i)
        {
            Node *node = new Node(arr[i]); // 10
            node->next = nullptr; // 10-> null
            root->next = node; // null -> 10-> null
            root = node; //  0->10-> null
        }
    }

    void DisplayLinkedList(Node *root)
    {
        Node *curr = root;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void DisplayLinkedListRecursive(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            DisplayLinkedListRecursive(root->next);
        }
    }

    void DisplayLinkedListRecursiveReverse(Node *root)
    {
        if (root != nullptr)
        {
            DisplayLinkedListRecursiveReverse(root->next);
            cout << root->data << " ";
        }
    }

    int CountNodesInLinkedList(Node *root)
    {
        if (root == nullptr) return 0;
        return CountNodesInLinkedList(root->next) + 1;
    }

    int AddValuesInLinkedList(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return AddValuesInLinkedList(root->next) + root->data;
    }

    int FindMaxValueOfLinkedList(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int mx = 0;
        Node *curr = root;
        while (curr != nullptr)
        {
            mx = max(curr->data, mx);
            curr = curr->next;
        }
        return mx;
    }

    int FindMaxValueOfLinkedListRecursive(Node *root)
    {
        if (root == nullptr)
        {
            return INT_MIN;
        }
        int x = FindMaxValueOfLinkedListRecursive(root->next);
        return max(x, root->data);
    }

    Node *LinearSearch(Node *root, int data)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    Node *LinerSearchRecursive(Node *root, int data)
    {
        if (root == nullptr) return nullptr;

        if (root->data == data) return root;
        else return LinerSearchRecursive(root->next, data);
    }

    void InsertNodeHead(Node **root, int data)
    {
        Node *node = new Node(data);
        node->next = *root;
        *root = node;
    }

    void InsertNodeAt(Node *root, int data, int pos)
    {
        Node *node = new Node(data);
        while (--pos)
        {
            if(root)
            {
                root = root->next;
            }
        }

        if (root)
        {
            node->next = root->next;
            root->next = node;
        }

    }
}


#endif //ADVANCED_TOPICS_LINKED_LIST_H
