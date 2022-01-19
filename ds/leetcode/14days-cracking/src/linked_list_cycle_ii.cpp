//
// Created by sajith on 1/19/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *detectCycle1(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            if (fast && fast->next)
            {
                fast = fast->next->next;
            }
            else
            {
                fast = nullptr;
            }
            if (slow)
            {
                slow = slow->next;
            }
            else
            {
                slow = nullptr;
            }
        } while (slow != fast);

        if (fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return fast;
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }

        if (!fast || !fast->next) return nullptr;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

};