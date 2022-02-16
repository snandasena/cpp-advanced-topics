//
// Created by sajith on 2/16/22.
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

#include "base.h"

class Solution
{
public:
    ListNode *swapNodes1(ListNode *head, int k)
    {
        vector<int> vals;
        ListNode *temp = head;
        while (temp)
        {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        if (vals.size() == 1) return head;
        else if (vals.size() == 2)
        {
            head->val = vals[1];
            head->next->val = vals[0];
            return head;
        }

        temp = head;
        int idx = 0;
        auto N = static_cast<int>(vals.size()) - 1;
        --k;

        if (k > N / 2)
        {
            k = N - k;
        }

        while (temp)
        {
            if (idx == k)
            {
                temp->val = vals[N - idx];
            }

            if (idx == N - k)
            {
                temp->val = vals[k];
                break;
            }

            temp = temp->next;
            ++idx;
        }
        return head;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = nullptr;
        ListNode *second = nullptr;
        ListNode *temp = head;

        while (temp)
        {
            --k;
            if (second)
            {
                second = second->next;
            }
            if (k == 0)
            {
                first = temp;
                second = head;

            }
            temp = temp->next;
        }

        if(first && second)
        {
            swap(first->val, second->val);
        }
        return head;
    }
};

/*
 * [91,56,48,77,91,96,55,53,68]
7

 */



int main()
{
    vector<int> vals{56, 48, 77, 91, 96, 55, 53, 68};
    ListNode *head = new ListNode(91);
    InsertElementsToHead(head, vals);

    PrintLinkedList(head);
    Solution solution;
    ListNode *node = solution.swapNodes(head, 7);
    PrintLinkedList(node);
    return 0;
}