//
// Created by sajith on 9/24/21.
//

#include "base.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        while (fast->next != nullptr)
        {
            fast = fast->next;

            if (n-- <= 0)
            {
                slow = slow->next;
            }
        }

        slow->next = slow->next->next;
        return dummy->next;
    }


    ListNode *removeNthFromEnd2(ListNode *head, int n)
    {
        ListNode *temp = new ListNode;
        temp->next = head;
        int length = 0;
        ListNode *first = head;

        while (first != nullptr)
        {
            length++;
            first = first->next;
        }

        length -= n;

        first = temp;
        while (length > 0)
        {
            length--;
            first = first->next;
        }

        first->next = first->next->next;

        return temp->next;
    }
};

int main()
{

    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    root->next = new ListNode(2);
    root->next = new ListNode(3);
    root->next = new ListNode(4);
    root->next = new ListNode(5);

    Solution solution;
    solution.removeNthFromEnd(root, 2);
    return 0;
}