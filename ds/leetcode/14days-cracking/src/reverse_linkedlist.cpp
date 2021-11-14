//
// Created by sajith on 10/3/21.
//

#include "base.h"

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};
