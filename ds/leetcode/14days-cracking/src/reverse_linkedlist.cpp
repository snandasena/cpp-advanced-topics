//
// Created by sajith on 10/3/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

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
