//
// Created by sajith on 6/10/21.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = head;

        if (!temp)
        {
            return head;
        }

        while (temp->next)
        {
            ListNode *t = temp->next;
            temp->next = t->next;
            t->next = temp;

            if (prev == head)
            {
                prev = temp;
                head = t;
            }
            else
            {
                prev->next = t;
                prev = temp;
            }

            temp = temp->next;
            if (!temp)
            {
                break;
            }
        }

        return head;
    }
};