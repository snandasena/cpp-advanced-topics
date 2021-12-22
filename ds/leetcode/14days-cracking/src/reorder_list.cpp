//
// Created by sajith on 12/22/21.
//

#include "base.h"


class Solution
{
public:
    void reorderList1(ListNode *head)
    {
        stack<ListNode *> stck;
        ListNode *curr = head;
        while (curr)
        {
            stck.push(curr);
            curr = curr->next;
        }
        auto n = stck.size();
        if (n <= 2) return;
        curr = head;
        ListNode *next;
        for (size_t i = 0; i < n / 2; ++i)
        {
            next = curr->next;
            curr->next = stck.top();
            stck.pop();
            curr = curr->next;
            curr->next = next;
            curr = curr->next;
        }
        curr->next = nullptr;
    }

    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *curr = slow;
        ListNode *next;
        ListNode *pre = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        ListNode *n1 = head;
        ListNode *n2 = pre;

        while (n2 && n2->next)
        {
            next = n1->next;
            n1->next = n2;
            n1 = next;

            next = n2->next;
            n2->next = n1;
            n2 = next;
        }
    }
};


int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    sol.reorderList(head);

    while (head)
    {
        cout << head->val << '\t';
        head = head->next;
    }

    return 0;
}