//
// Created by sajith on 2/16/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *next = head;
        ListNode *prev = head;
        if (!next) return head;
        ListNode *temp;
        while (next->next)
        {
            temp = next->next;
            next->next = temp->next;
            temp->next = next;

            if (prev == head)
            {
                prev = next;
                head = temp;
            }
            else
            {
                prev->next = temp;
                prev = next;
            }

            next = next->next;
            if (!next)
            {
                break;
            }
        }
        return head;
    }
};