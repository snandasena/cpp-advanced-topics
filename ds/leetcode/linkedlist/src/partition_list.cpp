//
// Created by sajith on 2/16/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *before_head = new ListNode(0);
        ListNode *after_head = new ListNode(0);

        ListNode *before = before_head;
        ListNode *after = after_head;

        while (head)
        {
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr;
        before->next = after_head->next;
        return before_head->next;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    vector<int> vals{4, 3, 2, 5, 2};
    InsertElementsToHead(head, vals);
    ListNode *node = sol.partition(head, 3);
    PrintLinkedList(node);
    return 0;
}