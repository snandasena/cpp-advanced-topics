//
// Created by sajith on 9/3/21.
//

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }

        int len = 1;
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            len++;
        }

        for (int i = 0; i < k % len; ++i)
        {
            ListNode *curr = head;
            ListNode *next = head->next;

            while (next->next != nullptr)
            {
                curr = curr->next;
                next = next->next;
            }

            next->next = head;
            head = next;
            curr->next = nullptr;
        }

        return head;
    }
};