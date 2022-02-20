//
// Created by sajith on 2/20/22.
//
#include "base.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *sentinel = new ListNode(0, head);
        ListNode *predecessor = sentinel;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                    head = head->next;

                predecessor->next = head->next;
            }
            else
            {
                predecessor = predecessor->next;
            }
            head = head->next;
        }
        sentinel = sentinel->next;
        return sentinel;
    }
};


int main()
{
    ListNode *head = new ListNode(1);
    vector<int> v{2, 3, 3, 4, 4, 5};
    InsertElementsToHead(head, v);
//    PrintLinkedList(head);

    Solution solution;
    solution.deleteDuplicates(head);
    return 0;
}