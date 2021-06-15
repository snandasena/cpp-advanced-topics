//
// Created by sajith on 6/15/21.
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
class Solution
{
public:

    void append(ListNode **head, int val)
    {
        ListNode *temp = new ListNode;
        temp->val = val;
        temp->next = *head;
        *head = temp;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        vector<int> nodes;
        for (auto l: lists)
        {
            while (l)
            {
                nodes.emplace_back(l->val);
                l = l->next;
            }
        }

        sort(nodes.begin(), nodes.end(), greater<>());
        ListNode *head;

        for (auto i: nodes)
        {
            append(&head, i);
        }

        return head;
    }
};


int main()
{
    vector<ListNode *> lists;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    lists.emplace_back(head1);


    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    lists.emplace_back(head2);

    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);

    Solution solution;
    solution.mergeKLists(lists);

    return 0;
}