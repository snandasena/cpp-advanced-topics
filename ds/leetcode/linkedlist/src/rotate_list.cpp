//
// Created by sajith on 3/11/22.
//

#include "base.h"


class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next) return head;
        int cnt = 1;
        ListNode *temp;
        int val;
        while (k)
        {
            temp = head;
            val = temp->val;

            while (temp->next)
            {
                swap(val, temp->next->val);
                temp = temp->next;
                if (cnt != -1) ++cnt;
            }
            head->val = val;
            --k;
            if (k > cnt)
            {
                k %= cnt;
            }
        }
        return head;
    }
};