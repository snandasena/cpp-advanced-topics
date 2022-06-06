//
// Created by sajith on 6/6/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headB || !headA) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b)
        {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};