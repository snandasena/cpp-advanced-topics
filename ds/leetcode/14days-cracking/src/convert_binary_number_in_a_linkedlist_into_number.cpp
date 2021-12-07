//
// Created by sajith on 12/7/21.
//
#include "base.h"

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int num = head->val;
        while(head->next)
        {
            num = (num<<1) | head->next->val;
            head = head->next;
        }

        return num;
    }
};


int main()
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    cout<<solution.getDecimalValue(head);
    return 0;
}