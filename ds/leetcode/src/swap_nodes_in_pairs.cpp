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

#include <bits/stdc++.h>

using namespace std;

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

void PrintLinkList(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << endl;

}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    PrintLinkList(head);
    Solution solution;

    head = solution.swapPairs(head);
    PrintLinkList(head);
    return 0;
}