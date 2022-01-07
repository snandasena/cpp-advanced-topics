//
// Created by sajith on 1/7/22.
//

#include "base.h"

class Solution
{
    ListNode *node;
    int n = 0;
public:
    Solution(ListNode *head) : node{head}
    {
        ListNode *temp = head;
        while (temp)
        {
            n += 1;
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int rd = random();
        rd %= n;
        int i = 0;
        ListNode *temp = node;
        while (temp)
        {
            if (rd == i)
            {
                return temp->val;
            }
            temp = temp->next;
            ++i;
        }

        return node->val;
    }
};