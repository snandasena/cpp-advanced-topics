//
// Created by sajith on 12/2/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *hOdd = head;
        ListNode *hEven = head->next;
        ListNode *even = hEven;
        ListNode *odd = head;

        while (even)
        {
            if (even->next)
            {
                odd->next = even->next;
            }
            else
            {
                odd->next = hEven;
                return hOdd;
            }

            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = hEven;
        return head;
    }
};