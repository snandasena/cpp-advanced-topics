//
// Created by sajith on 12/15/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next) return head;

        ListNode *pSorted = nullptr;
        while (head != nullptr)
        {
            ListNode *pHead = head;
            ListNode **ppTrail = &pSorted;
            head = head->next;
            while (!(*ppTrail == nullptr || pHead->val < (*ppTrail)->val))
            {
                ppTrail = &(*ppTrail)->next;
            }
            pHead->next = *ppTrail;
            *ppTrail = pHead;
        }

        return pSorted;
    }
};