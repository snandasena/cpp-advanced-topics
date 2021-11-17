//
// Created by sajith on 11/17/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{

    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    solution.deleteDuplicates(head);
    return 0;
}