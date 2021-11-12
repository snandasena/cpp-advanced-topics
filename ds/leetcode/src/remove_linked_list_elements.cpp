//
// Created by sajith on 11/12/21.
//
#include "base.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->next && head->next->val == val) head = head->next;

        ListNode *curr = head;
        while (curr)
        {
            if (curr->next && curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            curr = cu
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode;

    vector<int> v = {1, 2, 6, 3, 4, 5, 6};
    for (int i = 0; i < v.size(); ++i)
    {
        ListNode *node = new ListNode(v[i]);
        node->next = nullptr;
        head->next = node;
        head = node;
    }

    Solution solution;
    ListNode *res = solution.removeElements(head, 6);
    return 0;
}