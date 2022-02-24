//
// Created by sajith on 2/24/22.
//

#include "base.h"

class Solution
{
    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1)
        {
            curr->next = l1;
        }

        if (l2)
        {
            curr->next = l2;
        }

        return ptr->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) return head;

        ListNode *temp{nullptr};
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeLists(l1, l2);
    }
};