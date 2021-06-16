//
// Created by sajith on 6/16/21.
//

#include <iostream>

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
    int len(ListNode *head)
    {
        ListNode *temp = head;
        int l = 0;
        while (temp != nullptr)
        {
            l++;
            temp = temp->next;
        }

        return l;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == nullptr || len(head) < k)
        {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        int count = 0;
        while (count < k && curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != nullptr)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    head = solution.reverseKGroup(head, 2);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}