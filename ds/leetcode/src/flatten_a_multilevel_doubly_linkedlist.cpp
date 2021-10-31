//
// Created by sajith on 10/31/21.
//

#include "base.h"

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:

    Node *flattenRec(Node *head)
    {
        Node *curr = head, *tail = head;
        while (curr)
        {
            Node *child = curr->child;
            Node *next = curr->next;

            if (child)
            {
                Node *_tail = flattenRec(child);
                _tail->next = next;

                if (next)
                {
                    next->prev = _tail;
                }

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                curr = tail;
            } else
            {
                curr = next;
            }

            if (curr)
            {
                tail = curr;
            }
        }
        return tail;
    }

    Node *flatten(Node *head)
    {
        if (!head) return head;

        Node *curr = head;
        while (curr)
        {
            if (curr->child)
            {
                Node *child = curr->child;
                while (child->next)
                {
                    child = child->next;
                }
                child->next = curr->next;
                if (curr->next) curr->next->prev = child;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }

        return head;
    }
};