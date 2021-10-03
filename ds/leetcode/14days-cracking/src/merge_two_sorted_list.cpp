//
// Created by sajith on 10/3/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *head = l1;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        } else
        {
            l1 = l1->next;
        }

        ListNode *curr = head; // head of the list
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l2 = l2->next;
            } else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 == nullptr)
        {
            curr->next = l2;
        } else
        {
            curr->next = l1;
        }
        return head;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *greater = l2->val > l1->val ? l2 : l1;
        ListNode *smaller = l2->val > l1->val ? l1 : l2;
        smaller->next = mergeTwoLists(greater, smaller->next);
        return smaller;
    }

};